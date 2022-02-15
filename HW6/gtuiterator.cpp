/* Emre YILMAZ - 1901042606 - Gebze Technical University - @emre9180*/
#include "gtuiterator.h"
#include <memory>

using namespace std;

namespace GTU
{
    template <class T>
    GTUIteratorConst<T>::GTUIteratorConst(const GTUIteratorConst<T>& object)
    {
        ptr = object.ptr;
    }

    template <class T>
    GTUIterator<T>::GTUIterator(const GTUIterator<T>&& object)
    {
        ptr = object.ptr;
    }

    template <class T>
    GTUIterator<T>::GTUIterator(const GTUIterator<T>& object)
    {
        ptr = object.ptr;
    }

    template <class T>
    GTUIteratorConst<T>::GTUIteratorConst(const GTUIteratorConst<T>&& object)
    {
        ptr = object.ptr;
    }

    template <class T>
    GTUIteratorConst<T>::GTUIteratorConst(){}

    template <class T>
    GTUIteratorConst<T>::~GTUIteratorConst(){}

    template <class T>
    GTUIteratorConst<T>::GTUIteratorConst(shared_ptr<T> ptrInput)
    {
        ptr = ptrInput.get();
    }

    template <class T>
    bool GTUIteratorConst<T>::empty()
    {
        if(ptr==NULL) return true;
        else return false;
    }

    template <class T>
    inline const T* GTUIteratorConst<T>::getPtr(){return ptr;}

    template <class T>
    inline T& GTUIteratorConst<T>::operator*(){return *ptr;}

    template <class T>
    inline T& GTUIteratorConst<T>::operator->(){return *ptr;}

    template <class T>
    void GTUIteratorConst<T>::operator++(){ptr = (ptr+1);}

    template <class T>
    void GTUIteratorConst<T>::operator--(){ptr = (ptr-1);}

    template <class U>
    bool operator==(const GTUIteratorConst<U>& obj1, const GTUIteratorConst<U>& obj2)
    {
        if(obj1.ptr == obj2.ptr) return true;
        else return false;
    }

    template <class U>
    bool operator!=(const GTUIteratorConst<U>& obj1, const GTUIteratorConst<U>& obj2)
    {
        if(obj1.ptr == obj2.ptr) return false;
        else return true;
    }

    template <class T>
    GTUIterator<T>& GTUIterator<T>::operator=(GTUIterator<T>&& other)
    {ptr = other.ptr;
    return *this;}

    template <class T>
    GTUIterator<T>& GTUIterator<T>::operator=(GTUIterator<T>& other)
    {ptr = other.ptr;
    return *this;}

    template <class T>
    GTUIteratorConst<T>& GTUIteratorConst<T>::operator=(GTUIteratorConst<T>&& other)
    {ptr = other.ptr;
    return *this;
    }

    template <class T>
    GTUIteratorConst<T>& GTUIteratorConst<T>::operator=(GTUIteratorConst<T>& other)
    {ptr = other.ptr;
    return *this;
    }


    template <class T>
    GTUIterator<T>::GTUIterator(){}

    template <class T>
    GTUIterator<T>::~GTUIterator(){}

    template <class T>
    GTUIterator<T>::GTUIterator(shared_ptr<T> ptrInput)
    {
        ptr = ptrInput.get();
    }

    template <class T>
    bool GTUIterator<T>::empty()
    {
        if(ptr==NULL) return true;
        else return false;
    }

    template <class T>
    inline T* GTUIterator<T>::getPtr(){return ptr;}

    template <class T>
    inline T& GTUIterator<T>::operator*(){return *ptr;}

    template <class T>
    inline T& GTUIterator<T>::operator->(){return *ptr;}

    template <class T>
    void GTUIterator<T>::operator++(){ptr= (ptr+1);}

    template <class T>
    void GTUIterator<T>::operator--(){ptr = (ptr-1);}

    template <class U>
    bool operator==(const GTUIterator<U>& obj1, const GTUIterator<U>& obj2)
    {
        if(obj1.ptr == obj2.ptr) return true;
        else return false;
    }

    template <class U>
    bool operator!=(const GTUIterator<U>& obj1, const GTUIterator<U>& obj2)
    {
        if(obj1.ptr == obj2.ptr) return false;
        else return true;
    }

}
