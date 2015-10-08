//
// Created by ekuch on 10/6/15.
//

#ifndef GITCPP_CONFIGITERATOR_H
#define GITCPP_CONFIGITERATOR_H

#include "interface/FwdDecl.h"
#include "interface/IIterator.h"
#include "git2/config.h"
namespace gitcpp { namespace config {
        class ConfigEntryIterator : public IConfigEntryIterator {
        public:
            ConfigEntryIterator(git_config_iterator* handle) : m_Handle(handle) {}
            ~ConfigEntryIterator();
            virtual IConfigEntryPtr Next();
            git_config_iterator* m_Handle;
        };
    }}



#endif //GITCPP_CONFIGITERATOR_H
