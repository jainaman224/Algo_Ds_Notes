/*
SUM OF INFINITE GEOMETRIC PROGRESSION

Any sequence of elements where the quotient between any two
consecutive elements is equal is termed to be in G.P.
The nth term of an G.P. is defined as (a * r^(n-1))
where a is the first element of the G.P.
r is the common ratio of the G.P.
n is the number of term.

The Sum of infinite series of a G.P. is defined as :
a / (1 - r), where -1 < r < 1
*/

#include<math.h>
#include<stdio.h>

int main() {
    printf("Enter the First Term of G.P.");
    float a;
    scanf("%f", &a);
    printf("Enter the common ratio");
    float r;
    scanf("%f", &r);
    printf("The sum of infinite G.P. is %.1f", (a * 1.0/ (1 - r)));
}

/*
INPUT : a = 5
        r = 0.5
OUTPUT : The sum of infinite G.P. is 10.0
*/
