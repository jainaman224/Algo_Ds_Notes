// Perfect number is a positive integer that is equal to the sum of its proper divisors.

#include <iostream>
using namespace std;
 
int main()
{
    int num, rem, sum = 0, i; 
    cout << "Enter a Number: ";
    cin >> num;
    
    // Calculating the sum of divisors
    for (i = 1; i < num; i++)
    {
        rem = num % i;
        if (rem == 0)
        {
            sum = sum + i;
        }
    }
    if (sum == num)
        cout << "It is a perfect number";
    else
        cout << "It is not a perfect number";
    return 0;
}

/*
Enter a Number: 28
It is a perfect number */
