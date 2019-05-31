/*
Subset Sum Problem using Backtracking:
Given an array of elements and a sum, is it possible to form the
given sum using some or all of the elements of array i.e using any
subset of given array.
Example: 1, 7, 3, 5, 6 and sum = 14, it is possible to
obtain the sum 14 by taking the elements 1, 7 and 6
*/

#include<stdio.h>

int flag = 0;

void isSubsetSum(int arr[], int subset[], int N, int subsetSize,
                             int subsetSum, int index ,int sum) 
{
    if (subsetSum == sum) 
    {
        flag = 1;
        for (int i = 0; i < subsetSize; i++)
            printf("%d ", subset[i]);
        printf("\n");
    }
    else 
    {
        for (int i = index; i < N; i++) 
        { 
            subset[subsetSize] = arr[i];
            isSubsetSum(arr, subset, N, subsetSize + 1, 
                        subsetSum + arr[i], i + 1, sum);
        }
    }
}

int main()
{ 
    printf("Enter size of array");
    int N;
    scanf("%d", &N);
    printf("Enter elements of array");
    int arr[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    printf("Enter sum");
    int sum;
    scanf("%d", &sum);
    int subset[N];
    isSubsetSum(arr, subset, N, 0, 0, 0, sum);
    if (flag == 0) {
        printf("No such subset present");
    }
    return 0;    
}

/*
INPUT:
N = 5
arr = [1 2 3 4 5]
sum = 7

OUTPUT:
1  2  4
2  5
3  4
*/
