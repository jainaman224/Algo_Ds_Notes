#include <stdlib.h> 
#include <stdio.h> 
  
//Reverses array
void flip (int arr[], int n) { 
    int temp, start = 0; 
    while (start < n) { 
        temp = arr[start]; 
        arr[start] = arr[n]; 
        arr[n] = temp; 
        start++; 
        n--; 
    } 
} 
  
// Returns index of element with maximum value in the array
int max_ind (int arr[], int n) { 
    int index = 0, i; 
    for (i = 0; i < n; ++i) 
        if (arr[i] > arr[index]) 
            index = i; 
    return index; 
} 
  
// Function to sort the array using pancake sort
int pancakeSort (int arr[], int n) { 
    int size, max;
    // Reduce size of the array one at a time
    for (size = n; size > 1; size--) { 
        max = max_ind(arr, size); 
        // if the max element is not in the end of the array move it there
        if (max != size-1) { 
            // We move the maximum element to the beginning and then flip the array to move the element to the end
            flip(arr, max);  
            flip(arr, size-1); 
        } 
    } 
}
  
int main() { 
    int arr[] = {-10, 1, 99, 10, -2, 0, 5, 6}; 
    int n, i;
    n = sizeof(arr)/sizeof(arr[0]); 
    printf("Unsorted Array: ");
    for(i = 0; i < n; i++)
    	printf("%d ", arr[i]);
    
    pancakeSort(arr, n); 
  
    printf("\nSorted Array: "); 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    return 0; 
} 

// Output:

// Unsorted Array: -10 1 99 10 -2 0 5 6
// Sorted Array: -10 -2 0 1 5 6 10 99
