#include <stdio.h>
#include<stdlib.h>

int main()
{
    int n, m;
    printf("Enter size of matrix :\n");
    printf("Row : ");
    scanf("%d", &m);
    printf("Column : ");
    scanf("%d", &n);
    int a[m][n];
    if(m == n)
    {
        
        //for storing matrix.        
        printf("Enter Matrix :\n");							
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        int sum = 0;
        
        //for calculating sum both the diagonals.
        for(int i = 0; i < m; i++)							
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j || i+j == n-1)
                {
                    sum += a[i][j];
                }
            }
        }
        sum -= a[m/2][n/2];
        printf("\nDiagonal sum : %d", sum);
        printf("\n");
    }
    else
    {
        printf("\nOnly square matrix contain diagonals....\n");
    }
    return 0;
}

/*
Output

Enter size of matrix :
Row : 3
Column : 3
Enter Matrix :
1
2
3
4
5
6
7
8
9

Diagonal Sum : 20

*/
