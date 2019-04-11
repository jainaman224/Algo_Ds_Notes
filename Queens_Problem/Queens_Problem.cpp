//The N Queen is the problem of placing N chess queens on an N×N chessboard so 
//that no two queens attack each other.

# include <bits/stdc++.h> 
# include <string.h>
using namespace std; 

int N ; //Number of queens
int board[100][100];
int is_attack(int i,int j) ;
int N_queen(int n);

int main()
{    
    cout << "Enter the value of N for NxN chessboard\n" ;
    cin >> N;
    int i, j;
    
    for( i = 0 ; i < N ; i++ )
    {
        for( j = 0 ; j < N ; j++ )
        {
            board[i][j] = 0;
        }
    }
    
    N_queen(N);    
    for( i = 0 ; i < N ; i++ )
    {
        for( j = 0 ; j < N ; j++ )
            cout << board[i][j] << "\t";
        cout << "\n";
    }
}

int is_attack(int i,int j)
{
    int k , l;
    //checking if there is a queen in row or column
    for( k = 0 ; k < N ; k++)
    {
        if((board[i][k] == 1) || (board[k][j] == 1))
            return 1;
    }
    //checking for diagonals
    for( k = 0 ; k < N ; k++ )
    {
        for( l = 0 ; l < N ; l++ )
        {
            if(((k+l) == (i+j)) || ((k-l) == (i-j)))
            {
                if(board[k][l] == 1)
                    return 1;
            }
        }
    }
    return 0;
}

int N_queen( int n )
{
    int i,j;
  
    if( n == 0 )
        return 1;
    for( i = 0 ; i < N ; i++ )
    {
        for( j = 0 ; j < N ; j++)
        {
            //checking if we can place a queen here or not            
            if((!is_attack(i,j)) && (board[i][j]!=1))
            {
                board[i][j] = 1;                
                if(N_queen(n-1) == 1)
                {
                    return 1;
                }
                board[i][j] = 0;
            }
        }
    }
    return 0;
}

/*Enter the value of N for NxN chessboard
4
0	1	0	0	
0	0	0	1	
1	0	0	0	
0	0	1	0	*/
