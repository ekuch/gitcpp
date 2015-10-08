//
// Created by ekuch on 10/5/15.
//

#ifndef GITCPP_CONFIGENTRY_H
#define GITCPP_CONFIGENTRY_H

#include "interface/FwdDecl.h"
#include "interface/config/IConfigEntry.h"
#include <git2/config.h>

namespace gitcpp { namespace config{
        class ConfigEntry :public IConfigEntry{
        public:
            ConfigEntry();
            virtual ~ConfigEntry();
            virtual std::string Name();
            virtual std::string Value();
            virtual IConfigLevelPtr Level();
            git_config_entry* m_Handle;
        };

    };
};





#endif //GITCPP_CONFIGENTRY_H
