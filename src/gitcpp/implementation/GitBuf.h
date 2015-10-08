//
// Created by ekuch on 10/5/15.
//

#ifndef GITCPP_GITBUF_H
#define GITCPP_GITBUF_H

#include <string>
#include <git2/buffer.h>
namespace gitcpp {
    class GitBuf {
    public:
        GitBuf();
        std::string ToString();
        git_buf m_Handle;
    };
}



#endif //GITCPP_GITBUF_H
