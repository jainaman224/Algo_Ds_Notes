using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication3
{
    class Program
    {
        public static class  globalVar
        {
            public  static int flag = 1;
        }
        static void Main(string[] args)
        {
            
            
            Console.WriteLine("ENTER THE SIZE OF ARRAY :");
            string input = Console.ReadLine();
            int s = Convert.ToInt32(input);
      
            int []arr = new int[10000];
            int num;
            Console.WriteLine("\nENTER THE ARRAY : \n");



            for (int i = 0; i < s; i++)
            {
                Console.Write("\nENTER ELEMENT " + (i + 1)+"  :");
                arr[i] = int.Parse(Console.ReadLine());
            }
             Console.WriteLine("\nNOW ENTER THE NUMBER TO BE SEARCHED :");
             num = int.Parse(Console.ReadLine());
        
            int result = binarysearch(arr, s, num);
            
            if(globalVar.flag !=0 )
            {
                Console.WriteLine("\n NO SUCH ITEM FOUND !!!");

            }
            else

                Console.WriteLine("\nITEM FOUND AT LOCATION  :"+(result+1)); 
            Console.Read();
        }
        
        
        ///BINARY SEARCH 
        public static int binarysearch(int[] a, int size, int item)
        {
            int start = 0, end = size - 1, mid;
            globalVar.flag = 1;
            while (start <= end)
            {
                mid = (start + end) / 2;
                if (item == a[mid])
                {
                    globalVar.flag = 0;
                    return mid;}
                else if (item > a[mid])
                    start = mid + 1;
                else end = mid - 1;
            }
            return 0;

        }

    }

}
