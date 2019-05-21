/*
Two integers a and b are said to be coprime if the only positive
integer that divides both of them is 1 i.e their greatest common
divisor or GCD is 1.
Example: 5 and 7, as gcd(5, 7) = 1
9 and 11, as gcd(9, 11) = 1
*/

import java.util.Scanner;

class Coprime_Numbers
{
    public static int gcd(int x, int y)
    {
        if (x == 0)
            return y;
        return gcd(y % x, x);
    }

    public static int isCoprime(int a, int b) 
    {
        if (gcd(a, b) == 1)
            return 1;
        return 0;
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter two numbers");
        int a = sc.nextInt();
        int b = sc.nextInt();
        int ans = isCoprime(a, b);
        if (ans == 1)
            System.out.println("The numbers are coprime");
        else
            System.out.println("The numbers are not coprime");
    }
}

/*
Input:
9
11

Output:
The numbers are coprime

Input:
4
12

Output:
The numbers are not coprime
*/
