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
    printf("Enter Matrix :\n");
    
    //for storing matrix.    
    for(int i = 0; i < m; i++)                                                          
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    
    //for calculating each column sum.
    for(int j = 0; j < n; j++)                                                          
    {
        int sum = 0;
        for(int i = 0; i < m; i++)
        {
            sum += a[i][j];
        }
        printf("\nSum of column %d", j+1);
        printf(" : %d", sum);
    }
    printf("%d", "\n");
    return 0;
}

/*
Output

Enter size of matrix :
Row : 2
Column : 2
Enter Matrix :
4
5
6
7
Sum of column 1 : 10
Sum of column 2 : 12

*/
