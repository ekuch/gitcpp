//
// Created by ekuch on 9/30/15.
//

#ifndef GITCPP_HANDLEUTILITY_H
#define GITCPP_HANDLEUTILITY_H

#include <git2.h>
#include "../Reference.h"

class HandleUtility {
public:
    static git_repository*& Handle(Repository& reference)
    {
        return reference.m_pRepository;
    }
};


#endif //GITCPP_HANDLEUTILITY_H
