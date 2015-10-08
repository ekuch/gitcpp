//
// Created by ekuch on 10/1/15.
//

#ifndef GITCPP_FWDDECL_H
#define GITCPP_FWDDECL_H

#include <memory>

namespace gitcpp {
    class ICommit;
    class IIndex;
    class IObject;
    class IObjectDatabase;
    class IObjectId;
    class IObjectType;
    class IReference;
    class IReferenceDatabase;
    class IRepository;
    template <typename T> class IIterator;


    typedef std::shared_ptr<ICommit> ICommitPtr;
    typedef std::shared_ptr<IObject> IObjectPtr;
    typedef std::shared_ptr<IObjectType> IObjectTypePtr;
    typedef std::shared_ptr<IObjectId> IObjectIdPtr;
    typedef std::shared_ptr<IReference> IReferencePtr;
    typedef std::shared_ptr<IRepository> IRepositoryPtr;
    typedef std::shared_ptr<IObjectDatabase> IObjectDatabasePtr;
    typedef std::shared_ptr<IReferenceDatabase> IReferenceDatabasePtr;
    typedef std::shared_ptr<IIndex> IIndexPtr;

    namespace annotated_commit {
        class IAnnotatedCommit;
        class IAnnotatedCommitRepositoryExt;

        typedef std::shared_ptr<IAnnotatedCommit> IAnnotatedCommitPtr;
    };

    namespace config {
        class IConfig;
        class IConfigEntry;
        class IConfigLevel;

        typedef IIterator<IConfigEntry> IConfigEntryIterator;

        typedef std::shared_ptr<IConfig> IConfigPtr;
        typedef std::shared_ptr<IConfigEntry> IConfigEntryPtr;
        typedef std::shared_ptr<IConfigLevel> IConfigLevelPtr;
        typedef std::shared_ptr<IConfigEntryIterator> IConfigEntryIteratorPtr;
    };
};

#endif //GITCPP_FWDDECL_H
