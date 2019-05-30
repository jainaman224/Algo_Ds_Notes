/* The sum of digits of a number is the mathematical addition
of the digits extracted from the number.
Example: number = 12345, sum = 1 + 2 + 3 + 4 + 5 = 15
number = 1005, sum = 1 + 0 + 0 + 5 = 6 */

import java.util.Scanner;

class Sum_Of_Digits
{
    public static int sumOfDigits(int N)
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

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number:");
        int N = sc.nextInt();
        int ans = sumOfDigits(N);
        System.out.println("The sum of digits of " + N + " is " + ans);
    }
}

/*
Input:
12345

Output:
The sum of digits of 12345 is 15

Input:
1000

Output:
The sum of digits of 1000 is 1
*/
