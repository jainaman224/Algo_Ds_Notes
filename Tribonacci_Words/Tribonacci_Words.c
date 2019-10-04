/*
TRIBONACCI WORDS

It is a series of words where each word is formed by concatenation
of last three words.
where :
T(1) = 1
T(2) = 12
T(3) = 1213

T(n) = T(n-1) + T(n-2) + T(n-3)
*/

#include<stdio.h>
#include<string.h>

char* tribonacci[10000];

char* tribonacci_word(int n) {
    tribonacci[1] = "1";
    tribonacci[2] = "12";
    tribonacci[3] = "1213";
    char *s = malloc(sizeof(char) * (100000 + 1));
    for (int i = 4; i <= n; i++) {
        s = malloc(sizeof(char) * (100000 + 1));
        strcat(s, tribonacci[i - 1]);
        strcat(s, tribonacci[i - 2]);
        strcat(s, tribonacci[i - 3]);
        tribonacci[i] = s;
    }
    if (n < 4) {
        return tribonacci[n];
    }
    return s;
}

int main() {
    int n;
    printf("Enter N: ");
    scanf("%d", &n);
    printf("The tribonacci word at position %d is: %s", n, tribonacci_word(n));
}

/*
INPUT : n = 5
OUTPUT: The tribonacci word at position 5 is: 1213121121312
*/
