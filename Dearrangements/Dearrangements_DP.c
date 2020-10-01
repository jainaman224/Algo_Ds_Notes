/*
DEARRANGEMENTS

It is a permutation of N elements such that no element appears in 
its original position.
We have to find the number of such permutations possible.

If count(n) = no of dearrangements for n numbers,
we use the generic formula 
count(n) = (n - 1) * [count(n - 1) + count(n - 2)]
*/

#include<stdio.h>

int dearrangement[10000];

int count(int number) {
    dearrangement[0] = 1;
    dearrangement[1] = 0;
    dearrangement[2] = 1;

    for (int i = 3; i <= number; i++) {
        dearrangement[i] = (i - 1) * 
        (dearrangement[i - 1] + dearrangement[i - 2]);
    }
    return dearrangement[number];
}

int main() {
    int number;
    scanf("%d", &number);
    int dearrangements = count(number);
    printf("The number of dearrangements is %d", dearrangements);
}

/*
INPUT : n = 6
OUTPUT: The number of dearrangements is 265
*/
