// Perfect number is a positive integer that is equal to the sum of its proper divisors.

#include <stdio.h>
 
int main()
{
    int num, sum = 0, i; 
    printf("Enter a Number: ");
    scanf("%d", &num);
    
    // Calculating the sum of divisors
    for (i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            sum = sum + i;
        }
    }
    if (sum == num)
        printf("It is a perfect number");
    else
        printf("It is not a perfect number");
    return 0;
}

/*
Enter a Number: 28
It is a perfect number */
