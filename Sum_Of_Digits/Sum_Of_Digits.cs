/* The sum of digits of a number is the mathematical addition
of the digits extracted from the number.
Example: number = 12345, sum = 1 + 2 + 3 + 4 + 5 = 15
number = 1005, sum = 1 + 0 + 0 + 5 = 6 */

using System;

class Sum_Of_Digits
{
    public static void Main(string[] args)
    {
        Console.WriteLine("Enter number:");
        int N = int.Parse(Console.ReadLine());
        int ans = SumOfDigits(N);
        Console.WriteLine($"The sum of digits of {N} is {ans}");
        Console.ReadLine();
    }
    public static int SumOfDigits(int N)
    {
        int a, sum = 0;
        while (N > 0)
        {
            a = N % 10;
            sum += a;
            N /= 10;
        }
        return sum;
    }
}

/*
Input:
Enter Number:
12345

Output:
The sum of digits of 12345 is 15

Input:
Enter Number:
1000

Output:
The sum of digits of 1000 is 1
*/

