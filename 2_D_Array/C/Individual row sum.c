#include <stdio.h>
#include<stdlib.h>

int main()
{
    int n,m;
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
    
     //for calculating each row sum.   
    for(int i = 0; i < m; i++)                                                              
    {
        int sum = 0;
        for(int j = 0; j < n; j++)
        {
            sum += a[i][j];
        }
        printf("\nSum of row %d", i+1);
        printf(" : %d", sum);
    }
    printf("%d", "\n");
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
Sum of row 1 : 6
Sum of row 2 : 15
Sum of row 3 : 24

*/
