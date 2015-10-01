//
// Created by ekuch on 9/30/15.
//

#ifndef GITCPP_GITOBJECT_H
#define GITCPP_GITOBJECT_H


#include <bits/shared_ptr.h>
#include "Repository.h"

class GitObject {
public:
    // TODO: Move these to the Repository object
    static std::shared_ptr<GitObject> LookUp(Repository& repository, const GitObjectId& objectId, const GitObjectType& gitObjectType);
    static std::shared_ptr<GitObject> LookUpPrefix(Repository& repository1, const GitObjectIdPrefix& objectIdPrefix, GitObjectType gitObjectType1);

    // Assumes we are the "treeish"
    std::shared_ptr<GitObject> LookUpByPath(const std::string& sPath, GitObjectType gitObjectType1) const;

    GitObjectId ObjectId() const;
    GitObjectPrefix ShortObjectId() const;

    GitObjectType Type() const;

    std::shared_ptr<Repository> RepositoryOwner();

    std::shared_ptr<GitObject> Peel(GitObjectType type);
    std::shared_ptr<GitObject> Duplicate();
};


#endif //GITCPP_GITOBJECT_H
