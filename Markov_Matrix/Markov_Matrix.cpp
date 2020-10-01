/*
Markov Matrix is a matrix in which the sum of each row is equal to 1.
*/

#include<iostream> 
using namespace std; 

const int x = 10; 

void markovMatrix(double matrix[][x], int row, int col) 
{ 
    int count = 0;
    for (int i = 0; i < row; i++)
    { 
        double sum = 0;
        
        // Calculating sum of each row
        for (int j = 0; j < col; j++) 
            sum = sum + matrix[i][j]; 
        if (sum != 1) 
            count++; 
    } 
    if (count == 0)
        cout<<"YES";
    else 
        cout<<"NO";
} 

// Driver Code 
int main() 
{ 
    int row, col;
    double matrix[x][x];
    cin>>row;
    cin>>col;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin>>matrix[i][j]; 
    markovMatrix(matrix, row, col); 
} 

/*
Input:
row = 2
col = 2
Matrix = {{1, 0},
          {0.5, 0.5}}
Output:
YES
*/
