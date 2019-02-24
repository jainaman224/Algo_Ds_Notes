#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_sum(vector<int> v)
{
    int n=(int)v.size();
    for(int i=1; i<n; i++)
        v[i]+=v[i-1];
    return v;
}

int main()
{
    ios::sync_with_stdio(false);
    vector<int> arr{10, 22, 9, 33, 21, 50, 41, 60};
    vector<int> v=prefix_sum(arr);
    cout<<"The prefix sum array for the given array is :\n";
    for(auto x:v)
        cout<<x<<" ";
}