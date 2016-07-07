using System;

namespace Insertion_Sort
{
    class Program
    {
        // function for insertion sort
        public static void InsertionSort(int[] array, int size)
        {
            int temp, j;
            for(int i = 1; i < size; i++)
            {
                temp = array[i];
                j = i - 1;
                // Do swapping
                while(j >= 0 && array[j] > temp)
                {
                    array[j + 1] = array[j];
                    j--;
                }
                array[j + 1] = temp;
            }
        }

        // function to print array
        public static void Print_Array(int[] array, int size)
        {
            for(int i = 0; i < size; i++)
                Console.Write(Convert.ToString(array[i]) + " ");
            Console.WriteLine();
        }

        static void Main(String[] args)
        {
            int[] array = { 2, 4, 3, 1, 6, 8, 4 };
            InsertionSort(array, 7);
            Print_Array(array, 7);
            Console.WriteLine();
            Console.ReadLine();
        }
    }
}

// Output
// 1 2 3 4 4 6 8
