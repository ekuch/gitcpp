//
// Created by ekuch on 9/30/15.
//

#ifndef GITCPP_REPOSITORY_H
#define GITCPP_REPOSITORY_H

#include <memory>
#include <string>
#include <git2/repository.h>
#include "Reference.h"

struct git_repository_init_options;



class RepositoryInitOptions {
public:
    enum class EFlags : uint32_t {
        INIT_BARE              = (1u << 0),
        INIT_NO_REINIT         = (1u << 1),
        INIT_NO_DOTGIT_DIR     = (1u << 2),
        INIT_MKDIR             = (1u << 3),
        INIT_MKPATH            = (1u << 4),
        INIT_EXTERNAL_TEMPLATE = (1u << 5),
        INIT_RELATIVE_GITLINK  = (1u << 6),
    };

    enum class EMode : uint32_t {
        INIT_SHARED_UMASK = 0,
        INIT_SHARED_GROUP = 0002775,
        INIT_SHARED_ALL   = 0002777,
    };

    RepositoryInitOptions(
            EFlags eFlags,
            EMode eMode,
            const std::string& sWorkingPath,
            const std::string& sDescription,
            const std::string& sTemplatePath,
            const std::string& sInitialHead,
            const std::string& sOriginUrl
    );
    ~RepositoryInitOptions();
    git_repository_init_options& get() const { return *m_pOptions; }
private:
    git_repository_init_options* m_pOptions;
    const EFlags m_eFlags;
    const EMode m_eMode;
    const std::string& m_sWorkingPath,
    const std::string& m_sDescription,
    const std::string& m_sTemplatePath,
    const std::string& m_sInitialHead,
    const std::string& m_sOriginUrl
};

struct git_repository;
class Config;
class Reference;

class Repository {
public:
    friend class HandleUtility;
    class FetchHeadCallback
    {
        virtual int EntryCallback(const std::string& refName, const std::string& remoteUrl, const ObjectId& oid, bool isMerge, void* payload) = 0;
    };

    class MergeHeadCallback
    {
        virtual int CommitCallback(const ObjectId *oid, void *payload) = 0;
    };

    class

    virtual ~Repository();
    static std::shared_ptr<Repository> Open(const std::string& sPath);
    static std::shared_ptr<Repository> Init(const std::string& sPath, const RepositoryInitOptions& options);

    RepositoryReferenceManager& ReferneceManager();
    bool HeadExists() const;
    bool IsHeadDetatched() const;
    bool IsHeadUnborn() const;
    bool IsEmpty() const;
    std::string Path() const;
    std::string WorkingDir() const;
    void SetWorkingDir(const std::string& sWorkingDir, bool updateGitLink);
    bool IsBare() const;
    std::shared_ptr<Config> Config() const;
    std::shared_ptr<Config> ConfigSnapshot() const;
    std::shared_ptr<ObjectDatabase> ObjectDatabase() const;
    std::shared_ptr<ReferenceDatabase> ReferenceDatabase() const;
    std::shared_ptr<Index> Index() const;
    std::string Message() const;
    void RemoveMessage() const;
    void CleanupState() const;

    //TODO make payload type-safe
    void FetchHeadForEach(FetchHeadCallback* pCallback, void* payload);
    void MergeHeadForEach(MergeHeadCallback* pCallback, void* payload);

    ObjectId HashFile(const std::string& sPath, ObjectType type, std::shared_ptr<std::string> as_path);

protected:
private:
    Repository();

    git_repository* m_pRepository;
    shared_ptr<RepositoryReferenceManager> m_pReferenceManager;

};


#endif //GITCPP_REPOSITORY_H
