// Kotlin Code for Counting Sort

public class Counting_Sort {
    // Function that sort the given input
    fun sort(int:input[]):void
    {
        int n = input.length;
        int output[] = new int[n]; 
        int max = input[0];
        int min = input[0];

        for(i in 1 until n)
        {
            if(input[i] > max)
            {
                max = input[i]; 
            }
    
            else if(input[i] < min)
            {
                min = input[i]; 
            }              
        }

        // Size of count array
        int k = max - min + 1; 
        int count_array[] = new int[k]; 

        for(i in 0 until n)
        {
            count_array[input[i] - min]++; 
        }
        
        for(i in 1 until k)
        {
            count_array[i] += count_array[i - 1];
        }

       
        for(i in 0 until n)
        {
            output[count_array[input[i] - min] - 1] = input[i];
            count_array[input[i] - min]--;
        }
        // Copy the output array to input, so that input now contains sorted values
        for(i in 0 until n)
        {
            input[i] = output[i]; 
        }
    }

    // Main Function
    fun main()
    {
        var read = Scanner(System.`in`)
        println("Enter the size of Array:")
        val arrSize = read.nextLine().toInt()
        var input = IntArray(arrSize)
        println("Enter elements")
        for(i in 0 until arrSize)
        {
            input[i] = read.nextLine().toInt()
        }

        sort(input);
        for(i in 0 until arrSize)
        {
            println(input[i]); 
        }
    }
}

/* 
Input
2  1  4  1  3  5  7  5 4
Output
1  1  2  3  4  4  5  5  7
*/
