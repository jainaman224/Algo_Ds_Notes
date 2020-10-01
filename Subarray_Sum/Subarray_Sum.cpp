/*
    SUBARRAY SUM 

    The task is to find sum of all possible subarrays of an array.
    This can be done by finding all subarray by a brute force solution
    and then finding combined sum of them.
    An efficient solution gets us to the theory that every element 
    contributes (i+1)*(n-1) times in the required sum. We use this
    formula for the computation of sum.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int num;
    cout << "Enter the size of array : ";
    cin >> num;
    int a[num];
    cout << "Enter array elements";
    for (int i = 0; i < num; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < num; i++) {
        ans = ans + (a[i] * (num - i) * (i + 1));
    }
    cout << "The sum of all subarrays is : " << ans;
}

/*
Input : num = 4
        Array = [-1, -4, -5, 20]
Output :
        The sum of all subarrays is : 22
*/
