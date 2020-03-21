#include <bits/stdc++.h>
using namespace std;

#define d (1 << n) - 1
int cnt = 0;

/*This is an optimised approach than the normal backtracking approach.
Here we don’t need to write is Safe Position Function
which works in linear time instead we use bitsets which work in O(1) time.*/

void solve(int row, int left, int right, int n)
{
    //All rows are occupied,so the solution must be complete
    if(row == d)
    {
        cnt++;
        return;
    }

    //Gets a bit sequence with "1"s whereever there is an open "slot"
    int pos = d & ~(left | row | right);

    //Loops as long as there is a valid place to put another queen.
    while(pos > 0)
    {
        int bit = pos & (-pos);
        pos -= bit;
        solve(row | bit, (left | bit) << 1, (right | bit) >> 1, n);
    }
}

int main() {
    int n;
    cin >> n;
    solve(0, 0, 0, n);
    cout << cnt;
}

/*
Sample Input:
4
Sample Output:
2
Sample Input:
5
Sample Output:
10
*/