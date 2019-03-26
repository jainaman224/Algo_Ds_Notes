#include <stdio.h> 
#include <bits/stdc++.h> 
using namespace std; 

const int MAX = 100; 
  
void middlesum(int A[][MAX], int row,int col) 
{ 
    int  row_sum = 0, col_sum = 0; 
    //loop for sum of row 
    for (int i = 0; i < row; i++) 
        row_sum += A[row / 2][i]; 
	
    cout << "Sum of middle row = " << row_sum<<endl; 
	
    //loop for sum of column 
    for (int i = 0; i < col; i++) 
        col_sum += A[i][col / 2]; 
     
    cout << "Sum of middle column = " << col_sum; 
} 
  
// Driven Program 
int main() 
{   
    int row, col;
    int A[MAX][MAX];
    cout << "Enter number of rows and columns of matrix A : ";
    cin >> row >> col;
    cout << "Enter elements of matrix A : ";
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> A[i][j];
    
    middlesum(A,row,col); 
 
    return 0; 
} 

//INPUT:Enter number of rows and columns of matrix A : 3
//3
//Enter elements of matrix A : 2
//5
//7
//2
//7
//2
//5
//6/9
//OUTPUT:Sum of middle row = 11
//Sum of middle column = 18
