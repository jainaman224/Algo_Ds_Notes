using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication5
{
    class Program
    {

    //Bubble Sort 
       static  void Bubble_Sort(int []array, int size)
    {
        int temp;

        for(int i = 0; i < size - 1; i++)
        {
            for(int j = 0; j < size - i - 1; j++)
                {
                    ///Do swapping
                        if(array[j] > array[j + 1])
                        {
                                temp = array[j];
                                array[j] = array[j + 1];
                                array[j + 1] = temp;
                            }
                        }

        }

        Console.WriteLine("SORTED ARRAY IS :");
        for (int k = 0; k < size; k++)
        Console.Write(array[k] + " ");

    }
        static void Main(string[] args)
        {

            Console.WriteLine("ENTER THE SIZE OF ARRAY :");
            string input = Console.ReadLine();
            int s = Convert.ToInt32(input);

            int[] arr = new int[10000];

            Console.WriteLine("\nENTER THE ARRAY : \n");
            int biggest = -1;


            for (int i = 0; i < s; i++)
            {
                Console.Write("\nENTER ELEMENT " + (i + 1) + "  :");
                arr[i] = int.Parse(Console.ReadLine());
                if (biggest <= arr[i])
                    biggest = arr[i];

            }

            Bubble_Sort(arr, s);
            Console.Read();

        }
    }
}
