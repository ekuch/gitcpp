//
// Created by ekuch on 10/5/15.
//

#include "ConfigUtil.h"
#include "implementation/GitBuf.h"
#include "git2/config.h"

namespace gitcpp { namespace config {
        ConfigUtil::~ConfigUtil()
        {}
        std::string ConfigUtil::GlobalConfigFile()
        {
            GitBuf gitBuf;
            git_config_find_global(&gitBuf.m_Handle);
            return gitBuf.ToString();
        }
        std::string ConfigUtil::XdgConfigFile()
        {
            GitBuf gitBuf;
            git_config_find_xdg(&gitBuf.m_Handle);
            return gitBuf.ToString();
        }
        std::string ConfigUtil::SystemConfigFile()
        {
            GitBuf gitBuf;
            git_config_find_system(&gitBuf.m_Handle);
            return gitBuf.ToString();
        }

        bool ConfigUtil::ParseBool(const std::string& sValue)
        {
            int nBool = 0;
            git_config_parse_bool(&nBool, sValue.c_str());
            return nBool == 1;
        }
        int32_t ConfigUtil::ParseInt32(const std::string& sValue)
        {
            int32_t nValue;
            git_config_parse_int32(&nValue, sValue.c_str());
            return nValue;
        }
        int64_t ConfigUtil::ParseInt64(const std::string& sValue)
        {
            int64_t nValue;
            git_config_parse_int64(&nValue, sValue.c_str());
            return nValue;
        }
        std::string ConfigUtil::ParsePath(const std::string& sValue)
        {
            GitBuf gitBuf;
            git_config_parse_path(&gitBuf.m_Handle, sValue.c_str());
            return gitBuf.ToString();
        }

    }}

//TODO git_config_open_default
//TODO        git_config_new
//TODO git_config_add_file_ondisk
//TODO        git_config_open_ondisk
//TODO git_config_open_level
//TODO        git_config_open_global