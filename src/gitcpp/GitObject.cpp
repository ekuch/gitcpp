//
// Created by ekuch on 9/30/15.
//

#include <git2/object.h>
#include "GitObject.h"
#include "util/ErrorUtility.h"
#include "util/HandleUtility.h"

GitObject::GitObject()
    : m_pObject(nullptr)
{

}

GitObject::~GitObject()
{
    if (m_pObject)
    {
        git_object_free(m_pObject);
        m_pObject = nullptr;
    }
}

// Assumes we are the "treeish"
std::shared_ptr<GitObject> GitObject::LookUpByPath(const std::string& sPath, GitObjectType gitObjectType1) const
{
    auto ptrObject = std::make_shared<GitObject>();
    ErrorUtility::ThrowOnError("git_object_lookup_bypath", git_object_lookup_bypath(&ptrObject->m_pObject, m_pObject, sPath.c_str(), static_cast<git_otype>(gitObjectType1.Type())));
    return ptrObject;
}

/*
GitObjectId GitObject::ObjectId() const
{
    return GitObjectId(git_object_id(m_pObject));
}
 */

// TODO: GitObjectPrefix GitObject::ShortObjectId() const;

GitObjectType GitObject::Type() const
{
    return GitObjectType(static_cast<GitObjectType::EGitObjectType>(git_object_type(m_pObject)));
}

std::shared_ptr<Repository> GitObject::RepositoryOwner()
{
    auto ptrRepository = std::make_shared<Repository>();
    HandleUtility::Handle(*ptrRepository) = git_object_owner(m_pObject);
}

std::shared_ptr<GitObject> GitObject::Peel(GitObjectType type)
{
    auto ptrObject = std::make_shared<GitObject>();
    ErrorUtility::ThrowOnError("git_object_peel", git_object_peel(&ptrObject->m_pObject, m_pObject, static_cast<git_otype>(type.Type())));
    return ptrObject;
}

std::shared_ptr<GitObject> GitObject::Duplicate()
{
    auto ptrObject = std::make_shared<GitObject>();
    ErrorUtility::ThrowOnError("git_object_dup", git_object_dup(&ptrObject->m_pObject, m_pObject));
    return ptrObject;
}
