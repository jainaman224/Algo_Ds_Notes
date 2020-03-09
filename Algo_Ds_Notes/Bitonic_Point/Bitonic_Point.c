/*
BITONIC POINT

Given an array. The task is to find the bitonic point of the array.
The bitonic point in an array is the index before which all the numbers
are in increasing order and after which, all are in decreasing order.
*/

#include<stdio.h>

int bitonic(int a[], int n) {
    int l = 1;
    int r = n - 2;
    while(l <= r) {
        int m = (l + r) / 2;
        if (a[m] > a[m - 1] && a[m + 1] < a[m]) {
            return m;
        }
        if (a[m] < a[m + 1]) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int point = bitonic(a, n);
    if (point == -1) {
        printf("There is no bitonic point");
    }
    else {
        printf("The bitonic point is %d", point);
    }
}

/*
INPUT :
n = 6
a = [1 4 8 4 2 1]
OUTPUT :
The bitonic point is 2
*/
