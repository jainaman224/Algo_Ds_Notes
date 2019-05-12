#include <stdio.h>
#include <windows.h>
#include <process.h>

void routine(void *a)
{
    int n = *(int *) a;
    Sleep(n);
    printf("%d ", n);
}

void sleepSort(int arr[], int n)
{
    int i;
    HANDLE threads[n];
    for (i = 0; i < n; i++)
        threads[i] = (HANDLE)_beginthread(&routine, 0, &arr[i]);
    WaitForMultipleObjects(n, threads, TRUE, INFINITE);
    return;
}

int main()
{
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sleepSort (arr, n);

    return 0;
}

/*
INPUT:
n = 4
arr[] = {12, 42, 23, 3}
OUTPUT:
3 12 23 42
*/
