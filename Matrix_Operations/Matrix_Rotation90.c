#include <bits/stdc++.h> 
#define N 3
using namespace std; 

void Rotate(int matrix[][N]) 
{ 
    for (int x = 0; x < N / 2; x++) 
    { 
        for (int i = x; i < N-x-1; i++) 
        { 
            int t = matrix[x][i];
            matrix[x][i] = matrix[i][N-1-x]; 
            matrix[i][N-1-x] = matrix[N-1-x][N-1-i]; 
            matrix[N-1-x][N-1-i] = matrix[N-1-i][x];  
            matrix[N-1-i][x] = t; 
        } 
    } 
} 

//Driver program 
int main() 
{ 
    // Sample Input 
    int matrix[N][N] = 
    { 
        {1, 2, 3}, 
        {5, 6, 7}, 
        {9, 10, 11}
    }; 
    Rotate(matrix); 

    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
            printf("%2d ", mat[i][j]); 

        printf("\n"); 
    } 
    printf("\n"); 
    return 0; 
} 

/* Sample Output:
   3	7	11	
   2	6	10	
   1	5	9	 
*/
