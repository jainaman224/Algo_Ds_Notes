#include <bits/stdc++.h>

using namespace std;

int lis(vector<int> const arr)
{
        int n=arr.size();

        // array that contains the longest increasing subsequence until element i
        vector<int> lis(arr.size());

        for (int i=0; i < n; ++i) {
                lis[i]=1;
        }

        int ans=-1<<30; // length of the lis starts with -infinite

        for (int i=1;i<n;++i) {
                for (int j=0; j < i; ++j) {
                        if (arr[j]<arr[i]) {
                                lis[i]=max(lis[i], lis[j]+1);
                                ans=max(ans, lis[i]);
                        }
                }
        }

        return ans;
}

int main()
{
        ios::sync_with_stdio(false);

        // arr = array of elements
        vector<int> arr{10, 22, 9, 33, 21, 50, 41, 60};

        cout << "Size of the longest increasing subsequence: " << lis(arr) << "\n";
}
