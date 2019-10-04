/*
To check whether a number is a power of two or not,
we do bitwise "and" of number and number - 1, if the
result is zero the number is a power of two.
Example: number = 4, then 4 & 3 i.e 100 && 011 is 0
16 & 15 i.e 10000 & 01111 = 0
This is true for all powers of two.
*/

#include<stdio.h>

int isPowerOfTwo(int x)
{
    return x && (!(x & (x - 1)));
}

int main()
{
    int num;
    printf("Enter a number to check:\n");
    scanf("%d", &num);
    if (isPowerOfTwo(num))
        printf("The number is a power of two");
    else
        printf("The number is not a power of two");
    return 0;
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
