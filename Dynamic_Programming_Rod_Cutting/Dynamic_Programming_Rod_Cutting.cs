using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dynamic_Programming_Rod_Cutting
{
    class Program
    {

        private static int max(int a , int b )
        {

            return (a > b) ? a : b;
        }
        private static int money( int []arr, int size)
        {
            if( size <= 0 )
            return 0 ;
            else
            {
                int max_val = Int32.MinValue;
                for (int i = 0; i < size; i++)
                    max_val = max(max_val, arr[i] + money(arr, size - i - 1));
                return max_val;
            }

            
        }
        static void Main(string[] args)
        {
            int [] arr = {1, 5, 8, 9, 10, 17, 17, 20};
            int size = arr.Length;
            Console.Write("MAximum Cost : " + money(arr, size));
            Console.Read();
            //output 22

        }
    }
}
