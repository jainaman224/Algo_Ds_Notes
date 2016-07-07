using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//The namespace refers to the project name you are working on.
namespace BinarySearch
{
    class Program
    {
       
        public static int Binary_Search(int[] array, int size, int desired)
        {
            int left = 0, right = size - 1, middle;

            while(left<=right)
            {
                middle = left + (right - left) / 2;
                
                if(array[middle] == desired)
                    return middle;
                else if(desired < array[middle])
                    right = middle - 1;
                else if(desired > array[middle])
                    left = middle + 1;
            }
            return -1;
         }

        static void Main(string[] args)
        {
            int [] array = { 1, 2, 3, 4, 5, 6, 7};

            

            //Element 4 to be searched
            if (Binary_Search(array, 7, 4) != -1)
                Console.WriteLine("Found");
            else
                Console.WriteLine("Not Found");

            //Element 9 to be searched
            if(Binary_Search(array, 7, 9) != -1)
                Console.WriteLine("Found");
            else
                Console.WriteLine("Not Found"); ;

            Console.ReadLine(); //To hold output (optional)
        }
    }
}
