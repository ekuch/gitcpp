//
// Created by ekuch on 9/30/15.
//

#ifndef GITCPP_GITOBJECTID_H
#define GITCPP_GITOBJECTID_H

#include <vector>
#include <string>


struct GitObjectIdData;

class GitObjectId {
public:
    GitObjectId(const GitObjectIdData* pData);
    virtual ~GitObjectId();
    static GitObjectId FromString(const std::string& sId);
    static GitObjectId FromVector(const std::vector<char>& vId);

    std::vector<char> NFormat(int n) const;
    std::string ToString() const;
    GitObjectId Copy() const;

    bool IsZero() const;
private:
    const GitObjectIdData* m_pData;
};


#endif //GITCPP_GITOBJECTID_H
