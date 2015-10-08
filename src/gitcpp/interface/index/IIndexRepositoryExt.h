//
// Created by ekuch on 10/3/15.
//

#ifndef GITCPP_IINDEXREPOSITORYEXT_H
#define GITCPP_IINDEXREPOSITORYEXT_H

#include "interface/FwdDecl.h"

namespace gitcpp { namespace index {
    class IIndexRepositoryExt {
    public:
        virtual ~IIndexRepositoryExt() = 0;
        IObjectIdPtr Write(IIndexPtr ptrIndex);
    protected:
        IIndexRepositoryExt() {}
    };
}; };



#endif //GITCPP_IINDEXREPOSITORYEXT_H
