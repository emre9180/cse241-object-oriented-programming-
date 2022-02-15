package emre9180;
import java.util.ArrayList;
import java.io.File;  // Import the File class
import java.io.PrintWriter;

/* NOTE FOR T.A. -> ALL THE OUTPUT IS BOTH PRINTED TO TEXT FILE and TERMINAL. */
/* NOTE FOR T.A. -> ALL THE OUTPUT IS BOTH PRINTED TO TEXT FILE and TERMINAL. */

public class main
{
  public static void main(String[] args) 
  { 

    PrintWriter file = null;
    DayOfYearSet.DayOfYear.objectNum=0;

    try
    {
      file = new PrintWriter("output.txt", "UTF-8");   
    }
    catch (Exception ex)  
    {
        System.out.printf("The text cannot open!\n");
    }



    // Construct an array that is created with Day Of Year objects

    ArrayList<DayOfYearSet.DayOfYear> DoYarray = new ArrayList<DayOfYearSet.DayOfYear>();
    DoYarray.add(new DayOfYearSet.DayOfYear(7,4));
    DoYarray.add(new DayOfYearSet.DayOfYear(3,3));
    DoYarray.add(new DayOfYearSet.DayOfYear(4,4));
    DoYarray.add(new DayOfYearSet.DayOfYear(5,5));
    DoYarray.add(new DayOfYearSet.DayOfYear(6,6));

    // Initiliaze a set using an ArrayList constructor
    DayOfYearSet set1 = new DayOfYearSet(DoYarray); 

    // Initiliaze a set using no-paremeter constructor
    DayOfYearSet set2 = new DayOfYearSet();

    // Add Day Of Year Objects to second set
    set2.add(new DayOfYearSet.DayOfYear(1,1));
    set2.add(new DayOfYearSet.DayOfYear(2,2));
    set2.add(new DayOfYearSet.DayOfYear(4,8));
    set2.add(new DayOfYearSet.DayOfYear(3,3));
    set2.add(new DayOfYearSet.DayOfYear(6,8));
    set2.add(new DayOfYearSet.DayOfYear(7,4));




    // Print the object number
    System.out.printf("\n\n\n***************************************************** Printing total objet number.  *****************************************************\n\n");
    System.out.printf("Total object number is: %d",DayOfYearSet.DayOfYear.objectNum);


    file.printf("\n\n\n***************************************************** Printing total objet number.  *****************************************************\n\n");
    file.printf("Total object number is: %d\n\n",DayOfYearSet.DayOfYear.objectNum);






    // Check and print the equality of SET1 and SET2
    boolean equality = set1.equals(set2);
    System.out.printf("\n\n\n*****************************************************  Check the equality of SET1 and SET2.  *****************************************************\n\n");
    if(equality) System.out.printf("SET1 and SET2 is equal!\n");
    else System.out.printf("SET1 and SET2 is NOT equal!\n");

    file.printf("\n*****************************************************  Check the equality of SET1 and SET2.  *****************************************************\n\n");
    if(equality) file.printf("SET1 and SET2 is equal!\n");
    else file.printf("SET1 and SET2 is NOT equal!\n");
    

    


    // Print the size of the SET1 and SET2
    System.out.printf("\n*****************************************************  Printing the size of the SET1 and SET2.  *****************************************************\n\n");
    System.out.printf("Size of the first Day Of Year Set object (SET1) is: %d\n", set1.size());
    System.out.printf("Size of the second Day Of Year Set object (SET2) is: %d\n", set2.size());


    file.printf("\n*****************************************************  Printing the size of the SET1 and SET2.  *****************************************************\n\n");
    file.printf("Size of the first Day Of Year Set object (SET1) is: %d\n", set1.size());
    file.printf("Size of the second Day Of Year Set object (SET2) is: %d\n", set2.size());
    

    // Print the sets
    System.out.printf("\n\n\n***************************************************** Printing the elements of the SET1 and SET2.  *****************************************************\n\n");
    System.out.printf("First set (SET1):\n%s\n",set1.toString());
    System.out.printf("\nSecond set (SET2):\n%s\n",set2.toString());


    file.printf("\n\n\n***************************************************** Printing the elements of the SET1 and SET2.  *****************************************************\n\n");
    file.printf("First set (SET1):\n%s\n",set1.toString());
    file.printf("\nSecond set (SET2):\n%s\n",set2.toString());





    // Create a set that is intersection set of SET1 and SET2
    DayOfYearSet intersection = new DayOfYearSet(set1.intersection(set2));


    // Print the size of intersection set of SET1 and SET2
    System.out.printf("\n\n\n*****************************************************  Printing the size of the intersection set of SET1 and SET2.  *****************************************************\n\n");
    System.out.printf("Size of the intersection set of SET1 and SET2: %d\n", intersection.size());


    file.printf("\n\n\n*****************************************************  Printing the size of the intersection set of SET1 and SET2.  *****************************************************\n\n");
    file.printf("Size of the intersection set of SET1 and SET2: %d\n", intersection.size());


    // Print the intersection set of SET1 and SET2
    System.out.printf("\n\n\n***************************************************** Printing the elements of the intersection set of SET1 and SET2.  *****************************************************\n\n");
    System.out.printf("Intersection set of SET1 and SET2:\n%s\n",intersection.toString());

    file.printf("\n\n\n***************************************************** Printing the elements of the intersection set of SET1 and SET2.  *****************************************************\n\n");
    file.printf("Intersection set of SET1 and SET2:\n%s\n",intersection.toString());






    // Create a set that is union set of SET1 and SET2
    DayOfYearSet union = new DayOfYearSet(set1.union(set2));


    // Print the size of union set of SET1 and SET2
    System.out.printf("\n\n\n***************************************************** Printing the size of the union set of SET1 and SET2.  *****************************************************\n\n");
    System.out.printf("Size of the union set of SET1 and SET2: %d\n", union.size());


    file.printf("\n\n\n***************************************************** Printing the size of the union set of SET1 and SET2.  *****************************************************\n\n");
    file.printf("Size of the union set of SET1 and SET2: %d\n", union.size());


    // Print the union set of SET1 and SET2
    System.out.printf("\n\n\n***************************************************** Printing the elements of the union set of SET1 and SET2.  *****************************************************\n\n");
    System.out.printf("Union set of SET1 and SET2:\n%s\n",union.toString());

    file.printf("\n\n\n***************************************************** Printing the elements of the union set of SET1 and SET2.  *****************************************************\n\n");
    file.printf("Union set of SET1 and SET2:\n%s\n",union.toString());





    // Create a difference set (SET1-SET2)
    DayOfYearSet difference = new DayOfYearSet(set1.difference(set2));


    // Print the size of difference set (SET1-SET2)
    System.out.printf("\n\n\n***************************************************** Printing the size of the difference set of SET1 and SET2.  *****************************************************\n\n");
    System.out.printf("Size of the difference set of SET1 and SET2: %d\n", difference.size());


    file.printf("\n\n\n***************************************************** Printing the size of the difference set of SET1 and SET2.  *****************************************************\n\n");
    file.printf("Size of the difference set of SET1 and SET2: %d\n", difference.size());


    // Print the difference set (SET1-SET2)
    System.out.printf("\n\n\n***************************************************** Printing the elements of the difference set of SET1 and SET2.  *****************************************************\n\n");
    System.out.printf("difference set of SET1 and SET2:\n%s\n",difference.toString());


    file.printf("\n\n\n***************************************************** Printing the elements of the difference set of SET1 and SET2.  *****************************************************\n\n");
    file.printf("difference set of SET1 and SET2:\n%s\n",difference.toString());


    // Print the object number
    System.out.printf("\n\n\n***************************************************** Printing total objet number.  *****************************************************\n\n");
    System.out.printf("Total object number is: %d",DayOfYearSet.DayOfYear.objectNum);


    file.printf("\n\n\n***************************************************** Printing total objet number.  *****************************************************\n\n");
    file.printf("Total object number is: %d",DayOfYearSet.DayOfYear.objectNum);







     // Remove some elements from SET1 and SET2
     System.out.printf("\n\n\n***************************************************** Removing some elements...  *****************************************************\n\n");
     file.printf("\n***************************************************** Removing some elements...  *****************************************************\n\n");
     set1.remove(new DayOfYearSet.DayOfYear(4,4));
     set2.remove(new DayOfYearSet.DayOfYear(1,1));
     System.out.printf("\nRemoving some elements from sets is done...\n\n");
     file.printf("\nRemoving some elements from sets is done...\n\n");
 
 


 
     // Print the size of the SET1 and SET2
     System.out.printf("\n*****************************************************  Printing the size of the SET1 and SET2 after removing some elements.  *****************************************************\n\n");
     System.out.printf("Size of the first Day Of Year Set object (SET1) is: %d\n", set1.size());
     System.out.printf("Size of the second Day Of Year Set object (SET2) is: %d\n", set2.size());


     file.printf("\n*****************************************************  Printing the size of the SET1 and SET2 after removing some elements.  *****************************************************\n\n");
     file.printf("Size of the first Day Of Year Set object (SET1) is: %d\n", set1.size());
     file.printf("Size of the second Day Of Year Set object (SET2) is: %d\n", set2.size());
     
 
     // Print the sets
     System.out.printf("\n\n\n***************************************************** Printing the elements of the SET1 and SET2 after removing some elements.  *****************************************************\n\n");
     System.out.printf("First set (SET1):\n%s\n",set1.toString());
     System.out.printf("\nSecond set (SET2):\n%s\n",set2.toString());


     file.printf("\n\n\n***************************************************** Printing the elements of the SET1 and SET2 after removing some elements.  *****************************************************\n\n");
     file.printf("First set (SET1):\n%s\n",set1.toString());
     file.printf("\nSecond set (SET2):\n%s\n",set2.toString());





     // Create a set that is intersection set of SET1 and SET2 after removing some elements
    DayOfYearSet intersection2 = new DayOfYearSet(set1.intersection(set2));

  
    // Print the size of intersection set of SET1 and SET2 after removing some elements
    System.out.printf("\n\n\n*****************************************************  Printing the size of the intersection set of SET1 and SET2 after removing some elements.  *****************************************************\n\n");
    System.out.printf("Size of the intersection set of SET1 and SET2 after removing some elements: %d\n", intersection2.size());


    file.printf("\n\n\n*****************************************************  Printing the size of the intersection set of SET1 and SET2 after removing some elements.  *****************************************************\n\n");
    file.printf("Size of the intersection set of SET1 and SET2 after removing some elements: %d\n", intersection2.size());


    // Print the intersection set of SET1 and SET2 after removing some elements
    System.out.printf("\n\n\n***************************************************** Printing the elements of the intersection set of SET1 and SET2 after removing some elements.  *****************************************************\n\n");
    System.out.printf("Intersection set of SET1 and SET2 after removing some elements:\n%s\n",intersection2.toString());

    file.printf("\n\n\n***************************************************** Printing the elements of the intersection set of SET1 and SET2 after removing some elements.  *****************************************************\n\n");
    file.printf("Intersection set of SET1 and SET2 after removing some elements:\n%s\n",intersection2.toString());





    // Create a set that is union set of SET1 and SET2 after removing some elements
    DayOfYearSet union2 = new DayOfYearSet(set1.union(set2));


    // Print the size of union set of SET1 and SET2 after removing some elements
    System.out.printf("\n\n\n***************************************************** Printing the size of the union set of SET1 and SET2 after removing some elements.  *****************************************************\n\n");
    System.out.printf("Size of the union set of SET1 and SET2 after removing some elements: %d\n", union2.size());


    file.printf("\n\n\n***************************************************** Printing the size of the union set of SET1 and SET2 after removing some elements.  *****************************************************\n\n");
    file.printf("Size of the union set of SET1 and SET2 after removing some elements: %d\n", union2.size());


    // Print the union set of SET1 and SET2 after removing some elements
    System.out.printf("\n\n\n***************************************************** Printing the elements of the union set of SET1 and SET2 after removing some elements.  *****************************************************\n\n");
    System.out.printf("Union set of SET1 and SET2 after removing some elements:\n%s\n",union2.toString());


    file.printf("\n\n\n***************************************************** Printing the elements of the union set of SET1 and SET2 after removing some elements.  *****************************************************\n\n");
    file.printf("Union set of SET1 and SET2 after removing some elements:\n%s\n",union2.toString());





    // Create a difference set (SET1-SET2) after removing some elements
    DayOfYearSet difference2 = new DayOfYearSet(set1.difference(set2));


    // Print the size of difference set (SET1-SET2) after removing some elements
    System.out.printf("\n\n\n***************************************************** Printing the size of the difference set of SET1 and SET2 after removing some elements.  *****************************************************\n\n");
    System.out.printf("Size of the difference set of SET1 and SET2 after removing some elements: %d\n", difference2.size());


    file.printf("\n\n\n***************************************************** Printing the size of the difference set of SET1 and SET2 after removing some elements.  *****************************************************\n\n");
    file.printf("Size of the difference set of SET1 and SET2 after removing some elements: %d\n", difference2.size());


    // Print the difference set (SET1-SET2) after removing some elements
    System.out.printf("\n\n\n***************************************************** Printing the elements of the difference set of SET1 and SET2 after removing some elements.  *****************************************************\n\n");
    System.out.printf("difference set of SET1 and SET2 after removing some elements:\n%s\n",difference2.toString());

    file.printf("\n\n\n***************************************************** Printing the elements of the difference set of SET1 and SET2 after removing some elements.  *****************************************************\n\n");
    file.printf("difference set of SET1 and SET2 after removing some elements:\n%s\n",difference2.toString());





    // Create complement set of SET1
    DayOfYearSet complement = new DayOfYearSet(set1.complement());


    // Print the size of complement set of SET1
    System.out.printf("\n\n\n***************************************************** Printing the size of the union set of SET1 and SET2.  *****************************************************\n\n");
    System.out.printf("Size of the union set of SET1 and SET2: %d\n", complement.size());


    file.printf("\n\n\n***************************************************** Printing the size of the union set of SET1 and SET2.  *****************************************************\n\n");
    file.printf("Size of the union set of SET1 and SET2: %d\n", complement.size());


    // Print the complement set of SET1
    System.out.printf("\n\n\n***************************************************** Printing the elements of the union set of SET1 and SET2.  *****************************************************\n\n");
    System.out.printf("Union set of SET1 and SET2:\n%s\n",complement.toString());


    file.printf("\n\n\n***************************************************** Printing the elements of the union set of SET1 and SET2.  *****************************************************\n\n");
    file.printf("Union set of SET1 and SET2:\n%s\n",complement.toString());





    // Check DeMorgan's Law
    System.out.printf("Morgan says that !(difference1 set + difference2 set) == !difference1 set ^ !difference2 set\nChecking that rule...\n...\n...\n");
    if(difference.union(difference2).complement().equals(difference.complement().intersection(difference2.complement()))) System.out.printf("TRUE!\n\n");

    file.printf("Morgan says that !(difference1 set + difference2 set) == !difference1 set ^ !difference2 set\nChecking that rule...\n...\n...\n");
    if(difference.union(difference2).complement().equals(difference.complement().intersection(difference2.complement()))) file.printf("TRUE!\n\n");



    // Check DeMorgan's Law
    file.printf("Morgan says that !(union1 set + union2 set) == !union1 set ^ !union2 set\nChecking that rule...\n...\n...\n");
    if(union.union(union2).complement().equals(union.complement().intersection(union2.complement()))) file.printf("TRUE!\n\n");

    System.out.printf("Morgan says that !(union1 set + union2 set) == !union1 set ^ !union2 set\nChecking that rule...\n...\n...\n");
    if(union.union(union2).complement().equals(union.complement().intersection(union2.complement()))) System.out.printf("TRUE!\n\n");



    // Check DeMorgan's Law
    System.out.printf("Morgan says that !(intersection set + intersection set) == !intersection set ^ !intersection2 set\nChecking that rule...\n...\n...\n");
    if(intersection.union(intersection2).complement().equals(intersection.complement().intersection(intersection2.complement()))) System.out.printf("TRUE!\n\n");

    file.printf("Morgan says that !(intersection set + intersection set) == !intersection set ^ !intersection2 set\nChecking that rule...\n...\n...\n");
    if(intersection.union(intersection2).complement().equals(intersection.complement().intersection(intersection2.complement()))) file.printf("TRUE!\n\n");



    // Check DeMorgan's Law
    System.out.printf("Morgan says that !(SET1 set + SET2 set) == !SET1 set ^ !SET2 set\nChecking that rule...\n...\n...\n");
    if(set1.union(set2).complement().equals(set1.complement().intersection(set2.complement()))) System.out.printf("TRUE!\n\n");

    file.printf("Morgan says that !(SET1 set + SET2 set) == !SET1 set ^ !SET2 set\nChecking that rule...\n...\n...\n");
    if(set1.union(set2).complement().equals(set1.complement().intersection(set2.complement()))) file.printf("TRUE!\n\n");



    // Check DeMorgan's Law
    file.printf("Morgan says that !(difference1 set + complement set) == !difference1 set ^ !complement set\nChecking that rule...\n...\n...\n");
    if(difference.union(complement).complement().equals(difference.complement().intersection(complement.complement()))) file.printf("TRUE!\n\n");
    
    file.close();

  }
}
