/*
FIBONACCI WORDS

It is a series of words where each word is formed by concatenation
of last two words.
where :
T(1) = 0
T(2) = 01

T(n) = T(n-1) + T(n-2)
*/

#include<stdio.h>
#include<string.h>

char* fibonacci[10000];

char* fibonacci_word(int n) {
    fibonacci[1] = "0";
    fibonacci[2] = "01";
    char *s = malloc(sizeof(char) * (100000 + 1));
    for (int i = 3; i <= n; i++) {
        s = malloc(sizeof(char) * (100000 + 1));
        strcat(s, fibonacci[i - 1]);
        strcat(s, fibonacci[i - 2]);
        fibonacci[i] = s;
    }
    if (n < 3) {
      return fibonacci[n];
    }
    return s;
}

int main() {
    int n;
    printf("Enter N: ");
    scanf("%d", &n);
    printf("The fibonacci word at position %d is: %s", n, fibonacci_word(n));
}

/*
INPUT : n = 5
OUTPUT: The tribonacci word at position 5 is: 1213121121312
*/
