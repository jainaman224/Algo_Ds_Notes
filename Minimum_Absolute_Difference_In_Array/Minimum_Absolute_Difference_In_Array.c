/*Given an integer array A of size N, find and return
the minimum absolute difference between any two elements in the array.
The absolute difference between two elements ai, and aj (where i != j ) is |ai - aj|*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int cmpfunc (const void * a, const void * b)
{
    return (*(int*)a - *(int*)b);
}

int minAbsoluteDiff(int arr[], int n)
{
    qsort(arr, n, sizeof(int), cmpfunc);
    int mindiff = INT_MAX;
    for(int i = 0; i < n - 1; i++)
    {
        if(abs(arr[i] - arr[i + 1]) < mindiff)
            mindiff = abs(arr[i] - arr[i + 1]);
    }
    return mindiff;
}

int main()
{
    int size, i;
    scanf("%d", &size);
    int input[size];
    for(i = 0; i < size; i++)
        scanf("%d", &input[i]);

    printf("%d", minAbsoluteDiff(input,size));
    return 0;
}

/* Input : 12
           922 192 651 200 865 174 798 481 510 863 150 520

   Output : 2
*/
