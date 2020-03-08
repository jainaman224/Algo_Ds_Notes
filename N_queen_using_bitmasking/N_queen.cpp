#include<bits/stdc++.h>
using namespace std;

const int N = 100;
const int num = 2*N;
vector<int> col(num,0);
vector<int> d1(num,0);
vector<int> d2(num,0);

//These are the vector of data type bitset i.e. either 0 or 1 is present inside the vector, for checking the already placed queen area
int board[N][N] = {0};

void show(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}


void N_queen(int r,int n)
{
    // when reached the last cell
    if(r==n)
    { 
        //for print the board
        show(n); 
        return; 
    }
    for(int i=0;i<n;i++)
    {
        if(!col[i] && !d1[r-i+n-1] && !d2[r+i])
        {
            // once we find such an area just mark 1 regarding the diagonal vertices and columns
            col[i] = 1;
            d1[r-i+n-1] = 1;
            d2[r+i] = 1;
            board[r][i] = 1; // placing a queen at this position
            N_queen(r+1,n);
            //once recur place 0 again at that position
            col[i] = 0;
            d1[r-i+n-1] = 0;
            d2[r+i] = 0;
            board[r][i] = 0;// removing the queen from that cell
        }
    }
}

int main()
{
    //Number of rows and columns on the chess board
    int n;
    cin>>n;
    N_queen(0,n);
}

/*
Sample Input: 
5
Sample Output: 
1 0 0 0 0 
0 0 1 0 0 
0 0 0 0 1 
0 1 0 0 0 
0 0 0 1 0 

1 0 0 0 0 
0 0 0 1 0 
0 1 0 0 0 
0 0 0 0 1 
0 0 1 0 0 

0 1 0 0 0 
0 0 0 1 0 
1 0 0 0 0 
0 0 1 0 0 
0 0 0 0 1 

0 1 0 0 0 
0 0 0 0 1 
0 0 1 0 0 
1 0 0 0 0 
0 0 0 1 0 

0 0 1 0 0 
1 0 0 0 0 
0 0 0 1 0 
0 1 0 0 0 
0 0 0 0 1 

0 0 1 0 0 
0 0 0 0 1 
0 1 0 0 0 
0 0 0 1 0 
1 0 0 0 0 

0 0 0 1 0 
1 0 0 0 0 
0 0 1 0 0 
0 0 0 0 1 
0 1 0 0 0 

0 0 0 1 0 
0 1 0 0 0 
0 0 0 0 1 
0 0 1 0 0 
1 0 0 0 0 

0 0 0 0 1 
0 1 0 0 0 
0 0 0 1 0 
1 0 0 0 0 
0 0 1 0 0 

0 0 0 0 1 
0 0 1 0 0 
1 0 0 0 0 
0 0 0 1 0 
0 1 0 0 0
*/