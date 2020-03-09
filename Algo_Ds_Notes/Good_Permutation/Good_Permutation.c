/*
GOOD PERMUTATION

A good permutation of a natural number N, is an arrangement
of first N natural numbers such that,
No number is present at it's position ( A[i] != i)
and
The value of a position is the index where the position is 
present as a value. ( A[A[i]] = i )

When such a permutation is not present, we print -1.
When we look at the second requirement, we find that if we
swap the consecutive numbers, we are able to satisfy the 
requirements. When N is odd, the swaps can not be possible.
Hence, we print -1.
*/

#include<math.h>
#include<stdio.h>

void permute(int n) {
    if (n % 2) {
        printf("-1");
    }
    else {
        for (int i = 0; i < n; i++) {
            if (i % 2) {
                printf("%d ", i);
            }
            else {
                printf("%d ", i + 2);
            }
        }
    }
}

int main() {
    printf("Enter N: ");
    int n;
    scanf("%d", &n);
    permute(n);
}

/*
    INPUT : n = 6
    OUTPUT : 2 1 4 3 6 5
*/
