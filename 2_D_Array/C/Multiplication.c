#include<stdio.h>
#include<conio.h>
int main()
{
    int mat1[10][10], mat2[10][10], matmult[10][10];
    int row1, col1, row2, col2, i, j, k, sum;
    printf("Enter size of first matrix:\n");
    printf("Enter row size: ");
    scanf("%d", &row1);
    printf("Enter column size: ");
    scanf("%d", &col1);

    // Storing elements of first matrix.
    printf("\nEnter the element of first matrix:\n");
    for(i = 0; i < row1; i++)
    {
        for(j = 0; j < col1; j++)
            scanf("%d", &mat1[i][j]);
    }
    printf("\nEnter size of second matrix:\n");
    printf("Enter row size: ");
    scanf("%d", &row2);
    printf("Enter column size: ");
    scanf("%d", &col2);

    // Storing elements of second matrix.
    printf("\nEnter the element of second matrix:\n");
    for(i = 0; i < row2; i++)
    {
        for(j = 0; j < col2; j++)
            scanf("%d", &mat2[i][j]);
    }

    // If column of first matrix in not equal to row of second matrix,
    // ask the user to enter the size of matrix again.
    if(col1 != row2)
    {
        printf("\nMultiplication not possible!");
        printf("\nExiting...\n");
        printf("Press any key...");
        getch();
        return 0;
    }
    
    // Multiplying matrix a and b and storing in array mult.   
    printf("\nMultiplying the two matrix...\n");
    for(i = 0; i < row1; i++)
    {
        for(j = 0; j < col2; j++)
        {
            sum = 0;
            for(k = 0; k < col1; k++)
                sum = sum + mat1[i][k] * mat2[k][j];
            matmult[i][j] = sum;
        }
    }

    // Displaying the multiplication of two matrix.   
    printf("The multiplication result is:\n");
    for(i = 0; i < row1; i++)
    {
        for(j = 0; j < col2; j++)
            printf("%d ", matmult[i][j]);
        printf("\n");
    }
    getch();
    return 0;
}

/*
Output

Enter size of first matrix:                                                                                                     
Enter row size: 2                                                                                                               
Enter column size: 2                                                                                                            
                                                                                                                                
Enter the element of first matrix:                                                                                              
1                                                                                                                               
2                                                                                                                               
3                                                                                                                               
4                                                                                                                               
                                                                                                                                
Enter size of second matrix:                                                                                                    
Enter row size: 2                                                                                                               
Enter column size: 2                                                                                                            
                                                                                                                                
Enter the element of second matrix:                                                                                             
5                                                                                                                               
6                                                                                                                               
7                                                                                                                               
8                                                                                                                               
                                                                                                                                
Multiplying the two matrix...                                                                                                   
The multiplication result is:                                                                                
19 22                                                                                                                           
43 50       

*/
