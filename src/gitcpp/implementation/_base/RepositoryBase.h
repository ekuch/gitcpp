//
// Created by ekuch on 10/7/15.
//

#ifndef GITCPP_REPOSITORYBASE_H
#define GITCPP_REPOSITORYBASE_H

#include <git2/types.h>
namespace gitcpp { namespace _base {
        class RepositoryBase {
        protected:
            virtual git_repository* Handle();
        };
    }}



#endif //GITCPP_REPOSITORYBASE_H
