/*
    LEADERS OF AN ARRAY

    The task is to find all leaders in an array, where
    a leader is an array element which is greater than all the elements
    on its right side
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
    int maximum = a[num - 1];
    cout << "The following are the leaders of array : " << endl;
    cout << a[num - 1] << " ";
    for (int i = num - 2; i >= 0; i--) {
        if (a[i] > maximum) {
            cout << a[i] << " ";
        }
    }
}

/*
Input : num = 5
        Array = [13, 4, 12, 1, 5]
Output :
        The following are the leaders of array :
        5 12 13
*/
