/*
To check whether a number is a power of two or not,
we do bitwise "and" of number and number - 1, if the
result is zero the number is a power of two.
Example: number = 4, then 4 & 3 i.e 100 && 011 is 0
16 & 15 i.e 10000 & 01111 = 0
This is true for all powers of two.
*/

using System;

class Main
{
    static bool isPowerOfTwo (int x)
    {
        return x != 0 && ((x & (x - 1)) == 0);
    }

    public static void Main()
    {
        Console.WriteLine(isPowerOfTwo(31) ? "The number is a power of two" : "The number is not a power of two"); 
        Console.WriteLine(isPowerOfTwo(64) ? "The number is a power of two" : "The number is not a power of two");
    }
}


/*
isPowerOfTwo(64)

Output:
The number is a power of two

isPowerOfTwo(31)

Output:
The number is not a power of two
*/