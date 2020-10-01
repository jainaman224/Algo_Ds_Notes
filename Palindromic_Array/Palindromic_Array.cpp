/* A Palindromic Sequence is a sequence of numbers which is
the same when read both forward and backward.
Example: 1, 2, 3, 2, 1 */

#include <bits/stdc++.h>
using namespace std;

bool isPalindromic(int arr[], int N) {
    for (int i = 0; i <= (N / 2); i++) {
    if (arr[i] != arr[N - i - 1])
        return false;
    }
    return true;
}

int main() {
    cout << "Enter number of elements in array" << endl;
    int N;
    cin >> N;
    cout << "Enter elements of array" << endl;
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    if (isPalindromic(arr, N))
        cout << "The array is palindromic" << endl;
    else
        cout << "The array is not palindromic" << endl;
    return 0;
}

/*
Input:
N = 5
arr = {0, 1, 2, 3, 4}

Output:
The array is not palindromic

Input:
N = 6
arr = {0, 2, 4, 4, 2, 0}

Output:
The array is palindromic
*/
