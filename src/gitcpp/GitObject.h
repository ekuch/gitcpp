//
// Created by ekuch on 9/30/15.
//

#ifndef GITCPP_GITOBJECT_H
#define GITCPP_GITOBJECT_H


#include <memory>
#include "Repository.h"
#include "GitObjectId.h"
#include "GitObjectType.h"
#include "GitObjectIdPrefix.h"

struct git_object;
class Repository;

class GitObject {
public:
    virtual ~GitObject();
    static std::shared_ptr<GitObject> MakeShared();

    // TODO: Move these to the Repository object
    // TODO: static std::shared_ptr<GitObject> LookUp(Repository& repository, const GitObjectId& objectId, const GitObjectType& gitObjectType);
    // TODO: static std::shared_ptr<GitObject> LookUpPrefix(Repository& repository1, const GitObjectIdPrefix& objectIdPrefix, GitObjectType gitObjectType1);

    // Assumes we are the "treeish"
    std::shared_ptr<GitObject> LookUpByPath(const std::string& sPath, GitObjectType gitObjectType1) const;

    GitObjectId ObjectId() const;
    //TODO GitObjectPrefix ShortObjectId() const;

    GitObjectType Type() const;

    std::shared_ptr<Repository> RepositoryOwner();

    std::shared_ptr<GitObject> Peel(GitObjectType type);
    std::shared_ptr<GitObject> Duplicate();

//protected:
    GitObject();
private:
    git_object* m_pObject;
};


#endif //GITCPP_GITOBJECT_H
