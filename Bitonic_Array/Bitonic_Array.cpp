/* A Bitonic Sequence is a sequence of numbers which is first
strictly increasing then after a point strictly decreasing.
Example: -10, 0, 3, 5, 15, 13, 7, 2 */

#include<bits/stdc++.h>
using namespace std;

int isBitonic(int arr[], int N)
{
    if (arr[0] > arr[1])
        return -1;

    int i, j;
    for (i = 2; i < N; i++) 
    { 
        if (arr[i - 1] >= arr[i]) 
            break;
    } 

    if (i == N - 1) 
        return 1; 
 
    for (j = i + 1; j < N; j++) 
    {
        if (arr[j - 1] <= arr[j])
            break;
    } 
    
    if (j != N) 
        return -1; 
  
    return 1; 
} 

int main()
{
    cout<<"Enter number of elements in array"<<endl;
    int N;
    cin>>N;
    cout<<"Enter elements of array"<<endl;
    int arr[N];
    for (int i = 0; i < N; i++)
        cin>>arr[i];
    int ans = isBitonic(arr, N);
    if (ans == -1)
        cout<<"The array is not bitonic"<<endl;
    else
        cout<<"The array is bitonic"<<endl;
    return 0;
}

/*
Input:
N = 5
arr = {0, 1, 2, 3, 4}

Output:
The array is not bitonic

Input:
N = 5
arr = {0, 2, 4, 3, 1}

Output:
The array is bitonic

Input:
N = 5
arr = {4, 3, 2, 1, 0}

Output:
The array is not bitonic
*/
