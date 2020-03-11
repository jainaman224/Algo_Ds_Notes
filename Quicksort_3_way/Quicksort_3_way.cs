// C# program implementing 3-way quick sort 
using System; 
    
class QuickSort3Way 
{ 
    // A function used to swap values 
    static void swap<Z>(ref Z a, ref Z b) 
    { 
        Z temp; 
        temp = a; 
        a = b; 
        b = temp; 
    } 
    
    //This function partitions the array into three
    public static void partition(int[] a, int r, int l, ref int j, ref int i) 
    { 
        j = r;
        i = l-1;  
        int y = r, x = i;
        int b = a[r]; 
        
        while (true) 
        { 
            // From left, find the first element greater than v
            while (a[++i] < b)
                {    }
        
            // From right, find the first element smaller than or equal to v
            while (a[--j] > b) 
                if (j == l) 
                    break; 
        
            // We are done with the checking 
            if (i >= j) 
                break; 
        
            // Swap, the smaller value to left and greater value to right 
            swap(ref a[j], ref a[i]); 
        
            // Move all same left occurrence of pivot to beginning of array
            if (a[i] == b) 
            { 
                x++; 
                swap(ref a[x], ref a[i]); 
            } 
        
            // Move all same right occurrence of pivot to end of array
            if (a[j] == b) 
            { 
                y--; 
                swap(ref a[j], ref a[y]); 
            } 
        } 
        
        // Move pivot element to its correct index 
        swap(ref a[i], ref a[r]); 
        
        // Move all left same occurrences from beginning  to adjacent to array[i] 
        j = i-1; 
        for (int k = l; k < x; k++) 
            {
                swap(ref a[k], ref a[j]); 
                j--;
            }
        // Move all right same occurrences from end to adjacent to array[i] 
        i = i+1; 
        for (int k = r-1; k > y; k--, i++) 
            swap(ref a[k], ref a[i]); 
    } 
        
    // 3-way partition based quick sort 
    public static void QuickSort(int[] a, int l, int r) 
    { 
        if (r <= l)
            return;  
        int j = 0, i = 0; 
         
        partition(a, r, l, ref j, ref i); 
        
        // Recursion
        QuickSort(a, i, r);
        QuickSort(a, l, j);  
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
        QuickSort(array, 0, size - 1); 
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
 4
 2
After sorting : 1 2 4 5 7
*/ 
