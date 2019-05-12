/*
        ARITHMETIC PROGRESSION

        Any sequence of elements where the difference between any two 
        consecutive elements is equal is termed to be in A.P.
        The nth term of an A.P. is defined as (a + (n - 1)*d)
        where a is the first element of the A.P.
        d is the common difference of the A.P.
*/

#include<stdio.h>

// To find sum of the arithmetic progression
int SumOfAP(int a, int d, int n) 
{ 
    int sum = 0; 
    for (int i = 0; i < n; i++) 
    { 
        sum = sum + a; 
        a = a + d; 
    } 
    return sum; 
}

int main() {
    printf("Enter the First Term of A.P.");
    int a;
    scanf("%d", &a);
    printf("Enter the common difference");
    int d;
    scanf("%d", &d);
    printf("Enter N (The index of term to find)");
    int n;
    scanf("%d", &n);
    printf("The term at index %d is %d ", n, (a + (n - 1) * d));
    printf("\nSum is: %d", SumOfAP(a, d, n));
}

/*
    INPUT : a = 5
            d = 2
            n = 7
    OUTPUT : The term at index 7 is 17
             Sum is: 77
    VERIFICATION : The A.P. would be 5,7,9,11,13,15,17...
*/
