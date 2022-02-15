/* Emre YILMAZ - 1901042606 - Gebze Technical University */

#include <iostream>
#include <vector>
#include <string>
#include "hw4_lib.h"
#include <fstream>

using namespace std;

namespace doys
{
        /* ----------------------------- Inner class (DayOfYear class) function implementations ----------------------------- */

    DayOfYearSet::DayOfYear::DayOfYear() : day(1), month(1)
    {DayOfYearSet::DayOfYear::setTotalObjects(1);}
    DayOfYearSet::DayOfYear::DayOfYear(int dayInput, int monthInput) : day(dayInput), month(monthInput)
    {DayOfYearSet::DayOfYear::setTotalObjects(1);}
    DayOfYearSet::DayOfYear&  DayOfYearSet::DayOfYear::operator=(const DayOfYear& rightSide)
    {
        this->day = rightSide.day;
        this->month = rightSide.month;
        return *this;
    }
    void DayOfYearSet::DayOfYear::setDay(int dayInput)
    {
        setDay(dayInput);
    }

    void DayOfYearSet::DayOfYear::setMonth(int monthInput)
    {
        setMonth(monthInput);
    }

    inline int DayOfYearSet::DayOfYear::getDay() const{return day;};
    inline int DayOfYearSet::DayOfYear::getMonth() const{return month;};

    bool DayOfYearSet::DayOfYear::operator==(DayOfYearSet::DayOfYear &obj1)
    {
        if((this->getMonth()==obj1.getMonth()) && (this->getDay()==obj1.getDay())) return true;
        else return false;
    }

    bool DayOfYearSet::DayOfYear::operator!=(DayOfYearSet::DayOfYear &obj1)
    {
        if(*this==obj1) return false;
        else return true;
    }

    ostream& operator <<(ostream& outputStream, const DayOfYearSet::DayOfYear& object1)
    {
        cout << "(Day: " << object1.getDay() << ' ';
        cout << "Month: " << object1.getMonth() << ')';
        return outputStream;
    }


    /* ----------------------------- DayOfYearSet class function implementations ----------------------------- */

    DayOfYearSet::DayOfYearSet(vector <DayOfYear> doyVec)
    {
        int size = doyVec.size();
        DayOfYear* newArr = new DayOfYear[size];
        for(int i=0;i<size;i++)
        {
            newArr[i] = doyVec.at(i);
        }
        doyArr = newArr;
        arraySize = doyVec.size();
    }
    DayOfYearSet::DayOfYearSet(DayOfYear* PdoyArr, int size)
    {
        doyArr = PdoyArr;
        arraySize = size;
    }
    DayOfYearSet::DayOfYearSet()
    {
        doyArr=nullptr;
        arraySize=0;
    }  
    DayOfYearSet::~DayOfYearSet()
    {
        delete [] doyArr;
    }
    DayOfYearSet::DayOfYearSet(const DayOfYearSet& Object)
    {
        this->arraySize = Object.getSize();
        this->doyArr = new DayOfYear[arraySize];
        for(int i = 0;i<arraySize;i++)
            this->doyArr[i] = Object.getArray()[i];
    }

    inline DayOfYearSet::DayOfYear* DayOfYearSet::getArray() const{return doyArr;};

    inline int DayOfYearSet::getSize() const{return arraySize;}
    void DayOfYearSet::setSize(int set)
    {
        arraySize += set;
    }

    bool DayOfYearSet::add(DayOfYear &addDoy)
    {
        /* Check the validity */
        if(addDoy.getMonth()<0 || addDoy.getMonth() > 12 || addDoy.getDay()<0 || addDoy.getDay()>31) return false;
        if(addDoy.getMonth()==4 || addDoy.getMonth()==6 || addDoy.getMonth()==9 || addDoy.getMonth()==11)
            if(addDoy.getDay()>30) return false;
        else if(addDoy.getMonth()==2)
            if(addDoy.getDay()>28) return false;
        /* End of checking */

        DayOfYear* memberArray = getArray();
        
        /* Check whether there are duplicates */
        bool duplicate = false;
        int sizeOfArray = getSize();

        /* If there is no element in the array */
        if(sizeOfArray==0)
        {
            DayOfYear* newArr = new DayOfYear[1];
            newArr[0] = addDoy;
            doyArr = newArr;
            setSize(1);
            return true;
        }
        
        for(int i=0;i<sizeOfArray;i++)
            if(memberArray[i]==addDoy) duplicate=true;

        if(duplicate==true) return false;

        /* Copying the old array's elements to new one. Then, make it member variable */
        DayOfYear* newArr = new DayOfYear[sizeOfArray+1];
        int i;
        for(i=0;i<sizeOfArray;i++) newArr[i] = memberArray[i];
        newArr[sizeOfArray] = addDoy;
        delete [] doyArr;
        doyArr = newArr;
        setSize(1);
        return true;
    }

