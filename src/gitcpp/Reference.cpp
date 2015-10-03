//
// Created by ekuch on 9/30/15.
//

#include <git2/refs.h>
#include "Reference.h"
#include "util/ErrorUtility.h"
#include "util/HandleUtility.h"

bool Reference::IsValidName(const std::string& sName)
{
    int nCode = git_reference_is_valid_name(sName.c_str());
    if (nCode == 1) return true;
    if (nCode == 0) return false;
    ErrorUtility::ThrowError("git_reference_is_valid_name", nCode);
}
bool Reference::NormalizeName(std::string& sName)
{
    std::vector<char> vNormalizedBuf;
    vNormalizedBuf.resize(sName.size());
    int nCode = GIT_EBUFS;
    while (nCode == GIT_EBUFS)
    {
        nCode = git_reference_normalize_name(&(vNormalizedBuf[0]), vNormalizedBuf.size(), sName.c_str(), sName.size());
        if (nCode == GIT_EBUFS)
        {
            vNormalizedBuf.resize(vNormalizedBuf.size() + 512);
        }
    }

    if (nCode != 0)
    {
        return false;
    }

    sName = std::string(&(vNormalizedBuf[0]));
    return true;
}

//GitObjectId Reference::Target() const
//{
    //TODO return GitObjectId(new GitObjectIdData(git_reference_target(m_pReference))); // TODO: Error handling. Checkfor null?
//}
//GitObjectId Reference::TargetPeel() const; // direct and hard tag
Reference::EType Reference::Type() const
{
    return static_cast<EType>(git_reference_type(m_pReference));
}
std::string Reference::Name() const
{
    return std::string(git_reference_name(m_pReference));
}
std::shared_ptr<Reference> Reference::Resolve()
{
    auto ptrReference = std::make_shared<Reference>();
    ErrorUtility::ThrowOnError("git_reference_resolve", git_reference_resolve(&ptrReference->m_pReference, m_pReference));
    return ptrReference;
}
std::shared_ptr<Repository> Reference::RepositoryOwner()
{
    auto ptrRepository = std::make_shared<Repository>();
    HandleUtility::Handle(*ptrRepository) = git_reference_owner(m_pReference);
    return ptrRepository;
}

void Reference::Delete()
{
    git_reference_delete(m_pReference);
}

bool Reference::IsBranch() const
{
    ToBool(git_reference_is_branch, m_pReference);
}

bool Reference::IsRemote() const
{
    ToBool(git_reference_is_remote, m_pReference);
}

bool Reference::IsTag() const
{
    ToBool(git_reference_is_tag, m_pReference);
}

bool Reference::IsNote() const
{
    ToBool(git_reference_is_note, m_pReference);
}


std::string Reference::ShortHand()
{
    return std::string(git_reference_shorthand(m_pReference));
}
