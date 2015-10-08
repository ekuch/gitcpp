//
// Created by ekuch on 10/1/15.
//

#ifndef GITCPP_ICONFIGUTIL_H
#define GITCPP_ICONFIGUTIL_H

#include <string>

namespace gitcpp { namespace config {
        class IConfigUtil {
        public:
            virtual ~IConfigUtil() = 0;
            virtual std::string GlobalConfigFile() = 0;
            virtual std::string XdgConfigFile() = 0;
            virtual std::string SystemConfigFile() = 0;

            virtual bool ParseBool(const std::string& sValue) = 0;
            virtual int32_t ParseInt32(const std::string& sValue) = 0;
            virtual int64_t ParseInt64(const std::string& sValue) = 0;
            virtual std::string ParsePath(const std::string& sValue) = 0;

        protected:
            IConfigUtil() {}
        };
        IConfigUtil::~IConfigUtil() { }
    }}

#endif //GITCPP_ICONFIGUTIL_H
