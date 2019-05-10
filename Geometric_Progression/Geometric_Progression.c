/*
        GEOMETRIC PROGRESSION

        Any sequence of elements where the quotient between any two
        consecutive elements is equal is termed to be in G.P.
        The nth term of an G.P. is defined as (a * r^(n-1))
        where a is the first element of the G.P.
        r is the common ratio of the G.P.
*/

#include<stdio.h>
#include<math.h>

int main() {
    printf("Enter the First Term of G.P.");
    int a;
    scanf("%d", &a);
    printf("Enter the common ratio");
    int r;
    scanf("%d", &r);
    printf("Enter N (The index of term to find)");
    int n;
    scanf("%d", &n);
    printf("The term at index %d is %d ", n, (int)(a * pow(r, n - 1)));
}

/*
    INPUT : a = 5
            r = 2
            n = 7
    OUTPUT : The term at index 7 is 320
    VERIFICATION : The G.P. would be 5,10,20,40,80,160,320...
*/
