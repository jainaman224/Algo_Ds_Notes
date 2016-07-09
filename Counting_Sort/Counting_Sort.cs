using System;

namespace Counting_Sort
{
    class Program
    {
        public static void CountingSort(int[] input)
        {
            int n = input.GetLength(0);
            int[] output = new int[n]; // The output will have sorted input array

            int max = input[0];
            int min = input[0];

            for(int i = 1; i < n; i++)
            {
                if(input[i] > max)
                    max = input[i]; // Maximum value in array
                else if(input[i] < min)
                    min = input[i]; // Minimum value in array
            }

            int k = max - min + 1; // Size of count array
            int[] count_array = new int[k]; // Create a Count array

            for(int i = 0; i < n; i++)
                count_array[input[i] - min]++; // Store count of each individual input value

            // Change count_array so that count_array now contains actual
            // position of input values in output array
            for(int i = 1; i < k; i++)
                count_array[i] += count_array[i - 1];

            // Populate output array using count_array and input array
            for(int i = 0; i < n; i++)
            {
                output[count_array[input[i] - min] - 1] = input[i];
                count_array[input[i] - min]--;
            }

            for(int i = 0; i < n; i++)
                input[i] = output[i]; // Copy the output array to input, so that input now contains sorted values
        }
        // function for bubble sort
        // function ro print array
        public static void Print_Array(int[] array, int size)
        {
            for(int i = 0; i < size; i++)
                Console.Write(Convert.ToString(array[i]) + " ");
            Console.WriteLine();
        }

        static void Main(String[] args)
        {
            int[] input = { 2, 4, 3, 1, 6, 8, 4 };

            CountingSort(input);

            Console.WriteLine("Sorted Array : ");
            Print_Array(input,input.GetLength(0));

            Console.WriteLine();
            Console.ReadLine();
        }
    }
}

// Output
// 1 2 3 4 4 6 8
