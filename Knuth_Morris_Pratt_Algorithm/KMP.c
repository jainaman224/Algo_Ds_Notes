// Program to implement KnuthMorrisPratt Algorithm in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void KnuthMorrisPratt(const char* X, const char* Y, int m, int n)
{
    if (*X == '\0' || m < n)
        printf("Pattern is not found");

    if (*X == '\0' || m < n)
        printf("Pattern is not found");

    if (*Y == '\0' || n == 0)
        printf("Pattern with shift 0");

    int alternate[n + 1];

    for (int i = 0; i < n + 1; i++)
        alternate[i] = 0;

    for (int i = 1; i < n; i++)
    {
        int j = alternate[i + 1];
        while (j > 0 && Y[j] != Y[i])
            j = alternate[j];

        if (j > 0 || Y[j] == Y[i])
            alternate[i + 1] = j + 1;
    }

    for (int i = 0, j = 0; i < m; i++)
    {
        if (*(X + i) == *(Y + j))
        {
            if (++j == n)
                printf("Pattern occurs with shift %d\n", i - j + 1);
        }
        else if (j > 0) {
            j = alternate[j];
            i--;
        }
    }
}

// Program to implement KnuthMorrisPratt Algorithm in C
int main(void)
{
    char word[20];
    gets(word);

    char pattern[20];
    gets(pattern);

    int n = strlen(word);
    int m = strlen(pattern);

    KnuthMorrisPratt(word, pattern, n, m);

    return 0;
}

///Sample IP:
// BACPARKWRPARM
// PAR

///Sample OP:
// Pattern occurs with shift 3
// Pattern occurs with shift 9
