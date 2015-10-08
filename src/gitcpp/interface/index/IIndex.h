//
// Created by ekuch on 10/2/15.
//

#ifndef GITCPP_IINDEX_H
#define GITCPP_IINDEX_H

#include "interface/FwdDecl.h"

namespace gitcpp { namespace index {
    class IIndex {
    public:
        virtual ~IIndex() = 0;
        IRepositoryPtr Owner();
    protected:
        IIndex() {}
    };
};};

#endif //GITCPP_IINDEX_H
