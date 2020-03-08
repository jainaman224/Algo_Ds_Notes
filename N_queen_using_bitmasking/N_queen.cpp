#include<bits/stdc++.h>
using namespace std;

const int N = 100;
bitset<N> col,d1,d2;

char board[N][N];

void show(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<board[i][j];
        cout<<endl;
    }
    cout<<endl;
}


void N_queen(int r,int n)
{
    if(r==n)
    { 
        show(n); 
        return; 
    }
    for(int i=0;i<n;i++)
    {
        if(!col[i] && !d1[r-i+n-1] && !d2[r+i])
        {
            col[i] = 1;
            d1[r-i+n-1] = 1;
            d2[r+i] = 1;
            board[r][i] = 'Q';
            N_queen(r+1,n);
            col[i] = 0;
            d1[r-i+n-1] = 0;
            d2[r+i] = 0;
            board[r][i] = '.';
        }
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            board[i][j] = '.';
        }
    }
    N_queen(0,n);
}

/*
Sample Input: 
4
Sample Output: 
.Q..
...Q
Q...
..Q.

..Q.
Q...
...Q
.Q..
*/