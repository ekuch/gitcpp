//
// Created by ekuch on 10/5/15.
//

#include "implementation/config/ConfigEntry.h"
#include "implementation/config/ConfigLevel.h"
#include "git2/config.h"
namespace gitcpp { namespace config {

    ConfigEntry::ConfigEntry() : m_Handle(nullptr) {}
    ConfigEntry::~ConfigEntry()
    {
        if (m_Handle)
        {
            git_config_entry_free(m_Handle);
        }
    }
    std::string ConfigEntry::Name()
    {
        return std::string(m_Handle->name);
    }
    std::string ConfigEntry::Value()
    {
        return std::string(m_Handle->value);
    }
    IConfigLevelPtr ConfigEntry::Level()
    {
        return IConfigLevelPtr(new ConfigLevel(m_Handle->level));
    }
};};