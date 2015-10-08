//
// Created by ekuch on 10/6/15.
//

#include "ConfigEntryIterator.h"
#include "ConfigEntry.h"

namespace gitcpp { namespace config {
        ConfigEntryIterator::~ConfigEntryIterator()
        {
            if (m_Handle) {
                git_config_iterator_free(m_Handle);
                m_Handle = nullptr;
            }
        }
        IConfigEntryPtr ConfigEntryIterator::Next()
        {
            auto ptrEntry = std::make_shared<ConfigEntry>();
            if (0 != git_config_next(&ptrEntry->m_Handle, m_Handle)) { return IConfigEntryPtr(nullptr); }
            return ptrEntry;
        }
    }}


