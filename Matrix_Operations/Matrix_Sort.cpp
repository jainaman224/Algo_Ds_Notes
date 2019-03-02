/*
Author: Nirmal Kumar Joshi

C++ Program to sort a matrix

Input : mat[][] = { {5, 4, 7},
                    {1, 3, 8},
                    {2, 9, 6} }
Output : 1 2 3
         4 5 6
         7 8 9
*/



#include <bits/stdc++.h> 
using namespace std; 
  
#define SIZE 10 
  
// function to sort the given matrix 
void sortMat(int mat[SIZE][SIZE], int n) 
{ 
    // temporary matrix of size n^2 
    int temp[n * n]; 
    int k = 0; 
  
    // copy the elements of matrix one by one 
    // into temp[] 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            temp[k++] = mat[i][j]; 
  
    // sort temp[] 
    sort(temp, temp + k); 
      
    // copy the elements of temp[] one by one 
    // in mat[][] 
    k = 0; 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            mat[i][j] = temp[k++]; 
} 
  
// function to print the given matrix 
void printMat(int mat[SIZE][SIZE], int n) 
{ 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) 
            cout << mat[i][j] << " "; 
        cout << endl; 
    } 
} 
  

int main() 
{ 
    int mat[SIZE][SIZE] = { { 5, 4, 7 }, 
                            { 1, 3, 8 }, 
                            { 2, 9, 6 } }; 
    int n = 3; 
  
    cout << "Input Matrix:\n"; 
    printMat(mat, n); 
  
    sortMat(mat, n); 
  
    cout << "\nMatrix After Sorting Operation:\n"; 
    printMat(mat, n); 
  
    return 0; 
} 



/*
Input Matrix:
5 4 7
1 3 8
2 9 6

Matrix After Sorting Operation:
1 2 3
4 5 6
7 8 9

*/


