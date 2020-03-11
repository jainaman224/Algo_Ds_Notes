using System;
 
class pancakeSortProgram {
 
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
        for (int curr_size = n; curr_size > 1;--curr_size)
        { 
            int mi = findMax(arr, curr_size);
            if (mi != curr_size - 1)
            {
                flip(arr, mi);
                flip(arr, curr_size - 1);
            }
        } 
        return 0;
    }
 
    static void printArray(int []arr, int arr_size)
    {
        for (int i = 0; i < arr_size; i++)
            Console.Write(arr[i] + " ");
        Console.Write("");
    }
 
    public static void Main (string [] args)
    {
        int n=Convert.ToInt32(Console.ReadLine());  
        int []arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i] = Convert.ToInt32(Console.ReadLine());
        n = arr.Length;
        pancakeSort(arr, n);
        Console.Write("Sorted Array: ");
        printArray(arr, n);
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
