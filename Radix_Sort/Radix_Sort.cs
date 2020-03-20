using System;
namespace Rextester
{
    class Program
    {
        static void Sort(int[] arr, int n)
        {
            int i, j;
            int[] tmp = new int[n];
            for (int shift = 31; shift > -1; --shift)
            {
                j = 0;
                for (i = 0; i < n; ++i)
                {
                    bool move = (arr[i] << shift) >= 0;
                    if (shift == 0 ? !move : move)   
                        arr[i-j] = arr[i];
                    else                             
                        tmp[j++] = arr[i];
                }
                Array.Copy(tmp, 0, arr, n-j, j);
            }
        }
        
        public static void Main(string[] args)
        {
            
            int n=Convert.ToInt32(Console.ReadLine());//input size of array
            int []arr=new int[n];//initializing array of size n
            Console.WriteLine("\nOriginal array : ");
            for(int i=0;i<n;i++){
                arr[i] = Convert.ToInt32(Console.ReadLine());//input value in array
                Console.Write(" " + arr[i]); 
            }
            Sort(arr, n);
            Console.WriteLine("\nSorted array : ");
            foreach (var item in arr)
            {
                 Console.Write(" " + item);    
            }
            Console.WriteLine("\n");
        }
    }
}
/*
Input:
10
2 
5 
-4 
11 
0 
18 
22 
67 
51 
6

Output:
Sorted array : 
 -4 0 2 5 6 11 18 22 51 67
*/
