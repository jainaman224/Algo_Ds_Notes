using System;

namespace Extended_Euclidean_GCD
{
    class Program
    {
        public static int gcdFunction(int a, int b, int x, int y)
        {
            if (a == 0)
            {
                x = 0;
                y = 0;
                return b;
            }
            int x1 = 0;
            int y1 = 0;
            int gcd = gcdFunction(b % a, a, x1, y1);
            x = y1 - (b / a) * x1;
            y = x1;
            return gcd;
        }

        public static void Main(String[] args)
        {
            int a = 98;
            int b = 21;
            int x = 0;
            int y = 0;
            Console.WriteLine("GCD of numbers " + Convert.ToString(a) + " and " + Convert.ToString(b) + " is " + Convert.ToString(gcdFunction(a, b, x, y)));

            Console.WriteLine();
            Console.ReadLine();
        }
    }
}

// Output
// GCD of numbers 98 and 21 is 7
