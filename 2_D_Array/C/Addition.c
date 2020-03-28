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
	    
	//calculating sum of a and b matrices.	    
        for(int i = 0; i < m; i++)						
        {
            for(int j = 0; j < n; j++)
            {
                c[i][j] = a[i][j] + b[i][j];
            }
	}
	    
	//for displaying output matrix.	    
        printf("Added Array :\n");						
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
Ouptput

Enter size of 1st array :
Row :2
Column :3
Enter size of 2nd array :
Row :2
Column :3
Enter 1st array :
1
2
3
4
5
6
Enter 2nd array :
7
8
9
10
11
12
Added Array :
8       10      12
14      16      18

*/
