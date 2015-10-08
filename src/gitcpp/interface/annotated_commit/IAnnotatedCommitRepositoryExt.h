//
// Created by ekuch on 10/8/15.
//

#ifndef GITCPP_IANNOTATEDCOMMITREPOSITORYEXT_H
#define GITCPP_IANNOTATEDCOMMITREPOSITORYEXT_H

#include "interface/FwdDecl.h"

namespace gitcpp { namespace annotated_commit {
        class IAnnotatedCommitRepositoryExt {
        public:
            virtual ~IAnnotatedCommitRepositoryExt() {}
            virtual IAnnotatedCommitPtr AnnotatedCommit(IReferencePtr& ptrReference) = 0;
            virtual IAnnotatedCommitPtr AnnotatedCommit(const std::string& sBranchName, const std::string& sUrl, IObjectIdPtr& ptrObjectId) = 0;
            virtual IAnnotatedCommitPtr AnnotatedCommit(IObjectIdPtr& ptrObjectId) = 0;
            virtual IAnnotatedCommitPtr AnnotatedCommit(const std::string& sRevSpec) = 0;
        };
    } }



#endif //GITCPP_IANNOTATEDCOMMITREPOSITORYEXT_H
