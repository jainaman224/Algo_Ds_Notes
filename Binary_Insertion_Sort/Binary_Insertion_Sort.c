//Binary Insertion sort is a variant of Insertion sorting in which proper location to insert
//the selected element is found using the binary search.
#include <stdio.h> 
#include <stdlib.h>

int binarySearch(int arr[], int item, int start, int end) ; 

void insertionSort(int arr[], int size) 
{ 
    int i, location, j, k, key; 
    for (i = 1; i < size; ++i) 
    { 
        j = i - 1; 
        key = arr[i]; 
        //to find location where key sould be inserted
        location = binarySearch(arr, key, 0, j); 
        // to move all elements after location to create space for key
        while (j >= location) 
        { 
            arr[j+1] = arr[j]; 
            j--; 
        } 
        arr[j+1] = key; 
    } 
}

int binarySearch(int arr[], int item, int start, int end) 
{ 
    if (end <= start) 
        return (item > arr[start])?  (start + 1): start; 
    int mid = (start + end)/2; 
    if(item == arr[mid]) 
        return mid+1; 
    if(item > arr[mid]) 
        return binarySearch(arr, item, mid+1, end); 
    return binarySearch(arr, item, start, mid-1); 
} 
  
int main() 
{
   int size,i;
   printf("Enter the size of the array ");
   scanf("%d",&size);
   int arr[size];
   printf("Enter the elements ");
   for ( i=0;i<size;i++)
       scanf("%d",&arr[i]) ; 
   insertionSort(arr,size ); 
   printf("Sorted array: \n"); 
    for (i = 0; i < size; i++) 
        printf("%d ",arr[i]); 
  
    return 0; 
} 
//INPUT:Enter the size of the array 5
//Enter the elements 34
//75
//24
//1
//6
//OUTPUT:Sorted array: 
//1 6 24 34 75
