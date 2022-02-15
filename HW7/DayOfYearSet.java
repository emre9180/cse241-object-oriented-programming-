package emre9180;
import java.util.ArrayList;

/**
 * This class represents a set of DayOfYear objects that includes day and month variables and implements all the neccessary methods.
 * @author Emre Yilmaz - 1901042606
 * @version 1.0
 * @since 2022 January
 */

public class DayOfYearSet
{   /**
    * This is an inner class represents day and month values of a date and all the necessary methods.
     */
    public static class DayOfYear
    {
        private int month;
        private int day;
        public static int objectNum;

        /**
         * This method is a no-parameter constructor. Inilitiazes the month and day variables as 1.
         */
        public DayOfYear()
        {
            this.month = 1;
            this.day = 1;
            ++objectNum;
        }
        /**
         * This method constructs a DayOfYear objects with a specified initDay and initMonth parameters
         * @param initDay
         * @param initMonth
         */
        public DayOfYear(int initDay, int initMonth)
        {
            this.month = initMonth;
            this.day = initDay;
            ++objectNum;
        }

        /**
         * This is a setter function for Day variable of the DayOfYear inner class.
         * @param inputDay
         */
        public void setDay(int inputDay)
        {
            this.day = inputDay;
        }

        /**
         * This is a getter function for the Day variable of the DayOfYear inner class.
         * @return
         */
        public int getDay()
        {
            return day;
        }
        /**
         * This is setter function for the Month varible of the DayOfYear inner class.
         * @param inputMonth
         */
        public void setMonth(int inputMonth)
        {
            month = inputMonth;
        }

        /**
         * This is a getter function for the Month varible of the DayOfYear inner class.
         * @return
         */
        public int getMonth()
        {
            return month;
        }

        /**
         * This is an override method to check whether the objects are equal
         * @param object
         * @return
         * @override
         */
        public boolean equals(DayOfYear object)
        {

            if((object.getDay() == this.getDay()) && object.getMonth() == this.getMonth())
                return true;
            
            else
                return false;        
        }

        /**
         * Returns the total objects alive
         * @return
         */
        public int getObjectNum()
        {
            return objectNum;
        }
    }

    private DayOfYear[] set;
    private int count; 
    

    /**
     * No parameter constructor
     */
    public DayOfYearSet()
    {set=null;}

    /**
     * This is a constructor method that takes an another DayOfYearSet object and initiliazes the variables accordingly.
     * @param newObj
     */
    public DayOfYearSet(DayOfYearSet newObj)
    {
        count = newObj.count;
        set = newObj.set;
    }

    /**
     * Constructor method that takes an ArrayList and initiliazes the variables accordingly.
     * @param array
     */ 
    public DayOfYearSet(ArrayList<DayOfYear> array)
    {
        DayOfYear[] newSet = new DayOfYear[array.size()];

        for(int i=0;i<array.size();i++)
            newSet[i] = array.get(i);
        
        count = array.size();
        set = newSet;
    }

    /**
     * Method to print DayOfYearSet details
     * @override
     */
    public String toString()
    {
        String str = new String();

        for(int i=0;i<count;i++)
            str = str + String.format("Array's %d. element:\nDay -> %d\nMonth -> %d\n\n",i+1, set[i].getDay(), set[i].getMonth());
        
        return str;
    }
    
    /**
     * This method checks whether "input" object duplicates any other element in the set
     * @param input
     * @return
     */
    public boolean duplicate(DayOfYear input)
    {   
        boolean result = false;

        for(int i=0;i<count;i++)
        {
            if(set[i].equals(input))
                result = true;
        }
        return result;
    }

    /**
     * Takes an "input" DayOfYear object and add it to the set. 
     * @param input
     * @return
     */
    public boolean add(DayOfYear input)
    {
        /**
         * Check the validity of the "input" DayOfYear
         */

        if(input.getMonth()<0 || input.getMonth() > 12 || input.getDay()<0 || input.getDay()>31)
        {
            System.out.print("The date is not valid!\n");
            return false;
        }

        if(input.getMonth()==4 || input.getMonth()==6 || input.getMonth()==9 || input.getMonth()==11)
            if(input.getDay()>30)
            {
                System.out.print("The date is not valid!\n");
                return false;
            }


        else if(input.getMonth()==2)
            if(input.getDay()>28)
            {
                System.out.print("The date is not valid!\n");
                return false;
            }
        
        /**
         * If there is duplicate we should NOT add the element to set
         */
        
        if(duplicate(input))
        {
            System.out.println("This element is already in the set. Try another!\n");
            return false;
        }

        /**
         * Initiliaze the new array and assign the new element in it 
         */
        DayOfYear[] newSet = new DayOfYear[count+1];
        int i;
        for(i=0;i<count+1;i++)
            newSet[i] = new DayOfYear();

        
        for(i = 0;i<this.count;i++)
            newSet[i] = set[i];
        
        newSet[i].setDay(input.getDay());
        newSet[i].setMonth(input.getMonth());

        this.set = newSet;
        ++this.count;
        return true;

    }


