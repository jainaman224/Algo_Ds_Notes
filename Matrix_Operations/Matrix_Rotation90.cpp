
#include <bits/stdc++.h> 
#define N 4 
using namespace std; 

void displayMatrix(int mat[N][N]); 

void rotateMatrix(int mat[][N]) 
{ 
    for (int x = 0; x < N / 2; x++) 
    { 
	for (int y = x; y < N-x-1; y++) 
	{ 
	    int temp = mat[x][y]; 

	    // move values from right to top 
	    mat[x][y] = mat[y][N-1-x]; 

	    // move values from bottom to right 
	    mat[y][N-1-x] = mat[N-1-x][N-1-y]; 

	    mat[N-1-x][N-1-y] = mat[N-1-y][x];  
	    mat[N-1-y][x] = temp; 
	} 
    } 
} 

// Function to print the matrix 
void displayMatrix(int mat[N][N]) 
{ 
    for (int i = 0; i < N; i++) 
    { 
	for (int j = 0; j < N; j++) 
	    cout << mat[i][j]; 

	cout << endl; 
    } 
    cout << endl;
} 


//Driver program 
int main() 
{ 
    // Sample Input 
    int mat[N][N] = 
    { 
	{1, 2, 3, 4}, 
	{5, 6, 7, 8}, 
	{9, 10, 11, 12}, 
	{13, 14, 15, 16} 
    }; 

    rotateMatrix(mat); 
    displayMatrix(mat); 

    return 0; 
} 

/* Sample Output:

    4  8 12 16 
    3  7 11 15 
    2  6 10 14 
    1  5  9 13 
*/


