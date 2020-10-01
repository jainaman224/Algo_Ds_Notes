//Program to rotate array Arr[] of size n by d Elements
#include <stdio.h>

void Rotate(int arr[], int r, int n)
{
    int temp[r];
    for (int i = 0; i < r; i++)
        temp[i] = arr[i];

    for (int i = r; i < n; i++)
        arr[i - r] = arr[i];

    for (int i = n - r; i < n; i++)
        arr[i] = temp[i - (n - r)];
}

int main()
{
    int n, r;
    printf("Enter number of elements in your array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter your array: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter the value for rotation cycle: ");
	scanf("%d", &r);

    Rotate(arr, r, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

/*
INPUT:
Enter number of elements in your array: 5
Enter your array: 1
2
3
4
5
Enter the value for rotation cycle: 2
OUTPUT:
3 4 5 1 2
*/
