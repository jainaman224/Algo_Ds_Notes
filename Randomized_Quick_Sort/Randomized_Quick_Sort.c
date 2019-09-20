#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int partition(int arr[], int low, int high) 
{ 
	int pivot = arr[high]; // pivot 
	int i = (low - 1); // Index of smaller element 

	for (int j = low; j <= high - 1; j++) { 

		// If current element is smaller than or 
		// equal to pivot 
		if (arr[j] <= pivot) { 

			i++; // increment index of smaller element 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

// Generates Random Pivot, swaps pivot with 
// end element and calls the partition function 
int partition_r(int arr[], int low, int high) 
{ 
	// Generate a random number in between 
	// low .. high 
	srand(time(NULL)); 
	int random = low + rand() % (high - low); 

	// Swap A[random] with A[high] 
	swap(&arr[random], &arr[high]); 

	return partition(arr, low, high); 
} 

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) { 

		/* pi is partitioning index, arr[p] is now 
		at right place */
		int pi = partition_r(arr, low, high); 

		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 

// Driver program to test above functions 
int main() 
{ 
	int i,n;
	printf("Enter the size of array:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter Array element:\n");
	for(i = 0; i<n; i++)
		scanf("%d",&arr[i]);
	quickSort(arr, 0, n - 1); 
	printf("Sorted array: \n"); 
	printArray(arr, n); 
	return 0; 
} 
/*
Enter the size of array:5
Enter Array element:
10
4
3
8
6
Sorted array: 
3 4 6 8 10 
*/
