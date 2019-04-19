# include <iostream>
# include <string>
using namespace std;

int N;
int board[100][100];
int is_safe(int row, int col);
int N_queen(int n);

int main()
{
    cout << "Enter the value of N for NxN chessboard: ";
    cin >> N;

    int row, col;
    if ( N <= 3)
    {   
        cout<< "The Queens cant be placed in the chessboard because queens can attack each other \n" ;
        exit(0);
    }    
    N_queen(N);

    for( row = 0 ; row < N ; row++ )
    {
        for( col = 0 ; col < N ; col++ )
            cout << "\t" << board[row][col];
        cout << "\n";
    }
}

int is_safe(int row, int col)
{
    int i, j;
    //checking if there is a queen in row or column
    for(i = 0 ; i < N ; i++ )
    {
        if((board[row][i] == 1) || (board[i][col] == 1))
            return 0;
    }
    //checking if there is a queen in diagonals
    for( i = 0 ; i < N ; i++)
    {
        for( j = 0 ; j < N ; j++)
        {
            if(((i+j) == (row+col)) || ((i-j) == (row-col)))
            {
                if(board[i][j] == 1)
                    return 0;
            }
        }
    }
    return 1;
}

int N_queen(int n)
{
    int row,col;
    //if n is 0, solution found
    if( n == 0 )
        return 1;
        
    for( row = 0 ; row < N ; row++ )
    {
        for( col = 0 ; col < N ; col++ )
        {
            //checking if we can place a queen here or not
            //queen will not be placed if the place is not safe
            //or already occupied
            if((is_safe(row,col)) && (board[row][col]!=1))
            {
                board[row][col] = 1;
                //recursion; whether we can put the next queen with this arrangement or not
                if(N_queen(n - 1) == 1)
                {
                    return 1;
                }
                board[row][col] = 0;
            }
        }
    }
    return 0;
}

/*Enter the value of N for NxN chessboard : 4
0       1       0       0
0       0       0       1
1       0       0       0
0       0       1       0*/
