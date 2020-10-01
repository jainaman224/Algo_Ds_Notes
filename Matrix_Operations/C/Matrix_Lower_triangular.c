#include<stdio.h>
 
int main()
{
    int i, j, row, col, matrix[10][10];

    printf("Enter the size of the matrix: ");
    scanf("%d", &row);
    
    // Square matrix
    col = row;

    printf("Enter the Matrix Elements: \n");
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
 
    // Lower triangular matrix is a matrix which contain elements below 
    // principle diagonal including principle diagonal elements and
    // rest of the elements are 0.
    for(i = 0; i < row; i++)
    {
        printf("\n");
        for(j = 0; j < col; j++)
        {
            if(i >= j)
            {
                printf("%d ", matrix[i][j]);
            }
            else
            {
                printf("0 ");
            }
        }
    }  	
    return 0;
}

/*
INPUT:Enter Number of row and col: 3
Enter the Matrix Elements:
1
2
3
4
5
6
7
8
9
OUTPUT:
1 0 0
4 5 0
7 8 9*/
