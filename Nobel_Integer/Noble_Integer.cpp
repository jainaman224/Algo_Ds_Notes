/*An integer x is said to be Noble given an array if the 
number of integers greater than x are equal to x. 
If there are many Noble integers, any of them is returned. 
If there is no noble integer, then return -1.*/

#include<bits/stdc++.h>
using namespace std;

int Noble(vector<int> &A) {
    int n = A.size();
    if (n == 0) {
        return -1;
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < n - 1; i++) {
        if (A[i] == A[i + 1]) {
            continue;
        }
        if (A[i] == n - (i + 1)) {
            return A[i];
        }
    }
    if (A[n - 1] == 0) {
        return A[n - 1];
    }
    return -1;
}

int main () 
{
    int n, x;
    cout << "Enter the size of array : ";
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> x;
        A.push_back(x);
    }
    cout << "Noble Integer = " << Noble(A);

    return 0;
}

/*
Input :
Enter the size of array : 6
3 2 5 6 1 4
Output :
Noble Integer = 3

Input : 
Enter the size of array : 3
2 2 2
Output :
Noble Integer = -1
*/
