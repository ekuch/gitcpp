//
// Created by ekuch on 9/30/15.
//

#ifndef GITCPP_REFERENCE_H
#define GITCPP_REFERENCE_H

#include <string>
#include <memory>
#include "Repository.h"
#include "GitObjectId.h"
#include "GitObject.h"

class Repository;

class Reference {
public:
    static bool IsValidName(const std::string& sName);
    static bool NormalizeName(std::string& sName);

    enum EType {
        DIRECT,
        SYMBOLICs
    };
    GitObjectId Target() const;
    GitObjectId TargetPeel() const; // direct and hard tag
    EType Type() const;
    std::string Name() const;
    std::shared_ptr<Reference> Resolve();
    std::shared_ptr<Repository> RepositoryOwner();

    void Delete();

    bool IsBranch() const;
    bool IsRemote() const;
    bool IsTag() const;
    bool IsNote() const;
    //GitObject Peel(GitObjectType objectType);
    std::string ShortHand();
private:
    git_reference* m_pReference;
};


#endif //GITCPP_REFERENCE_H
