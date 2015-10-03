//
// Created by ekuch on 9/30/15.
//

#ifndef GITCPP_LIBGIT2UTIL_H
#define GITCPP_LIBGIT2UTIL_H

#include <string>

#define ToBool(function, argument) \
int nCode = function(argument); \
if (nCode == 0) return false; \
if (nCode == 1) return true; \
ErrorUtility::ThrowError(#function, nCode);

class ErrorUtility {
public:
    static void ThrowOnError(const std::string& sError, int nReturnCode){ /* TODO */}
    static void ThrowError(const std::string& sError, int nReturnCode){ /* TODO */}
};


#endif //GITCPP_LIBGIT2UTIL_H
