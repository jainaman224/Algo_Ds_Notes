#include <stdio.h> 
#include <bits/stdc++.h> 
using namespace std; 

const int MAX = 100; 
  
void Upper(int A[MAX][MAX], int row, int col) 
{ 
    int i, j; 
    for (i = 0; i < row; i++) 
    { 
        for (j = 0; j < col; j++) 
        { 
            if (i > j) 
                cout << "0" << " "; 
            else
                cout <<A[i][j] << " "; 
        } 
        cout << endl; 
    } 
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
   
    cout << "Upper triangular matrix: \n"; 
    Upper(A, row, col);
    return 0; 
}

//INPUT:Enter number of rows and columns of matrix A : 3
//3
//Enter elements of matrix A : 1
//2
//3
//4
//5
//6
//7
//8
//9
//OUTPUT:Upper triangular matrix: 
//1 2 3 
//0 5 6 
//0 0 9 
