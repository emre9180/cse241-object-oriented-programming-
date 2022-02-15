/* Emre YILMAZ - 1901042606 - Gebze Technical University - @emre9180*/
#ifndef VECTOR_H
#define VECTOR_H
#include <memory>

namespace GTU
{
    template <class T>
    class GTUVector : public Iterable<T>
    {
        public:
            GTUVector();
            ~GTUVector();
            GTUVector(int i);
            GTUVector(GTUVector<T>&& src);
            GTUVector(GTUVector<T>& src);

            virtual bool empty() const;  // Checks that the set is empty or not
            virtual int size() const; // Returns the size of the set
            virtual bool erase(GTUIterator<T>& iter); // Erase the element that the iterator in the parameter points 
            virtual void clear(); // Clears all the content of the array
            virtual GTUIterator<T> begin() const; // Returns the iterator that points the first element
            virtual GTUIterator<T> end() const; // Returns the iterator that points the end
            virtual GTUIteratorConst<T> cbegin() const; // Returns the constant iterator that points the first element
            virtual GTUIteratorConst<T> cend() const; // Returns the constant iterator that points the end

            bool search(GTUIterator<T> target) const; /* Search the target iterator in the vector */
            T& operator[](int index);
            T& at(int index);
            void push_back(T element); // Adds an element to the vector
            void pop_back(); // Removes an element from the vector
            GTUVector& operator=(GTUVector<T>&& other);
            GTUVector& operator=(GTUVector<T>& other);

            void setPtr(shared_ptr<T>& newPtr);

            shared_ptr<T> getPtr() const;

            private:
                shared_ptr<T> ptr;
                int counter;
    };
}
    

#endif