/*
Markov Matrix is a matrix in which the sum of each row is equal to 1.
*/

#include<stdio.h> 

int row, col; 

void markovMatrix(double matrix[row][col], int row, int col) 
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
        printf("YES");
    else 
        printf("NO");
} 

// Driver Code 
int main() 
{ 
    scanf("%d", &row);
    scanf("%d", &col);
    double matrix[row][col];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            scanf("%lf", &matrix[i][j]); 
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
