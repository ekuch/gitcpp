//
// Created by ekuch on 9/30/15.
//

#include "Repository.h"
#include "util/ErrorUtility.h"
#include <git2.h>


Repository::Repository()
        : m_pRepository(nullptr)
{}

Repository::~Repository()
{
    if (m_pRepository)
    {
        git_repository_free(m_pRepository);
        m_pRepository = nullptr;
    }
}

std::shared_ptr<Repository> Repository::Open(const std::string& sPath)
{
    auto ptrRepository = std::make_shared<Repository>();
    ErrorUtility::ThrowOnError("git_repository_open failed", git_repository_open(&ptrRepository->m_pRepository, sPath.c_str()));
    return ptrRepository;
}

static std::shared_ptr<Repository> Repository::Init(const std::string& sPath, const RepositoryInitOptions& options)
{
    auto ptrRepository = std::make_shared<Repository>();
    ErrorUtility::ThrowOnError("", git_repository_init_ext(&ptrRepository->m_pRepository, sPath.c_str(), &(options.get())));
}

std::shared_ptr<Reference> Head() const
{
    git_repository_head()
}

bool Repository::HeadExists() const
{
    return Head().get() != nullptr;
}
bool Repository::IsHeadDetatched() const
{
    int nCode = git_repository_head_detached(m_pRepository);
    if (nCode == 1) return true;
    if (nCode == 0) return false;
    ErrorUtility::ThrowError("git_repository_head_detached", nCode);
}
bool Repository::IsHeadUnborn() const
{
    int nCode = git_repository_head_unborn(m_pRepository);
    if (nCode == 1) return true;
    if (nCode == 0) return false;
    ErrorUtility::ThrowError("git_repository_head_unborn", nCode);
}
bool Repository::IsEmpty() const
{
    int nCode = git_repository_is_empty(m_pRepository);
    if (nCode == 1) return true;
    if (nCode == 0) return false;
    ErrorUtility::ThrowError("git_repository_is_empty", nCode);
}
std::string Repository::Path() const
{
    // TODO: Check for memory leak!
    const char* psPath = git_repository_path(m_pRepository);
    return std::string(psPath);
}
std::string Repository::WorkingDir() const
{
    // TODO: Check for memory leak!
    const char* psPath = git_repository_workdir(m_pRepository);
    return std::string(psPath);
}
void Repository::SetWorkingDir(const std::string& sWorkingDir, bool updateGitLink)
{
    ErrorUtility::ThrowOnError("git_repository_set_workdir", git_repository_set_workdir(m_pRepository, sWorkingDir.c_str(), updateGitLink));
}
bool Repository::IsBare() const
{
    int nCode = git_repository_is_bare(m_pRepository);
    if (nCode == 1) return true;
    if (nCode == 0) return false;
    ErrorUtility::ThrowError("git_repository_is_bare", nCode);
}
std::shared_ptr<Config> Repository::Config() const;

std::shared_ptr<Config> Repository::ConfigSnapshot() const;
