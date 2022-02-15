/* Emre YILMAZ - 1901042606 - Gebze Technical University - @emre9180*/
/* NOTE FOR T.A. Base Class pure functions is used all the implementations. */

#include "gtuiterator.h"
#include "iterable.h"
#include "vector.h"
#include "gtuarray.h"
#include "gtuset.h"

#include "iterable.cpp"
#include "gtuarray.cpp"
#include "gtuset.cpp"
#include "vector.cpp"



#include <memory>
#include <iostream>

using namespace std;
using namespace GTU;

int main()
{   

    // *************************************     ************** ************* TESTING VECTOR CLASS ************* ************** ************************************* 
    cout << "************************************************************** TESTING VECTOR CLASS **************************************************************\n\n";

    GTUVector<int> vec; // Create a vector 

    try 
    {
        if(vec.empty()) cout << "\nempty() function says that the vector is empty yet!\n"; // Throw an exception when a problem arise
    }
    catch (...) {
        cout << "Caught an exception!\n";
    }
    

    cout << "Adding some eleements to the vector...\n";
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(7);
    vec.push_back(4);
    vec.push_back(1);
    cout << "\nSize of the vector: " << vec.size() << endl; // Print the size of the vector

    // Print the all elements of the vector 
    cout << "\nElements of the vector:\n\n";
    int ct = 0;
    for (auto i : vec)
    {
        std::cout << ct << ". element of the vector " << i << endl;
        ++ct;
    }
    cout << endl;

    // Delete the last 2 element
    cout << "\nRemoving some elements from the vector...\n\n";
    vec.pop_back();
    vec.pop_back();

    // Print the all elements of the vector
    cout << "\nElements of the vector:\n\n";
    ct = 0;
    for (auto i : vec)
    {
        std::cout << ct << ". element of the vector " << i << endl;
        ++ct;
    }

    GTUIterator<int> iter = vec.begin();
    cout << "\n\nFirst element of the vector is: " << *iter << endl;
    cout << "(using at function) Second element of the vector is: " << vec.at(1) << endl;
    cout << "(using [] operator) Third element of the vector is: " << vec[2] << endl;
    ++iter;
    cout << "(using iterator) Third element of the vector is: " << *iter << endl;

    vec.clear();
    cout << "\n\nAll the elements of the vector is cleared successfuly!\n";

    // *************************************     ************** ************* TESTING SET CLASS ************* ************** *************************************
    cout << "\n\n\n************************************************************** TESTING SET CLASS **************************************************************\n\n";

    GTUSet<int> set;
    GTUSet<int> set2;
    GTUSet<int> set3;

    if(set.empty()) "empty() function says that the set-1 is empty yet!\n";
    if(set2.empty()) "empty() function says that the set-2 is empty yet!\n";
    if(set3.empty()) "empty() function says that the set-3 is empty yet!\n\n";

    // Add some elements to set-1
    cout << "Adding some elements to the set-1...\n";
    set.add(1);
    set.add(5);
    set.add(6);
    set.add(0);

    // Add some elements to set-2
    cout << "Adding some elements to the set-2...\n";
    set2.add(2);
    set2.add(7);
    set2.add(9);

    // Add some elements to set-3
    cout << "Adding some elements to the set-3...\n\n";
    set3.add(6);
    set3.add(9);
    set3.add(1);
    set3.add(0);

    cout << "The element number of the set-1 is: " << set.size() << endl;
    cout << "The element number of the set-2 is: " << set2.size() << endl;
    cout << "The element number of the set-3 is: " << set3.size() << endl << endl;

    // Print the all elements of the vector
    cout << "Elements of the set-1: { ";
    for (auto i : set)
    {
       cout << i << ", ";
        ++ct;
    }
    cout << "}\n";

    // Print the all elements of the vector
    cout << "Elements of the set-2: { ";
    for (auto i : set2)
    {
       cout << i << ", ";
        ++ct;
    }
    cout << "}\n";

    // Print the all elements of the vector
    cout << "Elements of the set-3: { ";
    for (auto i : set3)
    {
       cout << i << ", ";
        ++ct;
    }
    cout << "}\n";

     // Print the all elements of the vector
    cout << "\nElements of the set-1: { ";
    for (auto i : set)
    {
       cout << i << ", ";
        ++ct;
    }
    cout << "}\n";


    GTUSet<int> intersect = (set - set3);
    cout << "\nThe intersection set of set1 and set3 is calculating...\n";
    cout << "Size of the intersection set of set1 and set3 is: " << intersect.size() << endl;

    // Print the all elements of the vector
    cout << "\nElements of the intersection set of set and set3: { ";
    for (auto i : intersect)
    {
       cout << i << ", ";
        ++ct;
    }
    cout << "}\n\n";

    GTUSet<int> unionSet = set + set2;
    
    cout << "The union set of set1 and set2 is calculating...\n";
    cout << "Size of the union set of set1 and set2 is: " << unionSet.size() << endl;

    // Print the all elements of the vector
    cout << "Elements of the union set of set and set2: { ";
    for (auto i : unionSet)
    {
       cout << i << ", ";
        ++ct;
    }
    cout << "}\n";

    cout << "\nRemoving an element from set-1...\n";
    set.remove(5);

    // Print the all elements of the vector
    cout << "Elements of the set-1: { ";
    for (auto i : set)
    {
       cout << i << ", ";
        ++ct;
    }
    cout << "}\n";



    // *************************************     ************** ************* TESTING ARRAY CLASS ************* ************** *************************************
    cout << "\n\n\n************************************************************** TESTING ARRAY CLASS **************************************************************\n\n";

    GTUArray<int,10> arr;

    // Print the size of the array 
    try 
    {
        cout << "The size of the array is: " << arr.size() << endl;
    }
    catch (...) {
        cout << "Caught an exception!\n";
    }
    

    // Fill the array
    cout << "\nFilling the array...\n";
    for(int i = 0;i<10;i++)
        arr[i]=i*10;

    // Print the all elements of the array
    cout << "\nElements of the array:\n\n";
    ct = 0;
    for (auto i : arr)
    {
        std::cout << ct << ". element of the array " << i << endl;
        ++ct;
    }
    cout << endl;

    // Create a new array
    cout << "\nCreating and filling a new array...\n";
    GTUArray<int,10> arr2;

    // Fill the new array
    for(int i = 0;i<10;i++)
        arr2[i]=i*5;

    // Use the assignment operator
    cout << "\nThe new array is assigned to old one.\n";
    arr = arr2;

    // Print the all elements of the array
    cout << "\nElements of the new array:\n\n";
    ct = 0;
    for (auto i : arr)
    {
        std::cout << ct << ". element of the array " << i << endl;
        ++ct;
    }
    cout << endl;



    

    
    

}