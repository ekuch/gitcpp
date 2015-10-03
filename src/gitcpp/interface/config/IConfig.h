//
// Created by ekuch on 10/1/15.
//

#ifndef GITCPP_ICONFIG_H
#define GITCPP_ICONFIG_H

#include <string>
#include "interface/FwdDecl.h"

namespace gitcpp { namespace config {
  class IConfig {
      class IForEachCallback {
      public:
          virtual ~IForEachCallback() = 0;
          virtual void DoWork(const IConfigEntryPtr& ptrEntry, IForEachCallback* pCallback) = 0;
      protected:
          IForEachCallback() {}
      };

      virtual IConfigEntryPtr Entry(const std::string& sName) = 0;
      virtual int32_t Int32(const std::string& sName) = 0;
      virtual int64_t Int64(const std::string& sName) = 0;
      virtual bool Bool(const std::string& sName) = 0;
      virtual std::string Path(const std::string& sName) = 0;
      virtual void Set(const std::string& sName, const int32_t nValue) = 0;
      virtual void Set(const std::string& sName, const int64_t nValue) = 0;
      virtual void Set(const std::string& sName, const bool bValue) = 0;
      virtual void Set(const std::string& sName, const std::string& sValue) = 0;
      virtual void Set(const std::string& sName, const std::string& sRegex, const std::string& sValue) = 0;
      virtual void Delete(const std::string& sName) = 0;
      virtual void Delete(const std::string& sName, const std::string& sRegex) = 0;

      // TODO: Mapped entries

      virtual IConfigEntryIteratorPtr MultivarIterator(const std::string& sName) = 0;
      virtual IConfigEntryIteratorPtr MultivarIterator(const std::string& sName, const std::string& sRegex) = 0;
      virtual IConfigEntryIteratorPtr Iterator() = 0;
      virtual IConfigEntryIteratorPtr Iterator(const std::string& sRegex) = 0;
      virtual void ForEachMultivar(IForEachCallback& callback, const std::string& sMultiVarName) = 0;
      virtual void ForEachMultivar(IForEachCallback& callback, const std::string& sMultiVarName, const std::string& sRegex) = 0;
      virtual void ForEach(IForEachCallback& callback) = 0;
      virtual void ForEach(IForEachCallback& callback, const std::string& sRegex) = 0;
  };
};};


#endif //GITCPP_ICONFIG_H
