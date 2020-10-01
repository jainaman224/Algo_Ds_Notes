/*
LUCAS NUMBERS

These numbers are similar to Fibonacci Numbers. The only difference
is that the first two terms are 2 and 1.
*/

#include<stdio.h>

int lucas(int n) {
    int a[n];
    a[0] = 2;
    a[1] = 1;
    for (int i = 2; i < n; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[n - 1];
}

int lucas_recursive(int n) {
    if (n == 1) {
        return 2;
    }
    if (n == 2) {
        return 1;
    }
    return lucas_recursive(n - 1) + lucas_recursive(n - 2);
}

int main() {
    int number;
    scanf("%d", &number);
    printf("The Lucas number at position %d is %d", number, lucas(number));
}

/*
INPUT :
n = 8
OUTPUT :
The Lucas number at position 8 is 29
*/
