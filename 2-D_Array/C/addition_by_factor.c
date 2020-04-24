#include<stdio.h>

int main()
{
    int n, m;
    printf("Enter dimensions of 2-D array: ");
    scanf("%d %d", &n, &m);

    int arr1[n][m], arr2[n][m], i, j;
    printf("Enter factor of first and second array: ");

    int a, b;
    scanf("%d %d", &a, &b);

    printf("Enter values of first array: ");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
        printf("\n");   //to add a new line when elements of other rwo are added
    }

    printf("Enter values of second array: ");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
        printf("\n");
    }

    int arr[n][m];
    //array in which answer i.e. a*arr1+b*arr2 is stored
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            arr[i][j]=a*arr1[i][j]+b*arr2[i][j];
        }
    }

    printf("Added matrix is: ");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Enter dimensions of 2-D array: 2 2
// Enter factor of first and second array: 1
// 2
// Enter values of first array: 1
// 2

// 3
// 4

// Enter values of second array: 1
// 3

// 5
// 7

// Added matrix is: 3 8
// 13 18
