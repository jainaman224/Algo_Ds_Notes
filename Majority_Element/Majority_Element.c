/*
A majority element in an array arr of size n is an
element that appears more than n/2 times.
Example: 
N = 9, arr = {1, 2, 2, 2, 4, 2, 2, 1, 5}
Majority Element = 2 as count[2] = 5 which is greater
than n/2 i.e 4
*/

#include<stdio.h>
#define SIZE 1000007

int checkMajorityElement(int arr[], int N)
{
    int freq[SIZE] = {0};
    // Computing frequency of each element
    for (int i = 0; i < N; i++)
        freq[arr[i]]++;
    for (int i = 0; i < SIZE; i++)
    {
        if (freq[i] != 0 && freq[i] > (N / 2))
        return i;
    }
    return -1;
}

int main()
{
    int N;
    printf("Enter size of array:\n");
    scanf("%d", &N);
    int arr[N];
    printf("Enter elements of array:\n");
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    int ans = checkMajorityElement(arr, N);
    if (ans != -1)
        printf("Majority Element is: %d", ans);
    else
        printf("No majority element in array");
    return 0;
}

/*
Input:
N = 9
arr = {1, 2, 2, 2, 4, 2, 2, 1, 5}

Output:
Majority Element is: 2

Input:
N = 5
arr = {1, 2, 3, 4, 5}

Output:
No majority element in array
*/
