//
// Created by ekuch on 10/1/15.
//

#ifndef GITCPP_IREPOSITORY_H
#define GITCPP_IREPOSITORY_H

#include "FwdDecl.h"

namespace gitcpp {

    class IRepository {
    public:
        virtual ~IRepository() = 0;
        virtual bool HeadExists() const = 0;
        virtual bool IsHeadDetatched() const = 0;
        virtual bool IsHeadUnborn() const = 0;
        virtual bool IsEmpty() const = 0;
        virtual std::string Path() const = 0;
        virtual std::string WorkingDir() const = 0;
        virtual void SetWorkingDir(const std::string& sWorkingDir, bool updateGitLink) = 0;
        virtual bool IsBare() const = 0;
        virtual IConfigPtr Config() const = 0;
        virtual IConfigPtr ConfigSnapshot() const = 0;
        virtual IObjectDatabasePtr ObjectDatabase() const = 0;
        virtual IReferenceDatabasePtr ReferenceDatabase() const = 0;
        virtual IIndexPtr Index() const = 0;
        virtual std::string Message() const = 0;
        virtual void RemoveMessage() const = 0;
        virtual void CleanupState() const = 0;

        //TODO make payload type-safe
        void FetchHeadForEach(FetchHeadCallback* pCallback, void* payload);
        void MergeHeadForEach(MergeHeadCallback* pCallback, void* payload);

        ObjectId HashFile(const std::string& sPath, ObjectType type, std::shared_ptr<std::string> as_path);
    protected:
        IRepository() {}
};

};


#endif //GITCPP_IREPOSITORY_H
