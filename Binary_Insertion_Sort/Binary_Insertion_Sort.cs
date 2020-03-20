/*We can use binary search to reduce the number of comparisons in normal insertion sort. 
Binary Insertion Sort uses binary search to find the proper location to insert the selected item at each iteration.*/
using System; 
  
class BIS { 
    public static void sort(int []array) 
    { 
        for (int i = 1; i < array.Length; i++) 
        { 
            int x = array[i]; 
  
            // Find location to insert using 
            // binary search 
            int j = Math.Abs(Array.BinarySearch( array, 0, i, x) + 1); 
  
            // Shifting array to one location right 
            System.Array.Copy(array, j, array, j + 1, i - j); 
 
            array[j] = x; 
        } 
    }
    public static void Main() 
    { 
        int size;
        size= Convert.ToInt32(Console.ReadLine()); 

        int[] array = new int[size];

        for (int i = 0; i < size; i++)
	    array[i] = Convert.ToInt32(Console.ReadLine());
	    
        sort(array); 
	    
        for (int i = 0; i < array.Length; i++) 
            Console.Write(array[i] + " "); 
    } 
} 



/*
INPUT:Enter the size of the array 5
Enter the elements 34
75
24
1
6
OUTPUT:Sorted array: 
1 6 24 34 75
*/
