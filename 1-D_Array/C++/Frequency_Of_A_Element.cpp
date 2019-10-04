#include <iostream>
#include <math.h>

using namespace std; 
int main()
{
    int num, arr[50], number;
    int i;

    cout << "Enter number of elements in your array: ";
    cin >> num;

    cout << "Enter your array: ";
    for (i = 0; i < num; i++)
    {
        cin  >> arr[i];
    }

    // Frequency is how many times a number have occurred
    int f = 0;

    // Number whose frequency has to be found
    cout << "Enter the number whose occurence is to be found: ";
    cin >> number;

    for (i = 0; i < num; i++)
    {
        if (arr[i] == number)
        {
            f = f + 1;
        }
    }

    cout << "Frequency = " << f;
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
