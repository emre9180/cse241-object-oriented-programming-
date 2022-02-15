/* Emre YILMAZ - 1901042606 - Gebze Technical University - @emre9180*/
#ifndef ITERABLE_H
#define ITERABLE_H
#include <memory>
#include "gtuiterator.cpp"
using namespace std;

namespace GTU
{
    template <class T>
    class Iterable
    {
        public:
            Iterable();
            ~Iterable();
            virtual bool empty() const = 0;
            virtual int size() const = 0;
            virtual bool erase(GTUIterator<T>& iter) = 0;
            virtual void clear() = 0;
            virtual GTUIterator<T> begin() const = 0;
            virtual GTUIterator<T> end() const = 0;
            virtual GTUIteratorConst<T> cbegin() const = 0;
            virtual GTUIteratorConst<T> cend() const = 0;
    };
}

#endif