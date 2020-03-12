#include <bits/stdc++.h>
using namespace std;
#define d (1<<n)-1
int cnt=0;

//This is an optimised approach than the normal backtracking approach. 
//Here we don’t need to write is Safe Positon Function which works in linear time instead we use bitsets which work in O(1) time.

void innerrecurse(int row,int left,int right,int n)
{
    if(row==d)
    {
        cnt++;
        return;
    }
    int pos = d & ~(left|row|right);
    while(pos > 0)
    {
        int bit = pos & (-pos);
        pos -= bit;
        innerrecurse(row|bit, (left|bit)<<1, (right|bit)>>1,n);
    }
}

int main() {
    int n;
    cin>>n;
    innerrecurse(0,0,0,n);
    cout<<cnt;
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
