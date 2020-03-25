#include <bits/stdc++.h>
using namespace std;
int dp[1 << 20][2];
int findMinTime(int leftmask, bool turn, int arr[], int &n)
{
    if (!leftmask)
        return 0;

    int &res = dp[leftmask][turn];
    if (~res)
        return res;

    int rightmask = ((1 << n) - 1) ^ leftmask;
    if (turn == 1)
    {
        int minRow = INT_MAX, person;
        for (int i = 0; i < n; ++i)
        {
            if (rightmask & (1 << i))
            {
                if (minRow > arr[i])
                {
                    person = i;
                    minRow = arr[i];
                }
            }
        }
        res = arr[person] + findMinTime(leftmask | (1 << person),
                                        turn ^ 1, arr, n);
    }
    else
    {
        if (__builtin_popcount(leftmask) == 1)
        {
            for (int i = 0; i < n; ++i)
            {
                if (leftmask & (1 << i))
                {
                    res = arr[i];
                    break;
                }
            }
        }
        else
        {
            res = INT_MAX;
            for (int i = 0; i < n; ++i)
            {
                if (!(leftmask & (1 << i)))
                    continue;

                for (int j = i + 1; j < n; ++j)
                {
                    if (leftmask & (1 << j))
                    {
                        int val = max(arr[i], arr[j]);
                        val += findMinTime(leftmask ^ (1 << i) ^ (1 << j),
                                           turn ^ 1, arr, n);
                        res = min(res, val);
                    }
                }
            }
        }
    }
    return res;
}
int findTime(int arr[], int n)
{
    int mask = (1 << n) - 1;
    memset(dp, -1, sizeof(dp));

    return findMinTime(mask, 0, arr, n);
}
int main()
{
    int n, arr[n];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << findTime(arr, n);
    return 0;
}