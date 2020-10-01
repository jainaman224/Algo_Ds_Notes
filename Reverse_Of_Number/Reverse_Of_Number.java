/* Reverse of a number is the number obtained when we read 
the original number backwards. 
Example: number = 12345, reverse = 54321
number = 1005, reverse = 5001 */

import java.util.Scanner;

class Reverse_Of_Number
{
    // function to reverse a number
    public static int reverse(int N)
    {
        int a, rev = 0;
        while (N > 0)
        {
            a = N % 10;
            rev = rev * 10 + a;
            N /= 10;
        }
        return rev;
    }

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number to reverse:");
        int N = sc.nextInt();
        int ans = reverse(N);
        System.out.println("The reverse of " + N + " is " + ans);
    }
}

/* 
Input:
12345

Output:
The reverse of 12345 is 54321

Input:
1000

Output:
The reverse of 1000 is 1
*/
