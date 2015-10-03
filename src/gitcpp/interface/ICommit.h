//
// Created by ekuch on 10/2/15.
//

#ifndef GITCPP_ICOMMIT_H
#define GITCPP_ICOMMIT_H

#include "interface/FwdDecl.h"

namespace gitcpp {
    class ICommit {
    public:
        virtual ~ICommit() = 0;

        virtual IObjectIdPtr Id() = 0;
        virtual IRepositoryPtr Owner() = 0;
        virtual std::string Encoding() = 0;
        virtual std::string Message() = 0;
        virtual std::string RawMessage() = 0;
        virtual std::string Summary() = 0;
        virtual std::string RawHeader() = 0;

        virtual ITimePtr Time() = 0;
        virtual ISignaturePtr Author() = 0;
        virtual ISignaturePtr Commiter() = 0;

        virtual ITreePtr Tree() = 0;
        virtual IObjectIdPtr TreeId() = 0;
        virtual int ParentCount() = 0;
        virtual ICommitPtr Parent(int nIndex) = 0;
        virtual IObjectId ParentId(int nIndex) = 0;
        virtual ICommitPtr NthGenAncestor(int nGen) = 0;
        virtual bool HeaderFieldExists(const std::string& sField) = 0;
        virtual std::string HeaderField(const std::string& sField) = 0;


    protected:
        ICommit() {}
    };
};


#endif //GITCPP_ICOMMIT_H
