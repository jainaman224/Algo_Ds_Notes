#include <iostream>
#include <cmath>

using namespace std;

//Number of queens
int Q;

//chessboard
int board[100][100];

//function to check if the cell is attacked or not
int is_attack(int i1, int j1)
{
    for(int i = 0; i < Q; i++)
        if( board[i1][i] == 1 || board[i][j1] == 1)
            return 1;
    
    //checking for diagonals
    for(int i = 0; i < Q; i++)
    {
        for(int j = 0; j < Q; j++)
        {
            if ((i + j == i1 + j1 || i - j == i1 - j1) && (board[i][j] == 1))
                return 1; 
        }
    }
    return 0;
}

int N_queen(int n)
{
    
    //if n is 0, solution found
    if( n == 0)
        return 1;
    for(int i = 0; i < Q; i++)
    {
        for(int j = 0; j < Q; j++)
        {
            if((!is_attack(i,j)) && (board[i][j] != 1))
            {
                board[i][j] = 1;
                if( N_queen(n - 1) == 1)
                {
                    return 1;
                }
                board[i][j] = 0;
            }
        }
    }
    return 0;
}

int main()
{
    //taking the value of N
    cout << "Enter the value of board side:" << endl;
    cin >> Q;

    for(int i = 0; i < Q; i++)
    {
        for(int j = 0; j < Q; j++)
        {
            board[i][j]=0;
        }
    }
    N_queen(Q);
    for (int i = 0; i < Q; i++) 
    {
        for (int j = 0; j < Q; ++j)
        {
            cout << board[i][j] << " "; 
        }
        cout << endl;
    }
}
