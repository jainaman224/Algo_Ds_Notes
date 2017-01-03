using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Selection_Sort
{
    class Program
    {
            /// Function for selection sort
            static void Selection_Sort(int[] array, int size)
            {
                int min_index, temp;

                for(int i = 0; i < size - 1; i++)
                {
                    min_index = i;

                    for(int j = i + 1; j < size; j++)
                        if(array[j] < array[min_index])
                            min_index = j;

                    temp = array[i];
                    array[i] = array[min_index];
                    array[min_index] = temp;
                }
            }

        static void Main(string[] args)
        {
            int[] array = {2, 4, 3, 1, 6, 8, 4};
             Selection_Sort(array, 7);
             for (int k = 0; k < 7;k++ )
                 Console.Write(array[k]+" ");

             Console.ReadLine();

        }
    }
}
