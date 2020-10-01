using System;

namespace Kadane_Algorithm
{
    class Program
    {
        public static int max(int a, int b)
        {
            if(a > b)
                return a;
            else
                return b;
        }

        // Function implementing Kadane's Algorithm (array contains at least one positive number)
        public static int kadane(int[] input, int size)
        {
            int current_max = 0;
            int max_so_far = 0;

            for(int i = 0; i < size; i++)
            {
                current_max = max(0, current_max + input[i]);
                max_so_far = max(max_so_far, current_max);
            }
            return max_so_far; // Maximum subarray sum
        }

        static void Main(String[] args)
        {
            int size, max_subarray_sum;

            int[] input = { -2, 1, -6, 4, -1, 2, 1, -5, 4 }; // Input array

            size = 9; // Size of array

            int flag = 0; // Flag variable to check if all the numbers in array are negative or not

            int largest_in_negative = input[0]; // Smallest_negative variable will store the maximum subarray sum if all the numbers are negative in array

            for(int i = 0; i < size; i++) // Scanning each element in array
            {
                  if(input[i] >= 0) // If any element is positive, kadane's algo can be applied
                  {
                      flag = 1;
                      break;
                  }
                  else if(input[i] > largest_in_negative) // If all the elements are negative, find the largest in them
                      largest_in_negative = input[i];
            }

            if(flag == 1) // Kadane's algo applicable
                max_subarray_sum = kadane(input, size);
            else
                max_subarray_sum = largest_in_negative; // Kadane 's algo not applicable,
            // hence the max_subarray_sum will be the largest number in array itself
            Console.WriteLine("Maximum Subarray Sum is " + Convert.ToString(max_subarray_sum));
            Console.ReadLine();
        }
    }
}

// Output
// Maximum Subarray Sum is 6
