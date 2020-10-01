#include <stdio.h>

//Swapping the value in the array 
void swap(int *a,int *b)
{
   int temp= *a;
   *a = *b;
   *b = temp;
}
int partition (int arr[], int low, int high)
{
    //Taking the last value of array as pivot.
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        //Partitioning the array.
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int t;
    //Testcase
    printf("Enter Number of times you want to sort:\n");
    scanf("%d", &t);

    while(t--)
    {
        int n, i;
        printf("Enter the Size of the Array:\n");
        scanf("%d", &n);
        int arr[n];
        printf("Enter Array:\n");
        for(i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        quickSort(arr, 0, n-1) ;
        printf("Sorted Array:\n");
        for(i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
/*
----------------OUTPUT----------------
Enter Number of times you want to sort:
1
Enter the Size of the Array:
6
Enter Array:
4
8
5
9
2
6
Sorted Array:
2 4 5 6 8 9 
*/
