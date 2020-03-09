/*
DIGIT COUNT OF A NUMBER

The task is to count the number of digits present in the given
number.
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

int main() {
    printf("Enter N: ");
    int n;
    scanf("%d", &n);
    printf("Number of digits is : %d", getDigits(n));
}

/*
INPUT : n = 6534
OUTPUT: Number of digits is : 4
*/
