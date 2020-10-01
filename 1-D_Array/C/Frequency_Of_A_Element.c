#include<stdio.h>

int main()
{
    int num, arr[50], number;
    int i;

    printf("Enter number of elements in your array: ");
    scanf("%d", &num);

    printf("Enter your array: ");
    for (i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Frequency is how many times a number have occurred
    int f = 0;

    // Number whose frequency has to be found
    printf("Enter the number whose occurence is to be found: ");
    scanf("%d", &number);

    for (i = 0; i < num; i++)
    {
        if (arr[i] == number)
        {
            f = f + 1;
        }
    }

    printf("Frequency = %d", f);
}

/*
Enter number of elements in your array: 6
Enter your array: 1
2
3
3
4
3
Enter the number whose occurence is to be found: 3
Frequency = 3*/
