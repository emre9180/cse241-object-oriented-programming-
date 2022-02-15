/* Emre YILMAZ - 1901042606 - Gebze Technical University - @emre9180*/
#include "vector.h"
#include <memory>

using namespace std;
namespace GTU
{
    template <class T>
    inline shared_ptr<T> GTUVector<T>::getPtr() const {return ptr;}

    template <class T>
    GTUVector<T>::GTUVector()
    {   
        counter = 0;
        ptr = NULL; 
    }

    template <class T>
    GTUVector<T>::~GTUVector() {}

    template <class T>
    GTUVector<T>::GTUVector(GTUVector<T>&& src) : ptr(src.getPtr())
    {}

    template <class T>
    GTUVector<T>::GTUVector(GTUVector<T>& src) : ptr(src.getPtr())
    {}

    template <class T>
    GTUVector<T>& GTUVector<T>::operator=(GTUVector<T>&& other)
    {ptr = other.ptr;}

    template <class T>
    GTUVector<T>& GTUVector<T>::operator=(GTUVector<T>& other)
    {ptr = other.ptr;}

    template <class T>
    GTUVector<T>::GTUVector(int i) {push_back(i);}

    template <class T>
    bool GTUVector<T>::search(GTUIterator<T> target) const
    {
        GTUIterator<T> iter(ptr);
        while(iter!=end())
        {
            if(iter==target) return true;
            ++iter;
        }
        return false;
    }

    template <class T>
    GTUIterator<T> GTUVector<T>::begin() const
    {
        GTUIterator<T> iter(getPtr());
        return iter;
    }

    template <class T>
    GTUIteratorConst<T> GTUVector<T>::cbegin() const
    {
        GTUIteratorConst<T> iter(getPtr());
        return iter;
    }

    template <class T>
    GTUIterator<T> GTUVector<T>::end() const
    {   
        GTUIterator<T> iter(begin());
        int ct = 0;

        while(ct!=counter)
        {
            ++iter;
            ++ct;
        }
        return iter;
    }

    template <class T>
    GTUIteratorConst<T> GTUVector<T>::cend() const
    {
        GTUIteratorConst<T> iter(ptr);

        if(empty()) return iter;

        iter = ptr;

        while(iter.getPtr()!=NULL)
            ++iter;

        return iter;
    }

    template <class T>
    bool GTUVector<T>::empty() const
    {
        GTUIteratorConst<T> iter(ptr);
        if(iter.getPtr()==NULL) return true;
        else return false;
    }

    template <class T>
    int GTUVector<T>::size() const
    {
        return counter;
    }

    template <class T>
    bool GTUVector<T>::erase(GTUIterator<T>& target)
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

        if(!search(target))
        {
            GTUIterator<T> temp(ptr);
            delete [] temp.getPtr();
            ptr=newPtr;
            --counter;
            return true;
        }

        else
        {
            GTUIterator<T> temp(newPtr);
            delete [] temp.getPtr();
            return false;
        }

        
    }

    template <class T>
    void GTUVector<T>::clear()
    {
        shared_ptr<T> newPtr;
        ptr = newPtr;
    }

    template <class T>
    T& GTUVector<T>::operator[](int index)
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

    template <class T>
    T& GTUVector<T>::at(int index)
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

    template <class T>
    void GTUVector<T>::push_back(T element)
    {
        shared_ptr<T> newPtr(new T[size()+1]); // Create the new shared ptr vector

        // Create the iterators
        GTUIterator<T> iter(begin());
        GTUIterator<T> temp(begin());
        GTUIterator<T> iterNew(newPtr);

        // Add the elements to new vector
        while(iter!=this->end())
        {
            *(iterNew) = *iter;
            ++iterNew;
            ++iter;
        }

        // Add the new element to the new vector
        *iterNew = element;
        ptr = newPtr;
        GTUIterator<T> iter2(begin());
        ++iter2;
        ++counter;
        return;
    }

    template <class T>
    void GTUVector<T>::pop_back()
    {
        int ct = 0;

        // If we are deleting only one element
        if(size()==1)
        {
            shared_ptr<T> emptyPtr;
            GTUIterator<T> temp(begin());
            cout << *temp;
            ptr = emptyPtr;
            --counter;
            return;
        }
        
        shared_ptr<T> newPtr(new T[size()-1]); // Create the new shared ptr vector 

        //Initiliaze the iterators
        GTUIterator<T> iter(begin());
        GTUIterator<T> temp(begin());
        GTUIterator<T> newIter(newPtr);

        // Adds the elements to the new vector 
        while(ct<size()-1)
        {
            *newIter = *iter;
            ++newIter;
            ++iter;
            ++ct;
        }
        --counter;
        ptr = newPtr;
    }
}
