using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Heap_Sort
{
    class Program
    {
        // Conquer
        public static void Heapify(int[] array, int root, int size)
        {
            int left = 2 * root + 1, largest;
            int right = left + 1, temp;

            if(left < size && array[left] > array[root])
                largest = left;
            else
                largest = root;

            if(right < size && array[right] > array[largest])
                largest = right;

            if(largest != root)
            {
                temp = array[root];
                array[root] = array[largest];
                array[largest] = temp;
                Heapify(array, largest, size);
            }
        }

        // Divide array into halves
        public static void Build_Heap(int[] array, int size)
        {
            for(int i = (size - 1) / 2; i >= 0; i--)
                Heapify(array, i, size);
        }

        public static void HeapSort(int[] array, int size)
        {
            Build_Heap(array, size);
            int temp, i;

            for(i = size - 1; i > 0; i--)
            {
                temp = array[0];
                array[0] = array[i];
                array[i] = temp;
                Heapify(array, 0, i);
            }
        }

        // function ro print array
        public static void Print_Array(int[] array, int size)
        {
            for(int i = 0; i < size; i++)
            Console.Write(Convert.ToString(array[i]) + " ");
            Console.WriteLine();
        }

        public static void Main(String[] args)
        {
            int[] array = {2, 4, 3, 1, 6, 8, 4};
            HeapSort(array, 7);
            Print_Array(array, 7);
            Console.ReadLine();
        }
    }
}

