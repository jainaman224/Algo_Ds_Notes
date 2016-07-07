using System;

namespace Euclid_GCD
{
    class Program
    {
        public static int EuclidGCD(int a, int b)
        {
            if(b == 0)
                return a;
            else
                return EuclidGCD(b, a % b);
        }

       public static void Main (String[] args)
	     {
		       int	a = 315;
		       int	b = 105;
		       int	c = EuclidGCD(a,b);
		       Console.WriteLine(c);
          // prints 105
          // GCD of 315 and 105 is 105
           a = 30;
           b = 105;
           c = EuclidGCD(a,b);
           Console.WriteLine(c);
		      // prints 15
          // GCD of 30 and 105 is 15
           Console.WriteLine();
           Console.ReadLine();
	     }
   }
}

/*
Output:
  105
  15
*/
