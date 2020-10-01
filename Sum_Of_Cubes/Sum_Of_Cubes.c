/*
    The sum of cubes of first N natural numbers is given
    by the equation (N * (N + 1) / 2) ^ 2 i.e.
    1^3 + 2^3 + 3^3 + 4^3 + 5^3.........N^3 sums upto
    (N * (N + 1) / 2) ^ 2
*/

#include<math.h>
#include<stdio.h>

int main() 
{
    int N;
    printf("Enter the value of N: \n");
    scanf("%d", &N);
    int ans = pow((N * (N + 1) / 2), 2);
    printf("%d", ans);
    return 0;
}

/*
Input:
N = 5

Output:
ans = 225

Verification:
1^3 + 2^3 + 3^3 + 4^3 + 5^3
= 1 + 8 + 27 + 64 + 125
= 225
*/
