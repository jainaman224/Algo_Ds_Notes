#include <stdio.h>
#define MAX 256

int findmax(int a, int b)
{
    return (a > b) ? a : b;
}

void searchwrongchar(char *str, int size, int extra[MAX])
{
    for (int i = 0; i < MAX; ++i)
        extra[i] = -1;

    for (int i = 0; i < size; ++i)
        extra[(int)str[i]] = i;
}

void search(char *text, char *pattern)
{
    int patLen = strlen(pattern);
    int txtLen = strlen(text);

    int extra[MAX];

    searchwrongchar(pattern, patLen, extra);

    int s = 0;
    while (s <= (txtLen - patLen))
    {
        int j = patLen - 1;

        while (j >= 0 && pattern[j] == text[s + j])
            j--;

        if (j < 0)
        {
            printf("\n\nPattern Matches at shift of = %d.", s);
            s += (s + patLen < txtLen) ? patLen - extra[text[s + patLen]] : 1;
        }
        else
            s += findmax(1, j - extra[text[s + j]]);
    }
}

int main()
{
    char text[MAX], pattern[MAX];
    printf("Enter the Text: ");
    scanf("%s", &text);
    printf("\nEnter the Pattern to Match: ");
    scanf("%s", &pattern);
    search(text, pattern);
    return 0;
}

/*
INPUT:
Enter the Text: ABAAABCD
Enter the Pattern to Match: ABC

OUTPUT: 
Pattern match at shift = 4
*/
