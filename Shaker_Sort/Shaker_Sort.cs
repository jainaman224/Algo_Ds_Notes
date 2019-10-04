/*shaker sort*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ShakerSort
{
    class Program
    {
        static void Main()
        {
            /* psuedo data for array */
            int numberOfElements = 6;
            int[] arr = { 2, 10, 8, 1, 4, 1 };
            //call to  shaker sort function
            shakerSort(arr, numberOfElements - 1);
        }

        private static void shakerSort(int[] array, int length)
        {
            bool isSwaped;
            int i;

            do
            {
                /*variable for finding if any swaping happens sets to false first */
                isSwaped = false;
                /*first loop*/
                for (i = length - 1; i >= 0; i--)
                {
                    /* checks if any small number is caught  */
                    if (array[i + 1] < array[i])
                    {
                        /* swap the digits */
                        int temp;
                        temp = array[i + 1];
                        array[i + 1] = array[i];
                        array[i] = temp;
                        //sets the isSwaped to (true)
                        isSwaped = true;
                    }
                }
                /*loop in opposite direction to first one*/
                for (i = 0; i < length; i++)
                {
                    /* checks if any small number is caught  */
                    if (array[i + 1] < array[i])
                    {
                        /* swap the digits */
                        int temp;
                        temp = array[i + 1];
                        array[i + 1] = array[i];
                        array[i] = temp;
                        //sets the isSwaped to true
                        isSwaped = true;
                    }
                }

            } while (isSwaped);
            /*do-while loops ends if there is no swaping*/


            //prints sorted array
            Console.Write("sorted array is ");
            for (i = 0; i <= length; i++)
            {
                /* prints every element of array*/
                Console.Write(array[i] + " ");
            }
            Console.ReadKey();
        }
    }
}
/* sorted array is 1 1 2 4 7 8 */
