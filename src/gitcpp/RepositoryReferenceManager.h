//
// Created by ekuch on 9/30/15.
//

#ifndef GITCPP_REPOSITORYREFERENCEMANAGER_H
#define GITCPP_REPOSITORYREFERENCEMANAGER_H

#include <string>
#include <memory>
#include "Reference.h"

struct git_repository;

class Reference;
class Repository;

class ReferenceIterator
{
public:
    ReferenceIterator();
    ~ReferenceIterator();
    std::string NextName();
    std::shared_ptr<Reference> Next();
};

class RepositoryReferenceManager
{
public:
    RepositoryReferenceManager(Repository& repository);

    std::shared_ptr<Reference> LookupByLongName(const std::string& sLongName);

    void RemoveReference(const std::string& refname);
    bool HasLog(const std::string& refname);
    void EnsureLog(const std::string& refname);
private:

    Repository& m_repository;
};


#endif //GITCPP_REPOSITORYREFERENCEMANAGER_H