    bool DayOfYearSet::remove(DayOfYear& removeDoy)
    {
        bool match = false; /* Indicates whether there is a match */
        int sizeOfArray = getSize();

        /* If there are no elements in the array yet */
        if(sizeOfArray==0) return false;
        
        for(int i=0;i<sizeOfArray;i++)
        {
            if(getArray()[i]==removeDoy)
            {
                match=true;
                break;
            }
        }
        sizeOfArray = getSize() - 1;

        if(match==false) return false; /* If there is no match, return false */

        /* Removing the element from the array. Then, make the new array member variable */
        DayOfYear* newArr = new DayOfYear[sizeOfArray];
        int i,k;
        int ct = 0;
        for(i=0;i<sizeOfArray;i++)
        {
            if(getArray()[i]!=removeDoy)
            {
                newArr[ct] = getArray()[i];
                ct++;
            }
            else continue;

        }

        delete [] doyArr;
        doyArr = newArr;
        arraySize -= 1;
        return true;
    }

    void DayOfYearSet::DayOfYear::setTotalObjects(int change)
    {
        DayOfYearSet::DayOfYear::totalObjects += change;
    }

    DayOfYearSet& DayOfYearSet::operator=(const DayOfYearSet& rtSide)
    {
        arraySize = rtSide.getSize();
        delete [] doyArr;
        doyArr = new DayOfYearSet::DayOfYear[arraySize];
        for(int i=0;i<arraySize;i++)
            getArray()[i] = rtSide.getArray()[i];
        return *this;
    }

    ostream& operator <<(ostream& outputStream, const DayOfYearSet& object1)
    {
        for(int i=0;i<object1.getSize();i++)
        {
            cout << "Array's " << i+1 << ". element:\nDay -> " << object1.getArray()[i].getDay() << endl << "Month -> " << object1.getArray()[i].getMonth() << endl << endl;
        }
        return outputStream;
    }

    const DayOfYearSet operator+(const DayOfYearSet& object1, const DayOfYearSet& object2)
    {
        auto totalSize = object1.getSize() + object2.getSize();
        int intersection = 0; /* Cardinality of intersection set */
        DayOfYearSet::DayOfYear* newArr;

        /* Determine the cardinality of the intersection set */
        for(int i=0;i<object1.getSize();i++)
        {
            for(int k=0;k<object2.getSize();k++)
            {
                if(object1.getArray()[i] == object2.getArray()[k])
                    intersection++;
            }
        }

        newArr = new DayOfYearSet::DayOfYear[totalSize-intersection]; /* Allocate memory for dynamic array for exact size*/
        int ct = 0; /* Indicates next index that will be assigned */

        /* Adds all the elements of first object to union set */
        for(int i=0;i<object1.getSize();i++)
        {
            newArr[ct] = object1.getArray()[i];
            ct++;
        }

        /* Adds all the elements of second object to union set. But before adding, it checks whether there are duplicates. If there are duplicates, that element will NOT be added to union set */
        for(int i=0;i<object2.getSize();i++)
        {
            bool flag = true;
            for(int k=0;k<object1.getSize();k++)
            {
                if(object2.getArray()[i] == object1.getArray()[k])
                {
                    flag=false;
                }
            }
            if(flag==true)
            {
                newArr[ct] = object2.getArray()[i];
                ct++;
            }
        }

        return DayOfYearSet(newArr,totalSize-intersection);
    }

