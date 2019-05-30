// Taylor series using Horner Rule in c++

#include<bits/stdc++.h>
using namespace std;

// creating exponential function
double exponential (int x, int num)
{
    static double s; // declare static variable
    if (num == 0)   // Base case
    {
        return s;
    }
    s = 1 + x * (s / num); // formula of horner's rule
    return exponential (x, num - 1); // recursive case
}

// main method
int main ()
{
    int x, num;
    cin >> x >> num;
    double result = exponential (x, num);
    cout << result << endl; // x^num
}

/* Input:- 2 10
  Output:-
  7.388713
*/

