/* Emre YILMAZ - 1901042606 - Gebze Technical University - @emre9180*/
#include "gtuarray.h"
#include <memory>

using namespace std;

namespace GTU
{
    template <class T, int Size>
GTUArray<T,Size>::GTUArray()
{   
    ptr = NULL;
    shared_ptr<T> newPtr(new T[Size]);
    ptr = newPtr; 
}

template <class T, int Size>
GTUArray<T,Size>& GTUArray<T,Size>::operator=(GTUArray<T,Size>& other)
{ptr = other.ptr;
return *this;}

template <class T, int Size>
GTUArray<T,Size>& GTUArray<T,Size>::operator=(GTUArray<T,Size>&& other)
{ptr = other.ptr;
return *this;}

template <class T, int Size>
GTUArray<T,Size>::~GTUArray() {}

template <class T, int Size>
GTUArray<T,Size>::GTUArray(GTUArray<T,Size>&& src) : ptr(src.getPtr())
{}

template <class T, int Size>
void GTUArray<T,Size>::setPtr(shared_ptr<T>& newPtr) {getPtr() = newPtr;}

template <class T, int Size>
inline shared_ptr<T> GTUArray<T,Size>::getPtr() const {return ptr;}


template <class T, int Size>
GTUIterator<T> GTUArray<T,Size>::begin() const
{
    GTUIterator<T> iter(getPtr());
    return iter;
}

template <class T, int Size>
GTUIteratorConst<T> GTUArray<T,Size>::cbegin() const
{
    GTUIteratorConst<T> iter(getPtr());
    return iter;
}

template <class T, int Size>
GTUIterator<T> GTUArray<T,Size>::end() const
{   
    GTUIterator<T> iter(begin());
    int ct = 0;
    while(ct!=Size)
    {
        ++iter;
        ++ct;
    }
    return iter;
}

template <class T, int Size>
GTUIteratorConst<T> GTUArray<T,Size>::cend() const
{
    GTUIteratorConst<T> iter(cbegin());
    int ct = 0;
    while(ct!=Size)
    {
        ++iter;
        ++ct;
    }
    return iter;
}

template <class T, int Size>
bool GTUArray<T,Size>::empty() const
{
    GTUIteratorConst<T> iter(ptr);
    if(iter.getPtr()==NULL) return true;
    else return false;
}

template <class T, int Size>
bool GTUArray<T, Size>::search(T target) const
{
    GTUIterator<T> iter(begin());
    while(iter!=end())
    {
        if(*iter==target) return true;
        ++iter;
    }
    return false;
}

template <class T, int Size>
int GTUArray<T,Size>::size() const
{
    return Size;
}

template <class T, int Size>
bool GTUArray<T,Size>::erase(GTUIterator<T>& target)
{   
    int ct = 0;
    shared_ptr<T> newPtr(new T[size()-1]);
    GTUIterator<T> iterNewptr(newPtr);

    GTUIterator<T> iter(ptr);
    while(iter!=end())
    {
        if(iter!=target) *(iterNewptr) = *iter;
        ++iter;
    }

        if(!search(*target))
        {
            GTUIterator<T> temp(ptr);
        delete [] temp.getPtr();
        ptr=newPtr;
        return true;
        }

    else
    {
        GTUIterator<T> temp(newPtr);
        delete [] temp.getPtr();
        return false;
    }
}

template <class T, int Size>
void GTUArray<T,Size>::clear()
{
    GTUIterator<T> temp(ptr);
    delete [] temp.getPtr();
}


 template <class T, int Size>
    T& GTUArray<T,Size>::operator[](int index)
    {   
        GTUIterator<T> iter(ptr);
        int ct = 0;

        if(index>size())
        {
            cerr << "Out of range!\n";
            return *iter;
        }

        
        while(iter.getPtr()!=NULL)
        {
            if(ct==index) return *iter;
            ++iter;
            ++ct;
        }

        return *iter;
    }

    template <class T, int Size>
    T& GTUArray<T,Size>::at(int index)
    {
        int ct = 0;
        GTUIterator<T> iter(ptr);

         if(index>size())
        {
            cerr << "Out of range!\n";
            return *iter;
        }

        
        while(iter!=end())
        {
            if(ct==index) return *iter;
            ++iter;
            ++ct;
        }

        return *iter;
    }

}
