/* The sum of digits of a number is the mathematical addition
of the digits extracted from the number.
Example: number = 12345, sum = 1 + 2 + 3 + 4 + 5 = 15
number = 1005, sum = 1 + 0 + 0 + 5 = 6 */

#include<stdio.h>

int sumOfDigits(int N)
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

int main()
{
    int N;
    printf("Enter number:\n");
    scanf("%d", &N);
    int ans = sumOfDigits(N);
    printf("The sum of digits of %d is %d", N, ans);
    return 0;
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
