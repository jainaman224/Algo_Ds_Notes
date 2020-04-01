using System;
 
class pancakeSortProgram {
    // function swapping adjacent integer in array till from index 0 toindex i
    static void flip(int []arr, int i)
    {
        int temp, start = 0;
        while (start < i)
        {
            temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp;
            start++;
            i--;
        }
    }
    // function returning index of max value till index curr_size
    static int findMax(int []arr, int n)
    {
        int mi, i;
        for (mi = 0, i = 0; i < n; ++i)
            if (arr[i] > arr[mi])
                mi = i;      
        return mi;
    }
 
    static int pancakeSort(int []arr, int n)
    {
        for (int curr_size = n; curr_size > 1; --curr_size)
        { 
            // function calling for finding index of max integer 
            // till the index curr_size
            int mi = findMax(arr, curr_size);
            // call function flip for swapping if index of max integer
            // till the index curr_size is not equal to curr_size-1
            if (mi != curr_size - 1)
            {
                flip(arr, mi);
                flip(arr, curr_size - 1);
            }
        } 
        return 0;
    }
    // function for printing sorted array
    static void printArray(int []arr, int arr_size)
    {
        for (int i = 0; i < arr_size; i++)
            Console.Write(arr[i] + " ");
        Console.Write("");
    }
 
    public static void Main (string [] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());//input size of array
        int []arr = new int[n];//initializing array of size n
     
        for(int i = 0; i < n; i++)
            arr[i] = Convert.ToInt32(Console.ReadLine());//input value in array
     
        pancakeSort(arr, n);// call function which is sorting the input array
        Console.Write("Sorted Array: ");
        printArray(arr, n);// call fubction which print the sorted array
    }
}
/*
Input:
6
23 
10 
20 
11 
12 
6 
7

Output:
Sorted Array: 6 7 10 11 12 20 23
*/
