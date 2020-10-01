/*
Author: Nirmal Kumar Joshi


C++ Program to find mirror of matrix across diagonal

Input : mat[][] = {{1  2  3  4 }
                   {5  6  7  8 }
                   {9  10 11 12}
                   {13 14 15 16} }
Output : 1 5 9 13 
         2 6 10 14  
         3 7 11 15 
         4 8 12 16
*/


#include <bits/stdc++.h> 
using namespace std; 
  
const int MAX = 100; 
  
void imageSwap(int mat[][MAX], int n) 
{ 
    // for diagonal which start from at  
    // first row of matrix 
    int row = 0; 
  
    // traverse all top right diagonal 
    for (int j = 0; j < n; j++) { 
  
        // here we use stack for reversing 
        // the element of diagonal 
        stack<int> s; 
        int i = row, k = j; 
        while (i < n && k >= 0)  
            s.push(mat[i++][k--]); 
          
        // push all element back to matrix  
        // in reverse order 
        i = row, k = j; 
        while (i < n && k >= 0) { 
            mat[i++][k--] = s.top(); 
            s.pop(); 
        } 
    } 
  
    // do the same process for all the 
    // diagonal which start from last 
    // column 
    int column = n - 1; 
    for (int j = 1; j < n; j++) { 
  
        // here we use stack for reversing  
        // the elements of diagonal 
        stack<int> s; 
        int i = j, k = column; 
        while (i < n && k >= 0)  
            s.push(mat[i++][k--]); 
          
        // push all element back to matrix  
        // in reverse order 
        i = j; 
        k = column; 
        while (i < n && k >= 0) { 
            mat[i++][k--] = s.top(); 
            s.pop(); 
        } 
    } 
} 
  
// Utility function to print a matrix 
void printMatrix(int mat[][MAX], int n) 
{ 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) 
            cout << mat[i][j] << " "; 
        cout << endl; 
    } 
} 
  
// driver program to test above function 
int main() 
{ 
    int mat[][MAX] = { { 1, 2, 3, 4 }, 
                     { 5, 6, 7, 8 }, 
                     { 9, 10, 11, 12 }, 
                     { 13, 14, 15, 16 } }; 
    int n = 4; 
    imageSwap(mat, n); 
    printMatrix(mat, n); 
    return 0; 
} 


/*
1 5 9 13 
2 6 10 14 
3 7 11 15 
4 8 12 16

*/
