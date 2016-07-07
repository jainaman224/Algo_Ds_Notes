using System;

namespace Linear_Search
{
    class Program
    {
        public static int LinearSearch(int[] array, int size, int desired)
        {
            for (int i = 0; i < size; i++)
            {
                // return position if element is found
                if (array[i] == desired)
                    return i;
            }

            return -1;
        }

        // Driver Function
        public static void Main(String[] args)
        {
            int[] array = {2, 4, 6, 7, 3, 1, 5};

            // Element 4 to be searched
            if(LinearSearch(array, 7, 4) != -1)
                Console.WriteLine("Found");
            else
                Console.WriteLine("Not Found");

        //Element 9 to be searched
            if(LinearSearch(array, 7, 9) != -1)
                Console.WriteLine("Found");
            else
                Console.WriteLine("Not Found");
            Console.ReadLine();
        }
    }
}

/*
Output:
Found
Not Found
*/
