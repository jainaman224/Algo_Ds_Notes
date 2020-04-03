/*Given an integer array A of size N,find and return
the minimum absolute difference between any two elements in the array.
The absolute difference between two elements ai, and aj (where i != j ) is |ai - aj|*/

#include<bits/stdc++.h>
#include <iostream>
#include<algorithm>
using namespace std;

int minAbsoluteDiff(int arr[], int n)
{
    std::sort(arr, arr + n);
    int mindiff = INT_MAX;
    for(int i = 0; i < n - 1; i++)
    {
        if(abs(arr[i] - arr[i + 1] ) < mindiff)
            mindiff = abs(arr[i] - arr[i + 1]);
    }
    return mindiff;
}

int main()
{
    int size;
    cin >> size;
    int *input = new int[1 + size];

    for(int i = 0; i < size; i++)
        cin >> input[i];
    cout << minAbsoluteDiff(input, size) << endl;
    return 0;
}

/* Input : 5
           2 9 0 4 5

   Output : 1
*/
