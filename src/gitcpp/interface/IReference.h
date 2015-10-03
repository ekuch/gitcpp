//
// Created by ekuch on 10/1/15.
//

#ifndef GITCPP_IREFERENCE_H
#define GITCPP_IREFERENCE_H

#include "FwdDecl.h"

namespace gitcpp {
  class IReference {
  public:
      ~IReference() = 0;
      enum EType {
          DIRECT,
          SYMBOLICs
      };
      virtual IObjectIdPtr Target() const = 0;
      virtual IObjectIdPtr TargetPeel() const = 0; // direct and hard tag
      virtual EType Type() const = 0;
      virtual std::string Name() const = 0;
      virtual IReferencePtr Resolve() = 0;
      virtual IRepositoryPtr RepositoryOwner() = 0;

      virtual void Delete() = 0;

      virtual bool IsBranch() const = 0;
      virtual bool IsRemote() const = 0;
      virtual bool IsTag() const = 0;
      virtual bool IsNote() const = 0;
      virtual IObjectPtr Peel(IObjectType& objectType) = 0;
      virtual std::string ShortHand() = 0;
  protected:
      IReference() {}
  };
};

#endif //GITCPP_IREFERENCE_H
