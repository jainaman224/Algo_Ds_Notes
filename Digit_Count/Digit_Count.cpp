/*
DIGIT COUNT OF A NUMBER

The task is to count the number of digits present in the given
number.
*/

#include<bits/stdc++.h>
using namespace std;

int getDigits(int n) {
    int ans = 0;
    while (n) {
        ans ++;
        n /= 10;
    }
    return ans;
}

int main() {
    cout<<"Enter N: ";
    int n;
    cin>>n;
    cout<<"Number of digits is : "<<getDigits(n);
}

/*
INPUT : n = 6534
OUTPUT: Number of digits is : 4
*/
