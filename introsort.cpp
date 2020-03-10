#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// Function to perform insertion sort on the array a[]
void InsertionSort(int a[], int low, int high)
{
	// start from the second element in the sub-array
	// (element at index 'low' is already sorted)
	for (int i = low + 1; i <= high; i++)
	{
		int value = a[i];
		int j = i;

		// Find the index j within the sorted subset a[0..i-1]
		// where element a[i] belongs
		while (j > low && a[j - 1] > value)
		{
			a[j] = a[j - 1];
			j--;
		}
		// Note that subarray a[j..i-1] is shifted to
		// the right by one position i.e. a[j+1..i]

		a[j] = value;
	}
}

// Function to partition the array using Lomuto partition scheme
int Partition (int a[], int low, int high)
{
	// Pick rightmost element as pivot from the array
	int pivot = a[high];

	// elements less than pivot will be pushed to the left of pIndex
	// elements more than pivot will be pushed to the right of pIndex
	// equal elements can go either way
	int pIndex = low;

	// each time we finds an element less than or equal to pivot, pIndex
	// is incremented and that element would be placed before the pivot.
	for (int i = low; i < high; i++)
	{
		if (a[i] <= pivot)
		{
			swap(a[i], a[pIndex]);
			pIndex++;
		}
	}
	// swap pIndex with Pivot
	swap (a[pIndex], a[high]);

	// return pIndex (index of pivot element)
	return pIndex;
}

// Function to perform heap sort on the given range of elements
void heapsort(int *begin, int *end)
{
	make_heap(begin, end);
	sort_heap(begin, end);
}

// Function to perform introsort on the array a[]
void introsort(int a[], int *begin, int *end, int maxdepth)
{
	// perform insertion sort if partition size is 16 or smaller
	if ((end - begin) < 16) {
		InsertionSort(a, begin - a, end - a);
	}
	// perform heapsort if maximum depth is 0
	else if (maxdepth == 0) {
		heapsort(begin, end + 1);
	}
	else {
		// otherwise perform quicksort
		int pivot = Partition(a, begin - a, end - a);
		introsort(a, begin, a + pivot - 1, maxdepth - 1);
		introsort(a, a + pivot + 1, end, maxdepth - 1);
	}
}

int main()
{
	int a[] = { 5, 7, -8, 9, 10, 4, -7, 0, -12, 1, 6, 2, 3, -4, -15, 12 };
	int n = sizeof(a) / sizeof(a[0]);

	// get maximum depth
	int maxdepth = log(n) * 2;

	// sort the array using introsort algorithm
	introsort(a, a, a + n - 1, maxdepth);

	// print the sorted array
	for (int i = 0 ; i < n; i++)
		cout << a[i] << " ";

	return 0;
}