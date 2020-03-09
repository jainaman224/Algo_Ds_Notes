/*
A majority element in an array arr of size n is an
element that appears more than n/2 times.
Example: 
N = 9, arr = {1, 2, 2, 2, 4, 2, 2, 1, 5}
Majority Element = 2 as count[2] = 5 which is greater
than n/2 i.e 4
*/

#include<bits/stdc++.h>
using namespace std;

int checkMajorityElement(int arr[], int N)
{
    map<int, int> mp;
    // Computing frequency of each element using Map
    for (int i = 0; i < N; i++)
        mp[arr[i]]++;
    map<int, int> :: iterator it;
    for (it = mp.begin(); it != mp.end(); it++)
    {
        if (it -> second > (N / 2))
        return it -> first;
    }
    return -1;
}

int main()
{
    int N;
    cout<<"Enter size of array:"<<endl;
    cin>>N;
    int arr[N];
    cout<<"Enter elements of array:"<<endl;
    for (int i = 0; i < N; i++)
        cin>>arr[i];
    int ans = checkMajorityElement(arr, N);
    if (ans != -1)
        cout<<"Majority Element is: "<<ans<<endl;
    else
        cout<<"No majority element in array"<<endl;
    return 0;
}

/*
Input:
N = 9
arr = {1, 2, 2, 2, 4, 2, 2, 1, 5}

Output:
Majority Element is: 2

Input:
N = 5
arr = {1, 2, 3, 4, 5}

Output:
No majority element in array
*/
