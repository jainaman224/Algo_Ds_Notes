#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    vector<int> arr{10, 22, 9, 33, 21, 50, 41, 60};
    vector<int> v(1000001, 0);
    for(auto x:arr)
        v[x]++;
    cout<<"The sorted array is:\n";
    for(int i=0; i<1000001; i++)
        while(v[i]--)
            cout<<i<<" ";
}
