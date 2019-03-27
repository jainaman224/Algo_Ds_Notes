/* C Program to Add Two Matrices using Multi-dimensional Arrays */


#include <stdio.h>

int main()
{
    int r, c, a[100][100], b[100][100], sum[100][100], i, j;
    
    /* a[100][100], b[100][100] denotes 1st matrix & 2nd matrix
       respectively which we want to add and sum[100][100]
       is 3rd matrix which is the addition of both the matrix 
       1st and 2nd */

    printf("Enter number of rows (between 1 and 100)");
    scanf("%d",&r);

    printf("Enter number of columns (between 1 and 100)\n");
    scanf("%d",&c);

    printf("Enter elements of 1st matrix: \n");
    
    // Storing elements of first matrix entered by user
    
    for(i = 0; i < r; ++i)
       for(j = 0; j < c; ++j)
       {
           printf("Enter element a%d%d: ",i+1,j+1);
           scanf("%d",&a[i][j]);
       }

    // Storing elements of second matrix entered by user
    
    printf("Enter elements of 2nd matrix: \n");
    for(i = 0; i < r; ++i)
       for(j = 0; j < c; ++j)
       {
           printf("Enter element b%d%d: ",i+1,j+1);
           scanf("%d",&b[i][j]);
       }

    // Adding Two matrices
    
    for(i = 0; i < r; ++i)
        for(j = 0; j < c; ++j)
            sum[i][j] = a[i][j] + b[i][j];

    // Displaying the resultant sum matrix
    
    printf("\n Sum of two matrix is: \n");
    for(i = 0; i < r; ++i)
        for(j = 0; j < c; ++j)
        {
            printf("%d ",sum[i][j]);
            if(j == c - 1)
                printf("\n");
        }

    return 0;
}



/*
Enter number of rows (between 1 and 100): 2
Enter number of columns (between 1 and 100): 2
Enter elements of 1st matrix:
Enter element a11: 7
Enter element a12: 5
Enter element a21: 3
Enter element a22: 6
Enter elements of 2nd matrix:
Enter element b11: 3
Enter element b12: -9
Enter element b21: 4
Enter element b22: -9
Sum of two matrix is:
10   -4
7   -3
*/

