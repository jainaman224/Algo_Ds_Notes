using System;

namespace Interpolation_Search
{
    class Program
    {
        public static int interpolation(int[] a, int n, int search_item) // Function implementing Interpolation_Search
        {
            int high = n - 1;
            int low = 0;
            int pos;

            while(low <= high && search_item >= a[low] && search_item <= a[high])
            {
                int rise = high - low;
                int run = a[high] - a[low];
                int x = search_item - a[low];
                pos = low + (rise / run) * x;

                if(a[pos] == search_item)
                    return pos;
                else if(search_item < a[pos])
                    high = pos - 1;
                else if(search_item > a[pos])
                    low = pos + 1;
            }
            return -1;
        }

        public static void Main(String[] args)
        {
            int[] a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Sorted Input array
            int n = a.GetLength(0); // Size of array
            int search_item = 8; // Element to be searched
            int index = interpolation(a, n, search_item);

            if(index == -1)
                Console.WriteLine("Element not found");
            else
                Console.WriteLine("Found at position " + index);
            Console.WriteLine();
            Console.ReadLine();
        }
    }
}

/* Output

Found at position 7

*/
