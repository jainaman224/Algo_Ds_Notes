/*
Two integers a and b are said to be coprime if the only positive
integer that divides both of them is 1 i.e their greatest common
divisor or GCD is 1.
Example: 5 and 7, as gcd(5, 7) = 1
9 and 11, as gcd(9, 11) = 1
*/

#include <stdio.h>

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int isCoprime(int a, int b) 
{
    if (gcd(a, b) == 1)
        return 1;
    return 0;
}

int main() 
{
    int a, b;
    printf("Enter two numbers\n");
    scanf("%d%d", &a, &b);
    int ans = isCoprime(a, b);
    if (ans == 1)
        printf("The numbers are coprime");
    else
        printf("The numbers are not coprime");
    return 0;
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
