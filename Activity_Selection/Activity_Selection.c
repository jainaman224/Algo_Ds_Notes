#include <stdio.h>

void print_activities(int start[], int finish[], int n)
{
    printf("Following activities are selected");
    int i = 0;
    printf("\n%d  ", i);
    int j;
    for (j = 1; j < n; j++)
    {
        if (start[j] >= finish[i])
        {
            printf("%d  ", j);
            i = j;
        }
    }
}

int main()
{
    int start[] = {1, 3, 1, 5, 8, 6};
    int finish[] = {2, 6, 6, 7, 10, 8};
    int n = sizeof(start) / sizeof(start[0]);
    print_activities(start, finish, n);
    return 0;
}

// Output
// Following activities are selected
// 0  1  4
