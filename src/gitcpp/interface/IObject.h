//
// Created by ekuch on 10/1/15.
//

#ifndef GITCPP_IOBJECT_H
#define GITCPP_IOBJECT_H

#include "FwdDecl.h"

namespace gitcpp {
    class IObject {
    public:
        virtual ~IObject() = 0;

        // Assumes we are the "treeish"
        IObjectPtr LookUpByPath(const std::string& sPath, IObjectType gitObjectType1) const;

        IObjectIdPtr ObjectId() const;
        //TODO GitObjectPrefix ShortObjectId() const;

        IObjectType Type() const;

        IRepositoryPtr RepositoryOwner();

        IObjectPtr Peel(IObjectType type);
        IObjectPtr Duplicate();

    protected:
        IObject() {};
    };
}


#endif //GITCPP_IOBJECT_H
