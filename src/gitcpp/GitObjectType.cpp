//
// Created by ekuch on 9/30/15.
//

#include <git2/object.h>
#include "GitObjectType.h"

GitObjectType::GitObjectType(EGitObjectType eObjectType)
    : m_eObjectType(eObjectType)
{}

GitObjectType GitObjectType::FromString(const std::string& sObjectType)
{
    return GitObjectType(static_cast<EGitObjectType>(git_object_string2type(sObjectType.c_str())));
}

std::string GitObjectType::ToString() const
{
    return std::string(git_object_type2string(static_cast<git_otype>(m_eObjectType)));
}
bool GitObjectType::IsLoose() const
{
    return git_object_typeisloose(static_cast<git_otype>(m_eObjectType)) == 1;
}

size_t GitObjectType::Size() const
{
    return git_object__size(static_cast<git_otype>(m_eObjectType));
}
