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
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c.
        arr.push_back(c);
    }
    vector<int> v=prefix_sum(arr);
    cout<<"The prefix sum array for the given array is :\n";
    for(auto x:v)
        cout<<x<<" ";
}
