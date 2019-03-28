// GSSoC
// TimSort


#include<bits/stdc++.h> 
using namespace std; 

// MERGE SORT FUNCTION : 
void merge(int array[], int left, int mid, int right) 
{  

    int leftLength = mid - left + 1, rightLength = right - mid; 
    int Left[leftLength], Right[rightLength]; 
    for (int i = 0; i < leftLength; i++) 
	Left[i] = array[left + i]; 
    for (int i = 0; i < rightLength; i++) 
	Right[i] = array[mid + 1 + i]; 

    int i = 0; 
    int j = 0; 
    int k = left; 

    while (i < leftLength && j < rightLength) 
    { 
	if (Left[i] <= Right[j]) 
	{ 
	    array[k] = Left[i]; 
       	    i++; 
	} 
	else
	{ 
	    array[k] = Right[j]; 
	    j++; 
	} 
	k++; 
    } 
    while (i < leftLength) 
    { 
	array[k] = Left[i]; 
	k++; 
	i++; 
    }  
    while (j < rightLength) 
    { 
	array[k] = Right[j]; 
	k++; 
	j++; 
    } 
} 

// INSERTION SORT FUNCTION :
void insertionSort(int array[], int left, int right) 
{ 
    for (int i = left + 1; i <= right; i++) 
    { 
	int temp = array[i]; 
	int j = i - 1; 
	while (array[j] > temp && j >= left) 
	{ 
	    array[j+1] = array[j]; 
	    j--; 
	} 
	array[j+1] = temp; 
    } 
} 

int main() 
{ 
    int array[] = {50, 39, 89, 10, 8}; 
    int n = sizeof(array)/sizeof(array[0]); 
    printf("Unsorted Array :\n"); 
    for (int i = 0; i < n; i++) 
	printf("%d ", array[i]); 
    printf("\n");  


    int Limit=32;
    for (int i = 0; i < n; i+=Limit) 
	insertionSort(array, i, min((i+31), (n-1))); 

    for (int size = Limit; size < n; size = 2*size) 
    { 
	for (int left = 0; left < n; left += 2*size) 
	{ 
	    int mid = left + size - 1; 
	    int right = min((left + 2*size - 1), (n-1)); 
	    merge(array, left, mid, right); 
	} 
    } 

    printf("Sorted Array :\n"); 
 
    for (int i = 0; i < n; i++) 
	printf("%d ", array[i]); 
    printf("\n"); 


    return 0; 
} 
/*
OUTPUT
----------------
Unsorted Array :
50 39 89 10 8 
Sorted Array :
8 10 39 50 89
----------------
*/
// Happy Coding!

