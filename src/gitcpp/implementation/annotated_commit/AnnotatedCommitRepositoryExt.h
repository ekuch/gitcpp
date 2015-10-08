//
// Created by ekuch on 10/7/15.
//

#ifndef GITCPP_ANNOTATEDCOMMITREPOSITORYEXT_H
#define GITCPP_ANNOTATEDCOMMITREPOSITORYEXT_H

#include "implementation/_base/RepositoryBase.h"
#include "interface/annotated_commit/IAnnotatedCommitRepositoryExt.h"

namespace gitcpp { namespace annotated_commit {
        class AnnotatedCommitRepositoryExt : public gitcpp::_base::RepositoryBase, public IAnnotatedCommitRepositoryExt {
        public:
            virtual ~AnnotatedCommitRepositoryExt() {}
            virtual IAnnotatedCommitPtr AnnotatedCommit(IReferencePtr& ptrReference);
            virtual IAnnotatedCommitPtr AnnotatedCommit(const std::string& sBranchName, const std::string& sUrl, IObjectIdPtr& ptrObjectId);
            virtual IAnnotatedCommitPtr AnnotatedCommit(IObjectIdPtr& ptrObjectId);
            virtual IAnnotatedCommitPtr AnnotatedCommit(const std::string& sRevSpec);
        };
    }}




#endif //GITCPP_ANNOTATEDCOMMITREPOSITORYEXT_H
