/// C# program for cycle sort 
using System; 
  
class CycleSort { 
      
    // Function to implement Cycle sort 
    public static void cycleSort(int[] arr, int n) 
    {
        int writes = 0; 
        // traverse through array elements and find the right position  
        for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) 
        {  
            int item = arr[cycle_start]; 
            int pos = cycle_start; 
            for (int i = cycle_start + 1; i < n; i++) 
                if (arr[i] < item) 
                    pos++; 
                    
            //If item is in correct position
            if (pos == cycle_start) 
                continue; 
            
            //Ignoring all duplicate elements
            while (item == arr[pos]) 
                pos += 1; 
            
            //Keeping the item in its correct position
            if (pos != cycle_start) { 
                int temp = item; 
                item = arr[pos]; 
                arr[pos] = temp; 
                writes++; 
        } 
  
            while (pos != cycle_start) { 
                pos = cycle_start; 
              
                // Find position where we put the element 
                for (int i = cycle_start + 1; i < n; i++) 
                    if (arr[i] < item) 
                        pos += 1; 
              
               //Ignoring duplicate elements
                while (item == arr[pos]) 
                    pos += 1;
              
                //Keeping the item in its right position
                if (item != arr[pos]) { 
                    int temp = item; 
                    item = arr[pos]; 
                    arr[pos] = temp; 
                    writes++; 
                } 
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
        cycleSort(array, size); 
        Console.Write("\nAfter sorting  : ");
        for (int i = 0; i < size; i++) 
            Console.Write(array[i] + " "); 
    } 
} 

//SAMPLE INPUT AND OUTPUT
/*SAMPLE 1
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

//SAMPLE 2
How many numbers do you want to sort : 5 
Enter the numbers :
 5 
 1 
 7 
 3 
 2
 After sorting : 1 2 3 5 7
*/
