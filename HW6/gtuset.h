/* Emre YILMAZ - 1901042606 - Gebze Technical University - @emre9180*/
#ifndef GTUSET_H
#define GTUSET_H
#include <memory>

namespace GTU
{
    template <class T>
    class GTUSet: public Iterable<T>
    {
        public:
            GTUSet();
            ~GTUSet();
            GTUSet(const GTUSet<T>&& src);
            GTUSet(const GTUSet<T>& src);

            virtual bool empty() const; // Checks that the set is empty or not
            virtual int size() const; // Returns the size of the set
            virtual bool erase(GTUIterator<T>& iter); // Erase the element that the iterator in the parameter points 
            virtual void clear(); // Clears all the content of the array
            virtual GTUIterator<T> begin() const; // Returns the iterator that points the first element
            virtual GTUIterator<T> end() const; // Returns the iterator that points the end
            virtual GTUIteratorConst<T> cbegin() const; // Returns the constant iterator that points the first element
            virtual GTUIteratorConst<T> cend() const; // Returns the constant iterator that points the end
            
            bool search(T target) const; // Search for an element and returns true if it finds it
            template <typename U> friend const GTUSet<U> operator+(const GTUSet<U>& object1, const GTUSet<U>& object2); // Creates and return union set
            template <typename U> friend const GTUSet<U> operator-(const GTUSet<U>& object1, const GTUSet<U>& object2); // Creates and return intersection set
            void add(T element); // Adds the new element to the set
            void remove(T element); // Removes the element in the parameter from the set
            GTUSet& operator=(GTUSet<T>&& other);
            GTUSet& operator=(const GTUSet<T>& other);

            void setPtr(shared_ptr<T>& newPtr);
            shared_ptr<T> getPtr() const;

            private:
                shared_ptr<T> ptr;
                int counter;
    };
}


#endif