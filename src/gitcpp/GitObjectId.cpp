//
// Created by ekuch on 9/30/15.
//

#include "GitObjectId.h"
#include "util/ErrorUtility.h"
#include <git2.h>
#include <memory>

struct GitObjectIdData {
    git_oid oid;
};

GitObjectId::GitObjectId(const GitObjectIdData* pData)
: m_pData(pData)
{

}

GitObjectId::~GitObjectId()
{
    delete m_pData;
}

GitObjectId GitObjectId::FromString(const std::string& sId)
{
    auto ptrData = std::unique_ptr<GitObjectIdData>(new GitObjectIdData());
    ErrorUtility::ThrowOnError("git_oid_fromstrp", git_oid_fromstrp(&ptrData->oid, sId.c_str()));
    return GitObjectId(ptrData.release());
}
GitObjectId GitObjectId::FromVector(const std::vector<char>& vId)
{
    auto ptrData = std::unique_ptr<GitObjectIdData>(new GitObjectIdData());
    ErrorUtility::ThrowOnError("git_oid_fromstrn", git_oid_fromstrn(&ptrData->oid, vId.data(), vId.size()));
    return GitObjectId(ptrData.release());
}

std::vector<char> GitObjectId::NFormat(int n) const
{
    std::vector<char> vFormat;
    vFormat.resize(n);
    git_oid_nfmt(vFormat.data(), n, &m_pData->oid);
    return vFormat;
}

std::string GitObjectId::ToString() const
{
    return std::string(git_oid_tostr_s(&m_pData->oid));
}
GitObjectId GitObjectId::Copy() const
{
    auto ptrData = std::unique_ptr<GitObjectIdData>(new GitObjectIdData());
    git_oid_cpy(&ptrData->oid, &m_pData->oid);
    return GitObjectId(ptrData.release());
}

bool GitObjectId::IsZero() const
{
    ToBool(git_oid_iszero, &m_pData->oid);
}
