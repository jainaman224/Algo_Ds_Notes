/* A Palindromic Sequence is a sequence of numbers which is 
the same when read both forward and backward.
Example: 1, 2, 3, 2, 1 */

#include<stdio.h>
#include<stdbool.h>

bool isPalindromic(int arr[], int N)
{
    int i;
    for (i = 0; i <= (N / 2); i++)
    {
        if (arr[i] != arr[N - i -1])
            return false;
    }
    return true;
} 

int main()
{
    printf("Enter number of elements in array\n");
    int N;
    scanf("%d", &N);
    printf("Enter elements of array\n");
    int arr[N], i;
    for (i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    if (isPalindromic(arr, N))
        printf("The array is palindromic");
    else
        printf("The array is not palindromic");
    return 0;
}

/*
Input:
N = 5
arr = {0, 1, 2, 3, 4}

Output:
The array is not palindromic

Input:
N = 6
arr = {0, 2, 4, 4, 2, 0}

Output:
The array is palindromic
*/
