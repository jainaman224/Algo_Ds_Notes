/*
    EQUILIBRIUM INDEX OF AN ARRAY

    An equilibrium index is an index of an array, where the commulative sum 
    of all elements below it is equal to the commulative sum of all elements
    above it in that array.

*/

#include<bits/stdc++.h>
using namespace std;

int eq_index(int a[], int num) {
    int sum = 0;
    int sum_left = 0;
    for (int i = 0; i < num; i++) {
        sum = sum + a[i];
    }
    for (int i = 0; i < num; i++) {
        sum = sum - a[i];
        if (sum_left == sum) {
            return i;
        }
        sum_left = sum_left + a[i];
    }
    return -1;
}


int main() {
    int num;
    cout << "Enter length of array";
    cin >> num;
    cout << "Enter array elements :";
    int a[num];
    for (int i = 0; i < num; i++) {
        cin >> a[i];
    }
    cout << "The equilibrium index is : " << eq_index(a, num);
}

/*
    Input : num = 4
            Array : [12, 2, 6, 6]
    Output : The equilibrium index is : 1
*/
