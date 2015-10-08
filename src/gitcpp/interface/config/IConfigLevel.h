//
// Created by ekuch on 10/2/15.
//

#ifndef GITCPP_ICONFIGLEVEL_H
#define GITCPP_ICONFIGLEVEL_H

namespace gitcpp { namespace config {
        class IConfigLevel {
        public:
            virtual ~IConfigLevel() = 0;
            /**
        * Priority level of a config file.
        * These priority levels correspond to the natural escalation logic
        * (from higher to lower) when searching for config entries in git.git.
        *
        * git_config_open_default() and git_repository_config() honor those
        * priority levels as well.
        */
            enum EConfigLevel {
                /** System-wide configuration file; /etc/gitconfig on Linux systems */
                        CONFIG_LEVEL_SYSTEM = 1,

                /** XDG compatible configuration file; typically ~/.config/git/config */
                        CONFIG_LEVEL_XDG = 2,

                /** User-specific configuration file (also called Global configuration
                 * file); typically ~/.gitconfig
                 */
                        CONFIG_LEVEL_GLOBAL = 3,

                /** Repository specific configuration file; $WORK_DIR/.git/config on
                 * non-bare repos
                 */
                        CONFIG_LEVEL_LOCAL = 4,

                /** Application specific configuration file; freely defined by applications
                 */
                        CONFIG_LEVEL_APP = 5,

                /** Represents the highest level available config file (i.e. the most
                 * specific config file available that actually is loaded)
                 */
                        CONFIG_HIGHEST_LEVEL = -1,
            };

            virtual EConfigLevel Level() = 0;
        protected:
            IConfigLevel() {}
        };
        inline IConfigLevel::~IConfigLevel() { }
    }}


#endif //GITCPP_ICONFIGLEVEL_H
