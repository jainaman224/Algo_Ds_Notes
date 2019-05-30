/*
To check whether a number is a power of two or not,
we do bitwise "and" of number and number - 1, if the
result is zero the number is a power of two.
Example: number = 4, then 4 & 3 i.e 100 && 011 is 0
16 & 15 i.e 10000 & 01111 = 0
This is true for all powers of two.
*/

import java.util.Scanner;

class Power_Of_Two
{
    public static boolean isPowerOfTwo(int x)
    {
        return (x > 0) && ((x & (x - 1)) == 0);
    }

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number to check:");
        int num = sc.nextInt();
        if (isPowerOfTwo(num))
            System.out.println("The number is a power of two");
        else
            System.out.println("The number is not a power of two");
    }
}

/*
Input:
64

Output:
The number is a power of two

Input:
5

Output:
The number is not a power of two
*/
