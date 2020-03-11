// C# program implementing 3-way quick sort 
using System; 
    
class QuickSort3Way 
{ 
    // A function used to swap values 
    static void swap<T>(ref T lhs, ref T rhs) 
    { 
        T temp; 
        temp = lhs; 
        lhs = rhs; 
        rhs = temp; 
    } 
    
    //This function partitions the array into three
    public static void partition(int[] a, int l, int r, ref int i, ref int j) 
    { 
        i = l-1; j = r; 
        int p = l-1, q = r; 
        int v = a[r]; 
        
        while (true) 
        { 
            // From left, find the first element greater than v
            while (a[++i] < v); 
        
            // From right, find the first element smaller than or equal to v
            while (v < a[--j]) 
                if (j == l) 
                    break; 
        
            // We are done with the checking 
            if (i >= j) break; 
        
            // Swap, the smaller value to left and greater value to right 
            swap(ref a[i], ref a[j]); 
        
            // Move all same left occurrence of pivot to beginning of array
            if (a[i] == v) 
            { 
                p++; 
                swap(ref a[p], ref a[i]); 
            } 
        
            // Move all same right occurrence of pivot to end of array
            if (a[j] == v) 
            { 
                q--; 
                swap(ref a[j], ref a[q]); 
            } 
        } 
        
        // Move pivot element to its correct index 
        swap(ref a[i], ref a[r]); 
        
        // Move all left same occurrences from beginning 
        // to adjacent to arr[i] 
        j = i-1; 
        for (int k = l; k < p; k++, j--) 
            swap(ref a[k], ref a[j]); 
        
        // Move all right same occurrences from end 
        // to adjacent to arr[i] 
        i = i+1; 
        for (int k = r-1; k > q; k--, i++) 
            swap(ref a[i], ref a[k]); 
    } 
        
    // 3-way partition based quick sort 
    public static void quicksort(int[] a, int l, int r) 
    { 
        if (r <= l) return; 
        
        int i = 0, j = 0; 
        
        // Here i and j are passed as reference 
        partition(a, l, r, ref i, ref j); 
        
        // Recursion
        quicksort(a, l, j); 
        quicksort(a, i, r); 
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
        quicksort(array, 0, size - 1); 
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

