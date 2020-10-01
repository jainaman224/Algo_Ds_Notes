/*
PARTITION PROBLEM

The problem is to identify if a given set of n elements can be divided
into two separate subsets such that sum of elements of both the subsets
is equal.
*/

#include<bits/stdc++.h>
using namespace std;

bool check(int a[], int sum, int ind) {
    if (sum == 0) {
        return true;
    }
    if (ind == -1 || sum < 0) {
        return false;
    }
    if (a[ind] > sum) {
        return check(a, sum, ind - 1);
    }
    return check(a, sum - a[ind], ind - 1) ||
    check(a, sum, ind - 1);
}

int main() {
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum = sum + a[i];
    }
    if (sum % 2 == 1) {
        cout << "Not Possible";
    }
    else {
        if (check(a, sum / 2, n - 1)) {
            cout << "Possible";
        }
        else {
            cout << "Not Possible";
        }
    }
}

/*
INPUT :
n = 4
a = [1, 4, 3, 2]
OUTPUT :
Possible
VERIFICATION :
Set can be divided into two sets :
[1, 4] and [3, 2], both of whose sum is 5.
*/
