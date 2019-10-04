/*
CYCLIC PERMUTATIONS

Cyclic permutations of a number are defined as a number that
can be obtained by rotating the concerned number any number 
of times between it's digits.
*/

#include<math.h>
#include<stdio.h>

int getDigits(int n) {
    int ans = 0;
    while (n) {
        ans ++;
        n /= 10;
    }
    return ans;
}

void cyclic(int n) {
    int length = getDigits(n);
    int res = n;
    while (1) {
        printf("%d\n", res);
        int remainder = res % 10;
        int quotient = res / 10;
        res = remainder * pow(10, length - 1) + quotient;
        if (res == n) {
            break;
        }
    }
}

int main() {
    printf("Enter N:");
    int n;
    scanf("%d", &n);
    cyclic(n);
}

/*
INPUT : n = 6534
OUTPUT: 6534
        4653
        3465
        5346
*/
