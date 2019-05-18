/*
        SUM OF GEOMETRIC PROGRESSION

        Any sequence of elements where the quotient between any two
        consecutive elements is equal is termed to be in G.P.
        The nth term of an G.P. is defined as (a * r^(n-1))
        where a is the first element of the G.P.
        r is the common ratio of the G.P.
        n is the number of term.

        The Sum of G.P. is defined as a * (r^n - 1) / (r - 1)
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    cout << "Enter the First Term of G.P.";
    int a;
    cin >> a;
    cout << "Enter the common ratio";
    int r;
    cin >> r;
    cout << "Enter N (The total number of terms)";
    int n;
    cin >> n;
    cout << "The sum of first " << n << " terms of G.P. is " 
    << (a * (pow(r, n) - 1) / (r - 1));
}

/*
    INPUT : a = 5
            r = 2
            n = 7
    OUTPUT : The sum of first 7 terms of G.P. is 635
    VERIFICATION : The 7 terms of G.P. would be 5,10,20,40,80,160,320
                   Sum = 635
*/
