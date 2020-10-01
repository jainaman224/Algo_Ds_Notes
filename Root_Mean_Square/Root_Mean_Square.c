/*
ROOT MEAN SQUARE

Root Mean Square or RMS is known as quadratic mean of a given array.
It holds a lot of importance in mathematical calculations in various
domains like Physics and geometry.
*/

#include<stdio.h>

void RMS(int a[], int n, int index, int ans) {
    if (index == n) {
        ans = ans / n;
        printf("RMS of array is : %d", ans);
        return;
    }
    ans = ans + a[index] * a[index];
    RMS(a, n, index + 1, ans);
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    RMS(a, n, 0, 0);
}

/*
INPUT : n = 3
        a = [3, 15, 32]
OUTPUT :
RMS of array is : 419
*/
