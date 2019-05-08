/*
        LENGTH OF LONGEST ALTERNATING SUBARRAY

        Given an array of non-zero integers. We need to find the maximum 
        possible length of a subarray such that it has alternating positive
        and negative elements.
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
    int result = 1;
    int count = 1;
    cout << "The length of longest alternating subarray is : ";
    for (int i = 1; i < num; i++) {
        if (a[i] * a[i - 1] < 0) {
            count = count + 1;
            if (count > result) {
                result = count;
            }
        }
        else {
            count = 1;
        }
    }
    cout << result;
}

/*
Input :
num = 4
Array = [-1, -4, -5, 20]

Output :

The length of longest alternating subarray is : 2
*/
