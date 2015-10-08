//
// Created by ekuch on 10/5/15.
//

#ifndef GITCPP_HANDLEUTIL_H
#define GITCPP_HANDLEUTIL_H

#include <git2/types.h>
#include <git2/oid.h>
#include "interface/FwdDecl.h"

namespace gitcpp {
    class HandleUtil {
    public:
        static git_reference*& Handle(IReferencePtr& ptrReference);
        static git_oid*& Handle(IObjectIdPtr& ptrObjectId);
    };
}

#endif //GITCPP_HANDLEUTIL_H
