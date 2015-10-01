//
// Created by ekuch on 9/30/15.
//

#ifndef GITCPP_REFERENCE_H
#define GITCPP_REFERENCE_H

#include <string>
#include <bits/shared_ptr.h>
#include "Repository.h"

class Reference {
public:
    static bool IsValidName(const std::string& sName) const;
    static bool NormalizeName(std::string& sName);

    enum EType {
        DIRECT,
        SYMBOLIC
    };
    ObjectId Target() const;
    ObjectId TargetPeel() const; // direct and hard tag
    EType Type() const;
    std::string Name() const;
    std::shared_ptr<Reference> Resolve();
    std::shared_ptr<Repository> RepositoryOwner();

    void Delete();

    bool IsBranch() const;
    bool IsRemote() const;
    bool IsTag() const;
    bool IsNote() const;
    GitObject Peel(ObjectType objectType);
    std::string ShortHand();
};


#endif //GITCPP_REFERENCE_H
