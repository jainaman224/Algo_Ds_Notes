/*
    Sum of First N Natural Numbers

    The task is to find sum of first n natural numbers, where n is 
    the number input to us. We use the well known formula,
    sum = n * (n + 1)/2 to compute the sum

*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int num;
    cout << "Enter N: ";
    cin >> num;
    int sum = num * (num + 1) / 2;
    cout << "The sum of first " << num << " natural numbers is : " << sum;
}

/*
    Input : num = 6
    Output : The sum of first 6 natural numbers is : 21
*/
