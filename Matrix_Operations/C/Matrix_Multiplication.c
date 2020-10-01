#include<stdio.h>
 
#define N 3    
  
// multiplies, matrix1[][] and matrix2[][], and  
// stores the result in result[][]
void multiply(int matrix1[][N], int matrix2[][N], int result[][N]) 
{ 
    int i, j, k; 
    for (i = 0; i < N; i++) 
    { 
        for (j = 0; j < N; j++) 
        { 
            result[i][j] = 0; 
            for (k = 0; k < N; k++) 
                result[i][j] += matrix1[i][k] * matrix2[k][j]; 
        } 
    } 
}   

int main() 
{ 
    int i, j; 
    int result[N][N]; 
    int matrix1[N][N] = {{1, 2, 3}, 
                         {4, 5, 6}, 
                         {7, 8, 9}}; 
  
    int matrix2[N][N] = {{1, 2, 3}, 
                         {4, 5, 6}, 
                         {7, 8, 9}};                        
  
    multiply(matrix1, matrix2, result); 
  
    printf("Result matrix is \n"); 
    for (i = 0; i < N; i++) 
    { 
        for (j = 0; j < N; j++) 
            printf("%d ", result[i][j]); 
        printf("\n"); 
    } 
    return 0; 
}

/*Result matrix is
30 36 42
66 81 96
102 126 150*/