    /**
     * Takes an "input" DayOfYear object and remove it from the set. 
     * @param input
     * @return
     */
    public boolean remove(DayOfYear input)
    {   
        /**
         * If there is no element that matches the input, we cannot delete anything!
         */
        if(!duplicate(input))
        {
            System.out.println("There is no element that matches your input!\n");
            return false;
        }

        /**
         * Inilitize the new array and remove the element
         */
        DayOfYear [] newSet = new DayOfYear[count-1];
        int i;
        for(i=0;i<count-1;i++)
            newSet[i] = new DayOfYear();

        
        int ct = 0;
        for(i=0;i<count;i++)
        {
            if(set[i].equals(input)) continue;
            else
            {
                newSet[ct] = set[i];
                ++ct;
            }
        }

        set = newSet;
        --count;
        return true;
    }

    /**
     * This method returns the size of the set
     * @return
     */
    public int size()
    {
        return count;
    }

    /**
     * Find the union set of 2 set, then return that union set.
     * @param obj
     * @return
     */
    public DayOfYearSet union(DayOfYearSet obj)
    {
        DayOfYearSet newObj = new DayOfYearSet();

        /**
         * Add the all elements in the object1 to new object.
         */
        /*for(int i=0;i<obj.size();i++)
            newObj.add(obj.set[i]);*/
        for(var i: obj.set)
        {
            newObj.add(i);
        }

        /**
         * We have to find the elements that are in the both sets, and we must NOT add those elements to the new object.
         */
        for(var i: this.set)
        {
            boolean unique = true;
            for(var k: obj.set)
                if(i.equals(k)) unique=false;
            
            if(unique==true)
                newObj.add(i);
        }

        return newObj;
    }

    /**
     * Find the intersection set of 2 set, then return that intersection set
     * @param obj
     * @return
     */
    public DayOfYearSet intersection(DayOfYearSet obj)
    {
        DayOfYearSet newObj = new DayOfYearSet();

        // We have to find the elements that are in the both sets. Then we will add those elements to new set
        for(var i: this.set)
        {
            boolean unique = true;
            for(var k: obj.set)
                if(i.equals(k)) unique=false;
            
            if(unique==false)
                newObj.add(i);
        }

        return newObj;
    } 

    /**
     * Find the complement set, then return that complement set
     * @return
     */
    public DayOfYearSet complement()
    {
        DayOfYearSet newObj = new DayOfYearSet();

        int day = 1;
        int month = 1;
        while(month<=12)
        {
            DayOfYear date = new DayOfYear(day,month);

            /**
             * Indicates whether the date ,that is generated, is in the object. If it is NOT in the object, flag will be true
             */
            boolean flag = true;
            
            /**
             * Check whether the date that is generated is in the object 
             */
            for(var i: this.set)
                if(i.equals(date)) flag = false;

            /**
             * The date that is generated is NOT in the object, add the date to array that will be returned
             */
            if(flag==true) 
                newObj.add(date);
            
            
            /**
             * If the month has 31 days
             */
            if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
            {
                if(day==31)
                {
                    day = 1;
                    month++;
                }
                else day++;
            }

            /**
             * If the month is February
             */
            else if(month==2)
            {
                if(day==28)
                {
                    day = 1;
                    month++;
                }
                else day++;
            }

            /**
             * If the month has 30 days
             */
            else
            {
                if(day==30)
                {
                    day = 1;
                    month++;
                }
                else day++;
            }
        }

        return newObj;


    }


    /**
     * Find the difference set, then return that difference set
     * @param obj
     * @return
     */
    public DayOfYearSet difference(DayOfYearSet obj)
    {
        DayOfYearSet newObj = new DayOfYearSet();

        /**
         * Find the elements that is in the first object but not in the second object. Then, add those elements to new difference set object
         */
        for(var i: this.set)
        {   
            boolean flag=true;

            for(var k: obj.set)
            {
                if(i.equals(k)) flag = false;
            }

            if(flag==true)
                newObj.add(i);
        }

        return newObj;
    }
   
    /**
     * Checks that two DayOfYearSet objects are equal or NOT 
     * @param object
     * @return
     * @override
     */
   public boolean equals(DayOfYearSet object)
   {
       if(this.size()!=object.size()) return false;

       for(var i:this.set)
        {   
            /**
             * Indicates whether the i'th element of the object1 is in the object2 
             */
            boolean check = false; 

            /**
             * 
             */
            for(var k: object.set)
            {
                if(i.equals(k))
                    check = true;
            }
            if(check==false) return false;
        }

        return true;
   }
}
