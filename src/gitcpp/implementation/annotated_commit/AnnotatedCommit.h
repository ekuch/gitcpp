//
// Created by ekuch on 10/7/15.
//

#ifndef GITCPP_ANNOTATEDCOMMIT_H
#define GITCPP_ANNOTATEDCOMMIT_H

#include <git2/types.h>
#include "interface/annotated_commit/IAnnotatedCommit.h"

namespace gitcpp { namespace annotated_commit {
        class AnnotatedCommit : public IAnnotatedCommit {
        public:
            AnnotatedCommit() : m_Handle(nullptr) {}
            virtual ~AnnotatedCommit();
            virtual IObjectIdPtr ObjectId();
            git_annotated_commit* m_Handle;
        };
    }}




#endif //GITCPP_ANNOTATEDCOMMIT_H
