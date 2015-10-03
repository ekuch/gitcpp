//
// Created by ekuch on 10/2/15.
//

#ifndef GITCPP_IITERATOR_H
#define GITCPP_IITERATOR_H

#include <memory>

namespace gitcpp {
    template<typename T>
    class IIterator {
    public:
        virtual ~IIterator() = 0;
        std::shared_ptr<T> Next();
    protected:
        virtual IIterator() {}
    };
};

#endif //GITCPP_IITERATOR_H
