//
// Created by ekuch on 10/6/15.
//

#ifndef GITCPP_ERRORUTIL_H
#define GITCPP_ERRORUTIL_H

#include <stdexcept>

namespace gitcpp {

    class ErrorException : std::exception {
    public:
        ErrorException(int returnCode, int klass, std::string sMessage)
                : m_nReturnCode(returnCode)
                , m_nKlass(klass)
                , m_sMessage(sMessage)
        {}
    private:
        int m_nReturnCode;
        int m_nKlass;
        std::string m_sMessage;
    };

    class ErrorUtil {
    public:
        static void ThrowOnError(int nReturnCode);
    };
}



#endif //GITCPP_ERRORUTIL_H
