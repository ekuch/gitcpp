//
// Created by ekuch on 10/7/15.
//

#include "AnnotatedCommitRepositoryExt.h"
#include "implementation/HandleUtil.h"
#include "implementation/ErrorUtil.h"
#include "implementation/annotated_commit/AnnotatedCommit.h"
#include <git2/annotated_commit.h>

namespace gitcpp
{
    namespace annotated_commit
    {
        typedef std::shared_ptr<gitcpp::annotated_commit::AnnotatedCommit> AnnotatedCommitPtr;
        IAnnotatedCommitPtr AnnotatedCommitRepositoryExt::AnnotatedCommit(IReferencePtr& ptrReference)
        {
            AnnotatedCommitPtr annotatedCommitPtr(new gitcpp::annotated_commit::AnnotatedCommit());
            ErrorUtil::ThrowOnError(git_annotated_commit_from_ref(&annotatedCommitPtr->m_Handle, Handle(), HandleUtil::Handle(ptrReference)));
            return annotatedCommitPtr;
        }

        IAnnotatedCommitPtr AnnotatedCommitRepositoryExt::AnnotatedCommit(const std::string& sBranchName, const std::string& sUrl, IObjectIdPtr& ptrObjectId)
        {
            AnnotatedCommitPtr annotatedCommitPtr(new gitcpp::annotated_commit::AnnotatedCommit());
            ErrorUtil::ThrowOnError(git_annotated_commit_from_fetchhead(&annotatedCommitPtr->m_Handle, Handle(), sBranchName.c_str(), sUrl.c_str(), HandleUtil::Handle(ptrObjectId)));
                return annotatedCommitPtr;
        }

        IAnnotatedCommitPtr AnnotatedCommitRepositoryExt::AnnotatedCommit(IObjectIdPtr& ptrObjectId)
        {
            AnnotatedCommitPtr annotatedCommitPtr(new gitcpp::annotated_commit::AnnotatedCommit());
            ErrorUtil::ThrowOnError(git_annotated_commit_lookup(&annotatedCommitPtr->m_Handle, Handle(), HandleUtil::Handle(ptrObjectId)));
            return annotatedCommitPtr;
        }

        IAnnotatedCommitPtr AnnotatedCommitRepositoryExt::AnnotatedCommit(const std::string& sRevSpec)
        {
            AnnotatedCommitPtr annotatedCommitPtr(new gitcpp::annotated_commit::AnnotatedCommit());
            ErrorUtil::ThrowOnError(git_annotated_commit_from_revspec(&annotatedCommitPtr->m_Handle, Handle(), sRevSpec.c_str()));
            return annotatedCommitPtr;
        }
    }
}