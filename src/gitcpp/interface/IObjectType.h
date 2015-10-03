//
// Created by ekuch on 10/1/15.
//

#ifndef GITCPP_IOBJECTTYPE_H
#define GITCPP_IOBJECTTYPE_H

#include "FwdDecl.h"

namespace gitcpp {


    class IObjectType {
    public:
        ~IObjectType() = 0;
        enum EGitObjectType {
            GIT_OBJ_ANY = -2, /**< Object can be any of the following */
                    GIT_OBJ_BAD = -1, /**< Object is invalid. */
                    GIT_OBJ__EXT1 = 0, /**< Reserved for future use. */
                    GIT_OBJ_COMMIT = 1, /**< A commit object. */
                    GIT_OBJ_TREE = 2, /**< A tree (directory listing) object. */
                    GIT_OBJ_BLOB = 3, /**< A file revision object. */
                    GIT_OBJ_TAG = 4, /**< An annotated tag object. */
                    GIT_OBJ__EXT2 = 5, /**< Reserved for future use. */
                    GIT_OBJ_OFS_DELTA = 6, /**< A delta, base is given by an offset. */
                    GIT_OBJ_REF_DELTA = 7, /**< A delta, base is given by object id. */
        };

        //Constructor? GitObjectType(EGitObjectType eObjectType);
        //Constructor? static GitObjectType FromString(const std::string& sObjectType);

        virtual const EGitObjectType Type() const = 0;

        virtual std::string ToString() const = 0;

        virtual bool IsLoose() const = 0;

        virtual size_t Size() const = 0;
    protected:
        IObjectType() {}
    };
};

#endif //GITCPP_IOBJECTTYPE_H
