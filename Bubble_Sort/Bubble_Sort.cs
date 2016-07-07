using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bubble_Sort
{

    class Program
    {
        public static void BubbleSort(int[] array, int size)
        {
            int temp;

            for (int i = 0; i < size - 1; i++)
            {
                for (int j = 0; j < size - i - 1; j++)
                {
                    if (array[j] > array[j + 1])
                    {
                        temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = temp;
                    }
                }
            }

        }

        // function for bubble sort

        // function ro print array
        public static void Print_Array(int[] array, int size)
        {
            for (int i = 0; i < size; i++)
                Console.Write(Convert.ToString(array[i]) + " ");

            Console.WriteLine();
        }

        static void Main(String[] args)
        {
            int[] array = { 2, 4, 3, 1, 6, 8, 4 };
            BubbleSort(array, 7);
            Print_Array(array, 7);
            Console.ReadLine();
        }
    }
}

// Output
// 1 2 3 4 4 6 8