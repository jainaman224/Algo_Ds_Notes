#include <bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
#define d (1 << n) - 1
int cnt = 0;

//This is an optimised approach than the normal backtracking approach. 
//Here we don’t need to write is Safe Position Function 
//which works in linear time instead we use bitsets which work in O(1) time.

void solve(int row, int left, int right, int n)
{
    //All rows are occupied,so the solution must be complete
    if(row == d)
=======
#define d (1<<n)-1
int cnt=0;

//This is an optimised approach than the normal backtracking approach. 
//Here we don’t need to write is Safe Positon Function which works in linear time instead we use bitsets which work in O(1) time.

void solve(int row,int left,int right,int n)
{
    //All rows are occupied,so the solution must be complete
    if(row==d)
>>>>>>> 42bb684... Backtracking using Bitmasking
    {
        cnt++;
        return;
    }

    //Gets a bit sequence with "1"s whereever there is an open "slot"
<<<<<<< HEAD
    int pos = d & ~(left | row | right);
=======
    int pos = d & ~(left|row|right);
>>>>>>> 42bb684... Backtracking using Bitmasking

    //Loops as long as there is a valid place to put another queen.
    while(pos > 0)
    {
        int bit = pos & (-pos);
        pos -= bit;
<<<<<<< HEAD
        solve(row | bit, (left | bit) << 1, (right | bit) >> 1, n);
=======
        solve(row|bit, (left|bit)<<1, (right|bit)>>1,n);
>>>>>>> 42bb684... Backtracking using Bitmasking
    }
}

int main() {
    int n;
<<<<<<< HEAD
    cin >> n;
    solve(0, 0, 0, n);
    cout << cnt;
=======
    cin>>n;
    solve(0,0,0,n);
    cout<<cnt;
>>>>>>> 42bb684... Backtracking using Bitmasking
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
<<<<<<< HEAD
*/
=======
*/
>>>>>>> 42bb684... Backtracking using Bitmasking
