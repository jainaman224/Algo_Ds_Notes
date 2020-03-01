                                                                     /*DESCRIPTION*/

/*Let us define the problem as trying determine the order of multiplication M1*M2*M3*...*Mn using parentheses to denote the order.

  So the basic way to look at this problem in a Dynamic Programming fashion is as follows:-

- We can separate this multiplication into two sets (M1*M2*...*Mj) * (M(j+1)*...*Mn). Thus, the solution at this level comes down to how to choose j to minimize the
  cost of multiplication.In this case, we would choose j so that M(j+1) is the matrix with the smallest number of rows)

 -But, to brute-force this, we need to know how to optimally parentesize each of the sub multiplication chains. Thus, we have a smaller problem at hand.
  This goes iteratively downwards till we have only two matrices within brackets, at which point we can calculate the flops required directly.

- We now have a big recursive solution at hand where many solutions need to be recalculated,

  eg. for A1*...*A5 given in book, we have these 5 possible solutions
(A1 (A2 (A3 A4))) ,
(A1 ((A2 A3) A4)) ,
((A1 A2) (A3 A4)) ,
((A1 (A2 A3)) A4) ,
(((A1 A2) A3) A4).

You can see that the cost of A3*A4 is required for the calculation of the overall cost in both the first and third solution. It makes sense to store the
cost of A3*A4 when we first calculate it so that it need not be recalculated. For larger matrix chains, we can store the overall minimal cost directly and
retrieve it from memory(n^2 table)(this is memorization). Thus, we don't need to go down the recursion the second time.
*/

/*The technique we have used is called Memorization*/


                                                          /*SOURCE CODE*/

#include <stdio.h>
#include <limits.h>

int MCM(int *p, int n) 
{
    int m[n][n]; 
  
    int i, j, k, L, q;
  
    // cost is zero when multiplying one matrix.
    for (i=1; i<n; i++) 
        m[i][i] = 0; 
  
    // L is chain length. 
    for (L = 2; L < n; L++) 
    { 
        for (i = 1; i< n-L+1; i++) 
        { 
            j = i + L - 1; 
            m[i][j] = INT_MAX; 
            for (k = i; k <= j-1; k++) 
            { 
                // q = cost/scalar multiplications 
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]; 
                if (q < m[i][j]) 
                    m[i][j] = q; 
            } 
        } 
    } 
  
    return m[1][n-1]; 
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

                                                                    /*OUTPUT DESCRIPTION*/
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

        ,where table[1][size-1]=30000 is the answer.
*/
