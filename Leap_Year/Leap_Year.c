/*
Leap year is an year with 366 days. Leap Year should be divisible by 4.
Also it should be divisible by 400 and not divisible by 100.
*/

#include<stdio.h>

int checkLeapYear(int year)
{
    if (year % 400 == 0)
        return 1;

    if (year % 100 == 0)
        return 0;

    if (year % 4 == 0)
        return 1;

    return 0;
}

int main()
{
    int year1, year2;
    printf("Enter the first year:\n");
    scanf("%d", &year1);
    printf("Enter the second year year:\n");
    scanf("%d", &year2);
    printf("The leap years between %d and %d are: \n", year1, year2);
    for (int i = year1; i <= year2; i++)
    {
        if (checkLeapYear(i))
            printf("%d\n", i);
    }
    return 0;
}

/*
Input:
2000
2050

Output:
The leap years between 2000 and 2050 are:
2000
2004
2008
2012
2016
2020
2024
2028
2032
2036
2040
2044
2048
*/
