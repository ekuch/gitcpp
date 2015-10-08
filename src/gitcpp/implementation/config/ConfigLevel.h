//
// Created by ekuch on 10/5/15.
//

#ifndef GITCPP_CONFIGLEVEL_H
#define GITCPP_CONFIGLEVEL_H

#include "interface/FwdDecl.h"
#include "interface/config/IConfigLevel.h"
#include <git2/config.h>

namespace gitcpp {
    namespace config {
        class ConfigLevel : public IConfigLevel {
        public:
            virtual EConfigLevel Level() { return m_eConfigLevel; }

            static IConfigLevelPtr System()
            {
                return std::shared_ptr<IConfigLevel>(new ConfigLevel(GIT_CONFIG_LEVEL_SYSTEM));
            }

            static IConfigLevelPtr Xdg()
            {
                return std::shared_ptr<IConfigLevel>(new ConfigLevel(GIT_CONFIG_LEVEL_XDG));
            }

            static IConfigLevelPtr Global()
            {
                return std::shared_ptr<IConfigLevel>(new ConfigLevel(GIT_CONFIG_LEVEL_GLOBAL));
            }

            static IConfigLevelPtr Local()
            {
                return std::shared_ptr<IConfigLevel>(new ConfigLevel(GIT_CONFIG_LEVEL_LOCAL));
            }

            static IConfigLevelPtr App()
            {
                return std::shared_ptr<IConfigLevel>(new ConfigLevel(GIT_CONFIG_LEVEL_APP));
            }

            static IConfigLevelPtr HighestLevel()
            {
                return std::shared_ptr<IConfigLevel>(new ConfigLevel(GIT_CONFIG_HIGHEST_LEVEL));
            }
            ConfigLevel(EConfigLevel eConfigLevel) : m_eConfigLevel(eConfigLevel) { }
            ConfigLevel(git_config_level_t eGitConfigLevel)
            : m_eConfigLevel(static_cast<EConfigLevel>(eGitConfigLevel))
            {

            }

        private:
            EConfigLevel m_eConfigLevel;
        };
    };
};


#endif //GITCPP_CONFIGLEVEL_H
