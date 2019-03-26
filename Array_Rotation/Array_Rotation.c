//Program to rotate array Arr[] of size n by d Elements
#include <stdio.h>

void Rotate(int arr[], int r, int n)
{
	int temp[r];
	for (int i = 0; i < r; i++)
		temp[i] = arr[i];

	for (int i = r; i < n; i++)
		arr[i-r] = arr[i];

	for (int i = n-r; i < n; i++)
		arr[i] = temp[i-(n-r)];
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int r = 2;

	int n = sizeof(arr)/sizeof(arr[0]);

	Rotate(arr, r, n);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	return 0;
}

/*
Input array: {1, 2, 3, 4, 5}
Expected Output
3 4 5 1 2 
*/
