/*
JOLLY JUMPER SEQUENCE

If the set of differences of consecutive elements of the sequence
varies from 1 to n - 1, the sequence formed is said to be Jolly Jumper
Sequence.
*/

#include<stdio.h>
#include<math.h>

int Jolly(int a[], int n) {
    int check[n];
    for (int i = 0; i < n; i++) {
        check[i] = 0;
    }
    for (int i = 1; i < n; i++) {
        int x = abs(a[i] - a[i - 1]);
        if (x == 0 || x > n - 1 || check[x] == 1) {
            return 0;
        }
        check[x] = 1;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    if (Jolly(a, n)) {
        printf("It is a jolly jumper sequence");
    }
    else {
        printf("It is not a jolly jumper sequence");
    }
}

/*
INPUT :
n = 6
a = [14 9 13 12 10 7]
OUTPUT :
It is a jolly jumper sequence
*/
