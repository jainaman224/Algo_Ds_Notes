/*
Author: Nirmal Kumar Joshi


C++ program to find the scalar product of a matrix 

*/
 
#include <bits/stdc++.h> 
using namespace std; 
  
 
#define N 3   //can be changed as per use
  
void scalarProductMat(int mat[][N], int k) 
{ 
    // scalar element is multiplied by the matrix 
    for (int i = 0; i < N; i++)  
        for (int j = 0; j < N; j++)  
            mat[i][j] = mat[i][j] * k;         
} 
  

int main() 
{ 
    int mat[N][N] = { { 1, 2, 3 }, 
                      { 4, 5, 6 }, 
                      { 7, 8, 9 } }; 
    int k = 4;   //scaling factor
  
    scalarProductMat(mat, k); 
  
   
    printf("Scalar Product Matrix is : \n"); 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++)  
            printf("%d ", mat[i][j]); 
        printf("\n"); 
    } 
  
    return 0; 
} 



/*
Scalar Product Matrix is : 
4 8 12 
16 20 24 
28 32 36
*/
