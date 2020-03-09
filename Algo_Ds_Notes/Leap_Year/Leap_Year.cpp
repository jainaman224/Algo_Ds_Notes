/*
Leap year is an year with 366 days. Leap Year should be divisible by 4.
Also it should be divisible by 400 and not divisible by 100.
*/

#include<bits/stdc++.h>
using namespace std;

bool checkLeapYear(int year)
{
    if (year % 400 == 0)
        return true;

    if (year % 100 == 0)
        return false;

    return year % 4 == 0;
}

void findLeapYears(int year1, int year2)
{
    cout<<"The leap years between "<<year1<<" and "<<year2<<" are:"<<endl;
    for (int i = year1; i <= year2; i++)
        if (checkLeapYear(i))
            cout<<i<<endl;
}

int main()
{
    int year1, year2;
    cout<<"Enter the first year:"<<endl;
    cin>>year1;
    cout<<"Enter the second year:"<<endl;
    cin>>year2;
    findLeapYears(year1, year2);
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
