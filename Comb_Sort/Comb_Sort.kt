// Kotlin Code for Comb Sort 

import java.lang.Math;
class CombSort
{ 
    // Function to swap elements at index a and b
    fun swap(int:arr[], int:a, int:b):void
    {
        int temp = arr[a]; 
        arr[a] = arr[b]; 
        arr[b] = temp; 
    }

    // Function to sort arr[] using Comb Sort 
    fun combSort(int:arr[], int:n):void
    { 
        // initialize gap value to array length
        int gap = n;
        int flag = 1;
        while (gap > 1 || flag == 1 ) 
        { 
            // Update gap value by using shrink factor 1.3
            gap = (gap * 10) / 13;
            gap = Math.max(1, gap);
            flag = 0;
            // Compare all elements with the obtained gap value
            for (i in 0 until (n-gap)) 
            { 
                if (arr[i] > arr[i+gap]) 
                {
                    swap(arr, i, i + gap);
                    flag = 1; 
                } 
            } 
        }
    } 

    // Main function
    fun main()
    { 
        CombSort obj = new CombSort(); 
        var read = Scanner(System.`in`)
        println("Enter the size of Array:")
        val arrSize = read.nextLine().toInt()
        var arr = IntArray(arrSize)
        println("Enter elements")
        for(i in 0 until arrSize)
        {
            arr[i] = read.nextLine().toInt()
        }
        int n = arrSize;
        obj.combSort(arr, n);

        println("Array after sorting:");
        for (i in 0 until arrSize) 
        {
            println(arr[i] + " ");
        }
    } 
}

/* 
Input
-10, 50, 20, 0, 15, -25, 30
Output
-25 -10 0 15 20 30 50
*/
