/* Emre YILMAZ - 1901042606 - Gebze Technical University - @emre9180*/
#ifndef GTUARRAY_H
#define GTUARRAY_H
#include <memory>
#include <iostream>

namespace GTU
{
    template <class T, int Size>
    class GTUArray: public Iterable<T>
    {
        public:
            GTUArray();
            ~GTUArray();
            GTUArray(GTUArray<T,Size>&& src);


            virtual bool empty() const; // Checks that the set is empty or not
            virtual int size() const; // Returns the size of the set
            virtual bool erase(GTUIterator<T>& iter); // Erase the element that the iterator in the parameter points 
            virtual void clear(); // Clears all the content of the array
            virtual GTUIterator<T> begin() const; // Returns the iterator that points the first element
            virtual GTUIterator<T> end() const; // Returns the iterator that points the end
            virtual GTUIteratorConst<T> cbegin() const; // Returns the constant iterator that points the first element
            virtual GTUIteratorConst<T> cend() const; // Returns the constant iterator that points the end
            
            T& operator[](int index);
            T& at(int index);
            bool search(T target) const; /* Search the target iterator in the vector */
            GTUArray& operator=(GTUArray<T,Size>&& other);
            GTUArray& operator=(GTUArray<T,Size>& other);

            void setPtr(shared_ptr<T>& newPtr);
            shared_ptr<T> getPtr() const;

            private:
                shared_ptr<T> ptr;
                int counter;
    };
}   


#endif