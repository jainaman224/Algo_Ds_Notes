// Calculating inverse using extended Euclidean algorithm iterative method
using System;

namespace Insertion_Sort
{
    class Program
    {
        public static int inverse(int a, int m)
        {
            int m0 = m;
            int x0 = 0;
            int x1 = 1;
            if (m == 1)
                return 0;

            int q, t;
            while (a > 1)
            {
                q = a / m;
                t = m;
                m = a % m;
                a = t;
                t = x0;
                x0 = x1 - q * x0;
                x1 = t;
            }
            if (x1 < 0)
                x1 += m0;
            return x1;
        }

        public static int findMinimumDividend(int[] divisor, int[] remainder)
        {
            int product = 1;
            int i, result, partialProduct;
            int len = divisor.GetLength(0);

            for (i = 0; i < len; i++)
                product *= divisor[i];

            result = 0;

            for (i = 0; i < len; i++)
            {
                partialProduct = product / divisor[i];
                result += remainder[i] * inverse(partialProduct, divisor[i]) * partialProduct;
            }
            return (result % product);
        }

        static void Main(String[] args)
        {
            int[] divisor = { 3, 4, 5, 7, 11 };
            int[] remainder = { 2, 3, 1, 4, 5 };
            int Result = findMinimumDividend(divisor, remainder);
            Console.WriteLine("Minimum value of dividend is : " + Convert.ToString(Result));
            Console.WriteLine();
            Console.ReadLine();
        }
    }
}

// Output
// Minimum value of dividend is : 3371
