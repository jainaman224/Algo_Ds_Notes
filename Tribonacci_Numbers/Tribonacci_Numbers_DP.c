/*
TRIBONACCI NUMBERS

It is a series of numbers where each term is the sum of preceeding 3
numbers of the sequence.

T(n) = T(n-1) + T(n-2) + T(n-3)
*/

#include<stdio.h>

int trib[10000];

int tribonacci(int n) {
    int x = n - 3;
    if (x < 0) {
        return trib[n] = 0;
    }
    if (x == 0) {
        return trib[n] = 1;
    }
    if (trib[n] != -1) {
        return trib[n];
    }
    return trib[n] = (tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3));
}

void init() {
    for (int i = 0; i < 10000; i++) {
        trib[i] = -1;
    }
}

int main() {
    init();
    int n;
    printf("Enter N: ");
    scanf("%d", &n);
    printf("The tribonacci number at position %d is: %d", n, tribonacci(n));
}

/*
INPUT : n = 6
OUTPUT: The tribonacci number at position 6 is: 4
VERIFICATION: The tribonacci series : 0 0 1 1 2 4
*/