    const DayOfYearSet operator-(const DayOfYearSet& object1, const DayOfYearSet& object2)
    {
        int totalSize = object1.getSize();
        int intersection = 0; /* Cardinality of intersection set */
        DayOfYearSet::DayOfYear* newArr;

        /* Determine the cardinality of the intersection set */
        for(int i=0;i<object1.getSize();i++)
        {
            for(int k=0;k<object2.getSize();k++)
            {
                if(object1.getArray()[i] == object2.getArray()[k])
                    intersection++;
            }
        }

        newArr = new DayOfYearSet::DayOfYear[totalSize-intersection]; /* Allocate memory for dynamic array for exact size*/
        int ct = 0; /* Indicates next index that will be assigned */

        /* Adds the i'th element of the first object to difference set , if that element is NOT in the second object */
        for(int i=0;i<object1.getSize();i++)
        {
            bool flag = true;
            for(int k=0;k<object2.getSize();k++)
            {
                if(object1.getArray()[i] == object2.getArray()[k])
                {
                    flag=false;
                }
            }
            if(flag==true)
            {
                newArr[ct] = object1.getArray()[i];
                ct++;
            }
        }

        return DayOfYearSet(newArr,totalSize-intersection);
    }

    const DayOfYearSet operator^(const DayOfYearSet& object1, const DayOfYearSet& object2)
    {
        int intersection = 0; /* Cardinality of intersection set */

        /* Determine the cardinality of the intersection set */
        for(int i=0;i<object1.getSize();i++)
        {
            for(int k=0;k<object2.getSize();k++)
            {
                if(object1.getArray()[i] == object2.getArray()[k])
                    intersection++;
            }
        }

        DayOfYearSet::DayOfYear* newArr = new DayOfYearSet::DayOfYear[intersection]; /* Allocate memory for dynamic array for exact size*/
        int ct = 0; /* Indicates next index that will be assigned */

        /* Adds the element that there is both objects to intersection set */
        for(int i=0;i<object1.getSize();i++)
        {
            for(int k=0;k<object2.getSize();k++)
            {
                if(object1.getArray()[i] == object2.getArray()[k])
                {
                    newArr[ct] = object1.getArray()[i];
                    ct++;
                }
            }
        }
        return DayOfYearSet(newArr,intersection);
    }

    const DayOfYearSet operator!(const DayOfYearSet& object1)
    {
        decltype(365-object1.getSize()) size;
        size = 365-object1.getSize(); /* Size of new array that will be returned */
        DayOfYearSet::DayOfYear* newArr = new DayOfYearSet::DayOfYear[size]; /* New array declaration */
        int ct = 0; /* The next index of array that will be assigned */

        int day = 1;
        int month = 1;

        while(month<=12)
        {
            DayOfYearSet::DayOfYear date(day,month);
            bool flag = true; /* Indicates whether the date ,that is generated, is in the object. If it is NOT in the object, flag will be true */
            /* Check whether the date that is generated is in the object */

            for(int i=0;i<object1.getSize();i++)
            {
                if(date==object1.getArray()[i]) flag = false;
            }

            if(flag==true) /* The date that is generated is NOT in the object, add the date to array that will be returned */
            {
                newArr[ct] = date;
                ct++;
            }

            if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) /* If the month has 31 days */
            {
                if(day==31)
                {
                    day = 1;
                    month++;
                }
                else day++;
            }

            else if(month==2) /* If the month is February */
            {
                if(day==28)
                {
                    day = 1;
                    month++;
                }
                else day++;
            }

            else /* If the month has 30 days */
            {
                if(day==30)
                {
                    day = 1;
                    month++;
                }
                else day++;
            }
        }

        return DayOfYearSet(newArr, size);
    }

    bool operator==(const DayOfYearSet& object1, const DayOfYearSet& object2)
    {
        if(object1.getSize()!=object2.getSize()) return false; /* If the size of arrays are not the same, that means the objects is NOT equal */

        for(int i=0;i < object1.getSize();i++)
        {
            bool check = false; /* Indicates whether the i'th element of the object1 in the object2 */
            for(int k=0;k < object2.getSize();k++)
            {
                if(object1.getArray()[i] == object2.getArray()[k])
                    check = true;
            }
            if(check==false) return false;
        }

        return true;
    }

    bool operator!=(const DayOfYearSet& object1, const DayOfYearSet& object2)
    {
        if(object1==object2) return false;
        else return true;
    }

    const DayOfYearSet::DayOfYear DayOfYearSet::operator[](int index)
    {
        return getArray()[index];
    }

    void DayOfYearSet::saveFile(fstream &file, DayOfYearSet &object) /* Save the object to txt file */
    {
        for(int i=0;i<object.getSize();i++)
        {
            file << "Index " << i+1 << ": (Day: " << object.getArray()[i].getDay() << ", Month: " << object.getArray()[i].getMonth() << ")\n";
        }
        file << "\n\n";
        
    }
}


