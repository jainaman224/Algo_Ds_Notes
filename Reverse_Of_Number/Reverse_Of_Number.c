/* Reverse of a number is the number obtained when we read 
the original number backwards. 
Example: number = 12345, reverse = 54321
number = 1005, reverse = 5001 */

#include<stdio.h>

// function to reverse a number
int reverse(int N)
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

int main()
{
    int N;
    printf("Enter number to reverse:\n");
    scanf("%d", &N);
    int ans = reverse(N);
    printf("The reverse of %d is %d", N, ans);
    return 0;
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
