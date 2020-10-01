#include<stdio.h>

int main()
{     
    int i, j;

    int arr[3][3] = {{9, 8, 7}, 
                    {6, 5, 4}, 
                    {3, 2, 1}}; 

    // temporary matrix
    int temp[9];
    int k = 0, t;
    
    // copy the elements of matrix one by one 
    // into temp[] 
    for(i = 0; i < 3; i++) 
    {
        for(j = 0; j < 3; j++)
            temp[k++] = arr[i][j];
    }

    // sort temp[] 
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < (8 - i); j++)
        {
            if(temp[j] > temp[j+1])
            {
                t = temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = t;
            }
        }
    }

    // copy the elements of temp[] one by one 
    // in arr[][] 
    k = 0;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            arr[i][j] = temp[k];
            k++;
        }
    }

    printf("Sorted Array is: \n");

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

/*Sorted Array is:
1 2 3
4 5 6
7 8 9*/
