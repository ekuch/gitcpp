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

std::shared_ptr<Repository> Repository::Init(const std::string& sPath, const RepositoryInitOptions& options)
{
    auto ptrRepository = std::make_shared<Repository>();
    ErrorUtility::ThrowOnError("", git_repository_init_ext(&ptrRepository->m_pRepository, sPath.c_str(), &(options.get())));
    return ptrRepository;
}
/*
std::shared_ptr<Reference> Head() const
{
    git_repository_head()
}
 */

bool Repository::HeadExists() const
{
    return false;//TODO return Head().get() != nullptr;
}
bool Repository::IsHeadDetatched() const
{
    ToBool(git_repository_head_detached, m_pRepository);
}
bool Repository::IsHeadUnborn() const
{
    ToBool(git_repository_head_unborn, m_pRepository);
}
bool Repository::IsEmpty() const
{
    ToBool(git_repository_is_empty, m_pRepository);
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
    ToBool(git_repository_is_bare, m_pRepository);
}
//std::shared_ptr<Config> Repository::Config() const;

//std::shared_ptr<Config> Repository::ConfigSnapshot() const;
