/* Emre YILMAZ - 1901042606 - Gebze Technical University */

#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

namespace doys
{
    class  DayOfYearSet
    {
        public:

            class DayOfYear
            {
                public:
                    DayOfYear(); /* No-parameter contructor, will initiliaze the variables as 1th January */
                    DayOfYear(int day, int month); /* Constructor that will initiliaze the variables as parameters */
                    DayOfYear(DayOfYear* object); /* Copy constructor */
                    int getDay() const; /* Getter function for accessing to day variable */
                    int getMonth() const; /* Getter function for accessing to month variable */
                    void setDay(int dayInput); /* Setter function to change day variable */
                    void setMonth(int monthInput); /* Setter function to change month variable */
                    bool operator==(DayOfYear &obj1); /* == Operator Overloading */
                    bool operator!=(DayOfYear &obj1); /* != Operator Overloading */
                    DayOfYear& operator=(const DayOfYear& rightSide); /* Assignment Operator Overloading */
                    friend ostream& operator <<(ostream& outputStream, const DayOfYearSet::DayOfYear& object1);
                    static int totalObjects;
                    inline static int getTotalObjects(){return DayOfYearSet::DayOfYear::totalObjects;};
                    static void setTotalObjects(int change);

                private:
                    int month;
                    int day;

            };

            DayOfYearSet(vector <DayOfYear> doyVec); /* Constructor that takes a vector of DayOfYear objects. */
            DayOfYearSet(DayOfYear* PdoyArr, int size); /* Constructor that takes a dynamic array of DayOfYear objects. */
            DayOfYearSet();
            ~DayOfYearSet(); /* Destructor */
            DayOfYearSet(const DayOfYearSet& Object); /* Copy contructor */
            DayOfYear* getArray() const;
            int getSize() const; /* Getter function to access the variable that keeps the size of array */
            void setSize(int set); /* Setter function to change the variable that keeps the size of array */
            bool add(DayOfYear& addDoy); /* Adds an element to the set. If there is a duplicate, return false. */
            bool remove(DayOfYear& removeDoy); /* Removes an element from the set. If there is no match with the element in the parameter, return false */
            //static int getTotalObjects();
            

            DayOfYearSet& operator=(const DayOfYearSet& rtSide); /* Overloading assignment operator */
            friend ostream& operator <<(ostream& outputStream, const DayOfYearSet& object1);
            friend bool operator==(const DayOfYearSet& object1, const DayOfYearSet& object2);
            friend bool operator!=(const DayOfYearSet& object1, const DayOfYearSet& object2);
            friend const DayOfYearSet operator+(const DayOfYearSet& object1, const DayOfYearSet& object2);
            friend const DayOfYearSet operator-(const DayOfYearSet& object1, const DayOfYearSet& object2);
            friend const DayOfYearSet operator^(const DayOfYearSet& object1, const DayOfYearSet& object2);
            friend const DayOfYearSet operator!(const DayOfYearSet& object1);
            const DayOfYearSet::DayOfYear operator[](int size);
            static void saveFile(fstream& file, DayOfYearSet& object); /* Save the object to txt file */

        private:
            DayOfYear* doyArr; /* */
            int arraySize;
            
    };
}
