//
// Created by ekuch on 10/5/15.
//

#ifndef GITCPP_CONFIGUTIL_H
#define GITCPP_CONFIGUTIL_H

#include "interface/FwdDecl.h"
#include "interface/config/IConfigUtil.h"
#include <string.h>

namespace gitcpp { namespace config {
        class ConfigUtil : public IConfigUtil {
            ConfigUtil();
            virtual ~ConfigUtil();
            virtual std::string GlobalConfigFile();
            virtual std::string XdgConfigFile();
            virtual std::string SystemConfigFile();

            virtual bool ParseBool(const std::string& sValue);
            virtual int32_t ParseInt32(const std::string& sValue);
            virtual int64_t ParseInt64(const std::string& sValue);
            virtual std::string ParsePath(const std::string& sValue);
        };
    };};


#endif //GITCPP_CONFIGUTIL_H
