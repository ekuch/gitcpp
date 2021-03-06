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
        virtual std::shared_ptr<T> Next() = 0;
    protected:
        IIterator() {}
    };
    template <typename T>
    IIterator<T>::~IIterator() { }
};

#endif //GITCPP_IITERATOR_H
