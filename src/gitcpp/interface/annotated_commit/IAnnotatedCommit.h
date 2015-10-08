//
// Created by ekuch on 10/8/15.
//

#ifndef GITCPP_IANNOTATEDCOMMIT_H
#define GITCPP_IANNOTATEDCOMMIT_H

#include "interface/FwdDecl.h"

namespace gitcpp { namespace annotated_commit {
        class IAnnotatedCommit {
        public:
            virtual ~IAnnotatedCommit() {}
            virtual IObjectIdPtr ObjectId() = 0;
        };
    }}



#endif //GITCPP_IANNOTATEDCOMMIT_H
