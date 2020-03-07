/*
Problem Description: Matrix chain multiplication (or Matrix Chain Ordering Problem, MCOP) is an optimization problem 
to find the most efficient sequence of multiplying a set of 'n' given matrices. 
e.g. Multiplying 3 matrices can have the following sequences: ((AB)C) or (A(BC)). 
Both of the sequences can have different computational cost(# of scalar multiplications) based on the dimensions of the matrices.
Our goal is to find the sequence with the least computational cost.
*/

#include <stdio.h>
#include <limits.h>

int MCM(int *p, int n) 
{
    int m[n][n]; 
  
    int i, j, k, L, q;
  
    // cost is zero when multiplying one matrix.
    for (i = 1; i < n; i++) 
        m[i][i] = 0; 
  
    // L is chain length. 
    for (L = 2; L < n; L++) 
    { 
        for (i = 1; i < n - L + 1; i++) 
        { 
            j = i + L - 1; 
            m[i][j] = INT_MAX; 
            for (k = i; k <= j - 1; k++) 
            { 
                // q = cost/scalar multiplications 
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]; 
                if (q < m[i][j]) 
                    m[i][j] = q; 
            } 
        } 
    } 
  
    return m[1][n - 1]; 
}

int main()
{
    int n;

    // Input number of matrices
    printf("Enter number of matrices: \n");
    scanf("%d", &n);

    int P[n + 1];   

    printf("Enter the values of dimensions of the matrices:\n");
    
    for (int i = 0; i < n + 1; i++) {
        scanf("%d", &P[i]);
    }
    
    int size = sizeof(P) / sizeof(int);

    printf("The minimum number of scalar multiplications: %d\n", MCM(P, size));
}

                /* OUTPUT DESCRIPTION */
/*
              P = {10, 20, 30, 40, 30},
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
