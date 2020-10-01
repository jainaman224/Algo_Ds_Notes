#include <stdio.h> 
#include <bits/stdc++.h> 
using namespace std; 
 
const int MAX = 100; 
 
void multiply(int A[][MAX], int res[][MAX],int row,int col) ;
// Function to check idempotent 
int checkIdempotent(int A[][MAX],int row,int col) 
{    
    int res[MAX][MAX]; 
    multiply(A, res,row,col); 
  
    for (int i = 0; i < row; i++)     
        for (int j = 0; j < col; j++)         
            if (A[i][j] != res[i][j]) 
                return 0; 
    return 1; 
} 
  
// Driver function. 
int main() 
{ 
    int row, col;
    int A[MAX][MAX];
    cout << "Enter number of rows and columns of matrix A : ";
    cin >> row >> col;
    if (row!=col)
    {
        cout<<" Not Idempotent Matrix because only sqaure matrix can be idempotent matrix";
        exit(0);
    }
    cout << "Enter elements of matrix A : ";
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> A[i][j];
  
    if (checkIdempotent(A,row,col)==1) 
        cout << "Idempotent Matrix"; 
    else
        cout << "Not Idempotent Matrix"; 
    return 0; 
}

void multiply(int A[][MAX], int res[][MAX],int row,int col) 
{ 
    for (int i = 0; i <row ; i++) 
    { 
        for (int j = 0; j < col; j++) 
        { 
            res[i][j] = 0; 
            for (int k = 0; k < row; k++) 
                res[i][j] += A[i][k] * A[k][j]; 
        } 
    } 
}

//INPUT:Enter number of rows and columns of matrix A : 3
//3
//Enter elements of matrix A : 2  
//-2
//-4
//-1
//3
//4
//1
//-2
//-3
//OUTPUT:Idempotent Matrix 
