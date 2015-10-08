//
// Created by ekuch on 10/6/15.
//

#ifndef GITCPP_CONFIG_H
#define GITCPP_CONFIG_H

#include "interface/config/IConfig.h"
#include <git2/config.h>

namespace gitcpp { namespace config {
        class Config : public IConfig {
        public:
            Config(git_config* handle) : m_Handle(handle) {}
            virtual ~Config();
            virtual IConfigEntryPtr Entry(const std::string& sName);
            virtual int32_t Int32(const std::string& sName);
            virtual int64_t Int64(const std::string& sName);
            virtual bool Bool(const std::string& sName);
            virtual std::string Path(const std::string& sName);
            virtual std::string String(const std::string& sName);
            virtual void Set(const std::string& sName, const int32_t nValue);
            virtual void Set(const std::string& sName, const int64_t nValue);
            virtual void Set(const std::string& sName, const bool bValue);
            virtual void Set(const std::string& sName, const std::string& sValue);
            virtual void Set(const std::string& sName, const std::string& sRegex, const std::string& sValue);
            virtual void Delete(const std::string& sName);
            virtual void Delete(const std::string& sName, const std::string& sRegex);

            // TODO: Mapped entries

            virtual IConfigEntryIteratorPtr MultivarIterator(const std::string& sName);
            virtual IConfigEntryIteratorPtr MultivarIterator(const std::string& sName, const std::string& sRegex);
            virtual IConfigEntryIteratorPtr Iterator();
            virtual IConfigEntryIteratorPtr Iterator(const std::string& sRegex);
            virtual void ForEachMultivar(IForEachCallback& callback, const std::string& sMultiVarName);
            virtual void ForEachMultivar(IForEachCallback& callback, const std::string& sMultiVarName, const std::string& sRegex);
            virtual void ForEach(IForEachCallback& callback);
            virtual void ForEach(IForEachCallback& callback, const std::string& sRegex);

            virtual IConfigPtr Snapshot();

            git_config* m_Handle;
        };
    };};


#endif //GITCPP_CONFIG_H
