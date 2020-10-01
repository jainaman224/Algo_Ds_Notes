/*
    PERFECT ARRAY

    An array which is strictly increasing and then constant, and then strictly 
    decreasing is called a perfect array.
    There should be no variations in between.

*/

#include<bits/stdc++.h>
using namespace std;

int perfect(int a[], int num) {
    int count = 1;
    while (count < num && a[count] > a[count - 1]) {
        count++;
    }
    while (count < num && a[count] == a[count - 1]) {
        count++;
    }
    while (count < num && a[count] < a[count - 1]) {
        count++;
    }
    if (count == num) {
        return 1;
    }
    return 0;
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
    if (perfect(a, num) == 1) {
        cout << "It is a perfect array";
    }
    else {
        cout << "It is not a perfect array";
    }
}

/*
    Input : num = 5
            Array : [1, 2, 3, 3, 6]
    Output : It is not a perfect array
*/
