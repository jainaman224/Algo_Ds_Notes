// C# program implementation of the  ShellSort algorithm
using System; 

class ShellSort 
{ 
    //function to implement ShellSort
    void shellsort(int []array, int size) 
    { 
        // Beginning with a big gap, and then keep on reducing it. 
        for (int g = size/2; g >= 1; g /= 2) 
        { 
            // Performing an insertion sort
            for (int i = g; i < size; i += 1) 
            { 
                int j, temp = array[i]; 

                //Shift other elements until the correct position of a[i] is found  
                for (j = i; array[j - g] > temp && j >= g ; j -= g) 
                    array[j] = array[j - g]; 

                // put the element a[i] in its correct position
                array[j] = temp; 
            } 
        } 
    } 

     public static void Main() 
    { 

        int size;
        Console.Write("How many numbers do you want to sort : ");
        size = Convert.ToInt32(Console.ReadLine());  
        int[] array = new int[size];
        Console.Write("\nEnter the numbers : ");
        for (int i = 0; i < size; i++) 
              array[i] = Convert.ToInt32(Console.ReadLine());
        ShellSort ob = new ShellSort(); 
        ob.shellsort(array, size); 
        Console.Write("\nAfter sorting  : ");
        for (int i = 0; i < size; i++) 
                Console.Write(array[i] + " "); 
    }  
} 

/*SAMPLE INPUT AND OUTPUT
SAMPLE 1
How many numbers do you want to sort : 7 
Enter the numbers : 
 4
 9 
 3
 9
 4
 7
 5
After sorting : 3 4 4 5 7 9 9 
SAMPLE 2
How many numbers do you want to sort : 5 
Enter the numbers :
 5 
 1 
 7 
 3 
 2
After sorting : 1 2 3 5 7
*/ 
