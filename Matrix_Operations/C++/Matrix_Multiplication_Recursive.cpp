#include <stdio.h> 
#include <bits/stdc++.h> 
using namespace std; 
 
const int MAX = 100; 
  
void multiplyMatrixRecursive(int row1,int col1,int A[][MAX],int row2, int col2, int B[][MAX],int C[][MAX]) 
{ 
    static int i = 0, j = 0, k = 0; 
    //Static i and j are used to know current block of matrix C ,k for current column of matrix A and row of matriz B 
  
    if (i >= row1) 
        return; 
    if (j < col2) 
    { 
        if (k < col1) 
        { 
            C[i][j] += A[i][k] * B[k][j]; 
            k++; 
  
            multiplyMatrixRecursive(row1, col1, A, row2, col2,B, C); 
        } 
  
        k = 0; 
        j++; 
        multiplyMatrixRecursive(row1, col1, A, row2, col2, B, C); 
    } 
  
    j = 0; 
    i++; 
    multiplyMatrixRecursive(row1, col1, A, row2, col2, B, C); 
} 
  

void multiplyMatrix(int row1, int col1, int A[][MAX],int row2, int col2, int B[][MAX]) 
{ 
    int C[MAX][MAX] = {0}; 
    multiplyMatrixRecursive(row1, col1, A, row2, col2, B, C);
	
    cout<<"The resultant Matrix is \n";
    // Print the result 
    for (int i = 0; i < row1; i++) 
    { 
        for (int j = 0; j < col2; j++) 
            cout<< C[i][j]; 
 
        printf("\n"); 
    } 
} 
  
// Driven Program 
int main() 
{ 
    int row1, col1, row2, col2, i, j, k;
    int A[MAX][MAX], B[MAX][MAX]; 
    cout << "Enter number of rows and columns of matrix A : ";
    cin >> row1 >> col1;
    cout << "Enter number of rows and columns of matrix B : ";
    cin >> row2 >> col2;
    
    if (col1 != row2)
    {
        cout << "Matrices cannot be multiplied!";
        exit(0);
    }	
    cout << "Enter elements of matrix A : ";
    for (i = 0; i < row1; i++)
        for (j = 0; j < col1; j++)
            cin >> A[i][j];
    cout << "Enter elements of matrix B : ";
    for (i = 0; i < row2; i++)
        for (j = 0; j < col2; j++)
            cin >> B[i][j];
			
    multiplyMatrix(row1, col1, A, row2, col2, B); 
	
    return 0; 
} 

//INPUT:Enter number of rows and columns of matrix A : 3
//3
//Enter number of rows and columns of matrix B : 3
//3
//Enter elements of matrix A : 1
//1
//1
//2
//2
//2
//3
//3
//3
//Enter elements of matrix B : 1
//1
//1
//2
//2
//2
//3
//3
//3

//OUTPUT:The resultant Matrix is 
//6  6  6  
//12  12  12  
//18  18  18 
  
