//
// Created by ekuch on 10/6/15.
//

#include "ErrorUtil.h"
#include <git2/errors.h>

namespace gitcpp {

    void ErrorUtil::ThrowOnError(int nReturnCode)
    {
        if (nReturnCode != 0)
        {
            const git_error* pError = giterr_last();
            if (pError)
            {
                ErrorException except(nReturnCode, pError->klass, pError->message);
                giterr_clear();
                throw except;
            }
            throw ErrorException(nReturnCode, 0, "No error found!");
        }
    }
}