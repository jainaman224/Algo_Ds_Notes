/*
Leap year is an year with 366 days. Leap Year should be divisible by 4.
Also it should be divisible by 400 and not divisible by 100.
*/

import java.util.Scanner;

class Leap_Year
{
    public static boolean checkLeapYear(int year) 
    {
        if (year % 400 == 0)
            return true;

        if (year % 100 == 0)
            return false;

        return year % 4 == 0;
    }

    public static void main(String []args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter first year: ");
        int year1 = sc.nextInt();
        System.out.println("Enter second year: ");
        int year2 = sc.nextInt();
        System.out.println("The leap years between " + year1 + 
                            " and " + year2 + " are :");
        for (int i = year1; i <= year2; i++)
        {
            if (checkLeapYear(i))
                System.out.println(i);
        }
    }
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
