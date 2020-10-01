/*
TOTAL SET BITS FROM 1 to N

Total set bits in a number n is defined as number of 1s in 
binary representation of the number. The task is to calculate
total number of set bits in all numbers till N.
*/

#include<stdio.h>

int setBits(int n) {
    int bit = 0;
    for (int i = 0; i < n; i++) {
        bit = bit + count(i);
    }
    return bit;
}

int count(int n) {
    int bit = 0;
    while(n > 0) {
        bit += n & 1;
        n >>= 1;
    }
    return bit;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("The total set bits are %d", setBits(n));
}

/*
INPUT :
n = 12
OUTPUT :
The total set bits are 20
*/
