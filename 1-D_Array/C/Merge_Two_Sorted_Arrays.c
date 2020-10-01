// Merging to sorted array a[] and b[] and storing it in c[]

#include<stdio.h>

int main()
{
    int i, num1, num2;

    printf("Enter number of elements in array 1: ");
    scanf("%d", &num1);
    
    int a[num1];
    printf("Enter your sorted array 1: ");
    for (i = 0; i < num1; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter number of elements in array 2: ");
    scanf("%d", &num2);

    int b[num2], c[num1 + num2];

    printf("Enter your sorted array 2: ");
    for (i = 0; i < num2; i++)
    {
        scanf("%d", &b[i]);
    }

    int k = 0;
    int j = 0;
    i = 0;

    // Traverse both array 
    while (i < num1 && j < num2) 
    { 
        if (a[i] > b[j]) 
            c[k++] = b[j++]; 
        else
            c[k++] = a[i++]; 
    } 

    // copying remaining elements of array a 
    while (i < num1) 
        c[k++] = a[i++]; 

    // copying remaining elements of array b
    while (j < num2) 
        c[k++] = b[j++]; 

    printf("New merged array: \n");
    for (i = 0; i< (num1 + num2); i++)	
    {
        printf("%d ", c[i]);
    }
}

/*
Enter number of elements in array 1: 3
Enter your sorted array 1: 1
3
4
Enter number of elements in array 2: 3
Enter your sorted array 2: 2
5
6
New merged array:
1 2 3 4 5 6*/
