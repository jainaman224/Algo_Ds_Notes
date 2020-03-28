#include <stdio.h>
#include<stdlib.h>

int main()
{
    int m, n, k, l;
    printf("Enter size of 1st array :\n");
    printf("Row :");
    scanf("%d", &m);
    printf("Column :");
    scanf("%d", &n);
    printf("Enter size of 2nd array :\n");
    printf("Row :");
    scanf("%d", &k);
    printf("Column :");
    scanf("%d", &l);
    int a[m][n], b[k][l];
    if(m == k && n == l)
    {
        
        //for storing first matrix.        
        printf("Enter 1st array : \n");						 
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        
        //for storing second matrix.   
        printf("Enter 2nd array :\n");						
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                scanf("%d", &b[i][j]);
            }
        }
        int c[m][n];
        
        //calculating subtraction of a and b matrices.       
        for(int i = 0; i < m; i++)						
        {
            for(int j = 0; j < n; j++)
            {
                c[i][j] = a[i][j] - b[i][j];
            }
        }
        printf("Subtracted Array :\n");
        
        //for displaying output matrix.       
        for(int i = 0; i < m; i++)						
        {
            for(int j = 0; j < n; j++)
            {
                printf("%d\t", c[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("\nThe two matrices cannot be added due to difference in size...\n");
    }
    return 0;
}

/*
Output

Enter size of 1st array :
Row :3
Column :2
Enter size of 2st array :
Row :3
Column :2
Enter 1st array :
2
3
-1
4
-8
5
Enter 2nd array :
6
-9
8
1
-7
-6

Subtracted Array :
-4      12
-9      3
-1      11

*/
