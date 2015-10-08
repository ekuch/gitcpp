//
// Created by ekuch on 10/5/15.
//

#include "HandleUtil.h"

namespace gitcpp {
    static HandleUtil& Instance()
    {
        static HandleUtil util;
        return util;
    }
}