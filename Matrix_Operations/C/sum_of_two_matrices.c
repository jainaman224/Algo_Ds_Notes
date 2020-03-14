#include<stdio.h>

void sum( int r, int c, int M1[100][100], int M2[100][100], int res[100][100])
{
    int i, j;
    //add corresponding terms of both matrices and intialise to the third matrix.
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {  
            res[i][j] = M1[i][j] + M2[i][j];
        }
    }
    //print the resultant matrix.
    printf("Sum of Matrices  is \n");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            printf("%d   ", res[i][j]);
        }
        printf("\n"); 
    }
}

void main()
{ 
    int M1[100][100], M2[100][100], res[100][100], r, c, i, j;
    printf("Enter order of matrices:");
    scanf("%d %d", &r, &c);
    //take input for both matrices.
    printf("ENTER elements of first matrix:");
    for(i = 0; i < r; i++)
    {
        for(j = 0;  j < c; j++)
        {
            scanf("%d", &M1[i][j]);
        }
    }
    printf("Enter elements of second matrix:");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
            {
                scanf("%d", &M2[i][j]);
            }
    }
    sum(r, c, M1, M2, res);
}

//sample input-output
/*Enter order of matrices:3 3
ENTER elements of first matrix:12 13 14 2 3 4 5 6 7
ENTER elements of second matrix:1 13 15 10 18 30 17 20 30
Sum of Matrices  is 
13   26   29   
12   21   34   
22   26   37 */  
