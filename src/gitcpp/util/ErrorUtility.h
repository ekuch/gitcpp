//
// Created by ekuch on 9/30/15.
//

#ifndef GITCPP_LIBGIT2UTIL_H
#define GITCPP_LIBGIT2UTIL_H

#include <string>

class ErrorUtility {
public:
    static void ThrowOnError(const std::string& sError, int nReturnCode);
    static void ThrowError(const std::string& sError, int nReturnCode);
};


#endif //GITCPP_LIBGIT2UTIL_H
