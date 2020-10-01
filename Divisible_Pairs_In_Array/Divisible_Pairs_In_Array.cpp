/*
        DIVISIBLE PAIRS IN AN ARRAY

        The problem is to find all pairs of numbers in an array, such that
        one of those numbers divides the other.
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
    cout << "The following are the divisible pairs :"<<endl;
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            if (a[i] % a[j] == 0 || a[j] % a[i] == 0) {
                cout << a[i] << " " << a[j] << endl;
            }
        }
    }
}

/*
Input :
num = 4
Array = [1, 4, 5, 20]

Output : 

The following are the divisible pairs :
1 4
1 5
1 20
4 20
5 20
*/
