/*
Problem Description: Matrix chain multiplication (or Matrix Chain Ordering Problem, MCOP) is an optimization problem 
to find the most efficient sequence of multiplying a set of 'n' given matrices. 
e.g. Multiplying 3 matrices can have the following sequences: ((AB)C) or (A(BC)). 
Both of the sequences can have different computational cost(# of scalar multiplications) based on the dimensions of the matrices.
Our goal is to find the sequence with the least computational cost.
*/

#include <stdio.h>
#include <limits.h>

int MCM(int *dims, int n) 
{
    int table[n][n]; 
  
    int i, j, k, L, q;
  
    // cost is zero when multiplying one matrix.
    for (i = 1; i < n; i++) 
        table[i][i] = 0; 
  
    // L is chain length. 
    for (L = 2; L < n; L++) 
    { 
        for (i = 1; i < n - L + 1; i++) 
        { 
            j = i + L - 1; 
            table[i][j] = INT_MAX; 
            for (k = i; k <= j - 1; k++) 
            { 
                // q = cost/scalar multiplications 
                q = table[i][k] + table[k + 1][j] + dims[i - 1] * dims[k] * dims[j]; 
                if (q < table[i][j]) 
                    table[i][j] = q; 
            } 
        } 
    } 
  
    return table[1][n - 1]; 
}

int main()
{
    int n;

    // Input number of matrices
    printf("Enter number of matrices: \n");
    scanf("%d", &n);

    int dims[n + 1];   

    printf("Enter the values of dimensions of the matrices:\n");
    
    for (int i = 0; i < n + 1; i++) {
        scanf("%d", &dims[i]);
    }
    
    int size = sizeof(dims) / sizeof(int);

    printf("The minimum number of scalar multiplications: %d\n", MCM(dims, size));
}

                /* OUTPUT DESCRIPTION */
/*
              dims = {10, 20, 30, 40, 30},
              dimensions of matrix [1] = 10X20,
              dimensions of matrix [2] = 20X30,
              dimensions of matrix [3] = 30X40,
              dimensions of matrix [4] = 40X30


         This is how table[][] matrix will look like

                0 6000 18000 30000
                0 0    24000 48000
                0 0    0     36000
                0 0    0     0

        where table[1][size-1]=30000 is the answer.
*/
