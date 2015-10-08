//
// Created by ekuch on 10/1/15.
//

#ifndef GITCPP_ICONFIGENTRY_H
#define GITCPP_ICONFIGENTRY_H

#include <string>
#include "interface/FwdDecl.h"

namespace gitcpp { namespace config{
  class IConfigEntry
  {
  public:
      virtual ~IConfigEntry() = 0;
      virtual std::string Name() = 0;
      virtual std::string Value() = 0;
      virtual IConfigLevelPtr Level() = 0;
  protected:
      IConfigEntry() {}
  };
        inline IConfigEntry::~IConfigEntry() {}
}; };

#endif //GITCPP_ICONFIGENTRY_H
