/* Emre YILMAZ - 1901042606 - Gebze Technical University - @emre9180*/
#include "gtuset.h"
#include <memory>

using namespace std;

namespace GTU
{
        // NO-parameter constructor
    template <class T>
    GTUSet<T>::GTUSet()
    {   
        counter = 0;
        ptr = NULL;
    }

    // Destructor
    template <class T>
    GTUSet<T>::~GTUSet() {}

    // Move assignment operator overloading
    template <class T>
    GTUSet<T>& GTUSet<T>::operator=(GTUSet<T>&& other)
    {ptr = other.ptr;
    return *this;}

    // Assignment operator overloading
    template <class T>
    GTUSet<T>& GTUSet<T>::operator=(const GTUSet<T>& other)
    {ptr = other.ptr;
    return *this;}

    // Move semantic copy constructor 
    template <class T>
    GTUSet<T>::GTUSet(const GTUSet<T>&& src) : ptr(src.ptr)
    {}

    // Copy constructor
    template <class T>
    GTUSet<T>::GTUSet(const GTUSet<T>& src) : ptr(src.ptr)
    {}



    template <class T>
    void GTUSet<T>::setPtr(shared_ptr<T>& newPtr) {getPtr() = newPtr;}

    template <class T>
    inline shared_ptr<T> GTUSet<T>::getPtr() const {return ptr;}

    // Adds the new element to the set
    template <class T>
    void GTUSet<T>::add(T element)
    {
        if(search(element)) return;
        if(size()==0)
        {
            shared_ptr<T> newPtr(new T[1]);
            GTUIterator<T> iterNew(newPtr);
            *iterNew = element;
            ptr = newPtr;
            ++counter;
            return;
        }

        shared_ptr<T> newPtr(new T[size()+1]);

        GTUIterator<T> iter(begin());
        GTUIterator<T> temp(begin());
        GTUIterator<T> iterNew(newPtr);

        int ct = 0;
        bool addFlag = true;
        while(ct<counter+1)
        {
            if(*iter<element && addFlag == true)
            {
                *iterNew = element;
                ++iterNew;
                ++ct;
                addFlag = false;
            }

            else
            {
                *(iterNew) = *iter;
                ++iterNew;
                ++iter;
                ++ct;
            }
        }

        ptr = newPtr;
        GTUIterator<T> iter2(begin());
        ++iter2;
        ++counter;
        
        return;
    }

    // Removes the element in the parameter from the set
    template <class T>
    void GTUSet<T>::remove(T element)
    {
        int ct = 0;

        if(size()==1)
        {
            shared_ptr<T> emptyPtr;
            GTUIterator<T> temp(begin());
            cout << *temp;
            ptr = emptyPtr;
            --counter;
            return;
        }
        
        shared_ptr<T> newPtr(new T[size()-1]);
        GTUIterator<T> iter(begin());
        GTUIterator<T> temp(begin());
        GTUIterator<T> newIter(newPtr);

        while(ct<size()-1)
        {
            if(*iter==element)
                ++iter;
            else
            {
                *newIter = *iter;
                ++newIter;
                ++iter;
                ++ct;
            }
        }
        --counter;
        ptr = newPtr;
    }

    // Creates and returns union set
    template <class T>
    const GTUSet<T> operator+(const GTUSet<T>& object1, const GTUSet<T>& object2)
    {
        GTUSet<T> newObject;
        GTUIterator<T> iter1 = object1.begin();
        GTUIterator<T> iter2 = object2.begin();
        
        int ct = 0;
        while(ct<object1.size())
        {
            newObject.add(*iter1);
            ++iter1;
            ++ct;
        }

        int i = 0;
        while(i<object2.size())
        {   
            iter1 = newObject.begin();
            bool unique = true;
            ct=0;
            while(ct<newObject.size())
            {
                if(*iter2==*iter1)
                    unique = false;
                ++ct;
            }

            if(unique==true)
                newObject.add(*iter2);
            ++iter2;
            ++i;
        }

        return newObject;
    }

    // Creates and return intersection set
    template <class T>
    const GTUSet<T> operator-(const GTUSet<T>& object1, const GTUSet<T>& object2)
    {
        GTUSet<T> newObject;
        GTUIterator<T> iter1 = object1.begin();
        GTUIterator<T> iter2 = object2.begin();
        
        int ct = 0;
        int i = 0;
        while(i<object1.size())
        {   
            iter2 = object2.begin();
            bool unique = true;
            ct=0;
            while(ct<object2.size())
            {
                if(*iter2==*iter1)
                    unique = false;
                ++ct;
                ++iter2;
            }

            if(unique==true)
                newObject.add(*iter1);

            ++iter1;
            ++i;
        }

        return newObject;
    }

    // Search for an element and returns true if it finds it
    template <class T>
    bool GTUSet<T>::search(T target) const
    {
        GTUIterator<T> iter(begin());
        while(iter!=end())
        {
            if(*iter==target) return true;
            ++iter;
        }
        return false;
    }

    // Returns the iterator that points the first element
    template <class T>
    GTUIterator<T> GTUSet<T>::begin() const
    {
        GTUIterator<T> iter(getPtr());
        return iter;
    }

    // Returns the constant iterator that points the first element
    template <class T>
    GTUIteratorConst<T> GTUSet<T>::cbegin() const
    {
        GTUIteratorConst<T> iter(getPtr());
        return iter;
    }

    // Returns the iterator that points the end
    template <class T>
    GTUIterator<T> GTUSet<T>::end() const
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

    // Returns the constant iterator that points the end
    template <class T>
    GTUIteratorConst<T> GTUSet<T>::cend() const
    {
        GTUIteratorConst<T> iter(cbegin());
        int ct = 0;
        while(ct!=counter)
        {
            ++iter;
            ++ct;
        }
        return iter;
    }

    // Checks that the set is empty or not
    template <class T>
    bool GTUSet<T>::empty() const
    {
        GTUIteratorConst<T> iter(ptr);
        if(iter.getPtr()==NULL) return true;
        else return false;
    }

    // Returns the size of the set
    template <class T>
    int GTUSet<T>::size() const
    {
        return counter;
    }

// Erase the element that the iterator in the parameter points 
    template <class T>
    bool GTUSet<T>::erase(GTUIterator<T>& target)
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

    // Clears all the content of the array
    template <class T>
    void GTUSet<T>::clear()
    {
        GTUIterator<T> temp(ptr);
        delete [] temp.getPtr();
    }
}
