using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication4
{
    class Program
    {

        
        public static void countingsort(int []a , int largest, int arrsize )
        {
            int size = largest + 1, val;
            int[] b= new int[size];
            for(int i=0 ; i<arrsize;i++)
            {
                 val = a[i];
                b[val] +=1;
            }
            int l = 0, r=0;
            int[] c = new int[arrsize];

            for (int j = 0; l < size; j++)
            {


                while (b[l] != 0)
                {
                    c[r] = l;
                    r++;
                    b[l]--;

                }
                l++;
            }
            Console.WriteLine("SORTED ARRAY IS :");
            for (int k = 0; k < arrsize; k++)
                Console.Write(c[k]+" ");




        }

        static void Main(string[] args)
        {


            Console.WriteLine("ENTER THE SIZE OF ARRAY :");
            string input = Console.ReadLine();
            int s = Convert.ToInt32(input);

            int[] arr = new int[10000];
           
            Console.WriteLine("\nENTER THE ARRAY : \n");
            int biggest=-1;


            for (int i = 0; i < s; i++)
            {
                Console.Write("\nENTER ELEMENT " + (i + 1) + "  :");
                arr[i] = int.Parse(Console.ReadLine());
                if (biggest <= arr[i])
                    biggest = arr[i];

            }
            countingsort(arr, biggest,s);
            Console.Read();
        }
    }
}
