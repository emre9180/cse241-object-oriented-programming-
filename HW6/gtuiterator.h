/* Emre YILMAZ - 1901042606 - Gebze Technical University - @emre9180*/
#ifndef GTUITERATOR_H
#define GTUITERATOR_H
#include <memory>
using namespace std;

namespace GTU
{
    template <class T>
    class GTUIteratorConst
    {
        public:
            GTUIteratorConst();
            GTUIteratorConst(const GTUIteratorConst<T>& object);
            GTUIteratorConst(const GTUIteratorConst<T>&& object);
            GTUIteratorConst(shared_ptr<T> ptr);
            ~GTUIteratorConst();
            T& operator*();
            T& operator->();
            void operator++();
            void operator--();
            template<typename U> friend bool operator==(const GTUIteratorConst<U>& obj1, const GTUIteratorConst<U>& obj2);
            template<typename U> friend bool operator!=(const GTUIteratorConst<U>& obj1, const GTUIteratorConst<U>& obj2);
            GTUIteratorConst<T>& operator=(GTUIteratorConst<T>&& other);
            GTUIteratorConst<T>& operator=(GTUIteratorConst<T>& other);
    

            const T* getPtr();
            bool empty();

        private:
            const T* ptr;
    };

    template<class T>
    class GTUIterator
    {
        public:
            GTUIterator(const GTUIterator<T>& object);
            GTUIterator(const GTUIterator<T>&& object);
            GTUIterator();
            GTUIterator(shared_ptr<T> ptr);
            ~GTUIterator();
            T& operator*();
            T& operator->();
            void operator++();
            void operator--();
            GTUIterator<T>& operator=(const GTUIterator<T>& rightSide);

            template<typename U> friend bool operator==(const GTUIterator<U>& obj1, const GTUIterator<U>& obj2);
            template<typename U> friend bool operator!=(const GTUIterator<U>& obj1, const GTUIterator<U>& obj2);
            GTUIterator<T>& operator=(GTUIterator<T>&& other);
            GTUIterator<T>& operator=(GTUIterator<T>& other);

            T* getPtr();
            bool empty();

        private:
            T* ptr;
    };
}


#endif