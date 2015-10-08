//
// Created by ekuch on 10/7/15.
//

#include "AnnotatedCommit.h"
#include <git2/annotated_commit.h>

namespace gitcpp { namespace annotated_commit {
        AnnotatedCommit::~AnnotatedCommit()
        {
            if (m_Handle)
            {
                git_annotated_commit_free(m_Handle);
                m_Handle = nullptr;
            }
        }
        IObjectIdPtr AnnotatedCommit::ObjectId()
        {
            git_annotated_commit_id(m_Handle);
        }
    }}