//
// Created by ekuch on 10/1/15.
//

#ifndef GITCPP_IOBJECTID_H
#define GITCPP_IOBJECTID_H

#include <vector>
#include <string>
#include "FwdDecl.h"

namespace gitcpp {

    class IObjectId {
    public:
        virtual ~IObjectId() = 0;

        virtual std::vector<char> NFormat(int n) const = 0;

        virtual std::string ToString() const = 0;

        virtual IObjectIdPtr Copy() const = 0;

        virtual bool IsZero() const = 0;

    protected:
        IObjectId() {}
    };
}


#endif //GITCPP_IOBJECTID_H
