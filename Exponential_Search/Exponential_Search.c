
//An exponential search (for sorted array) is a combination of two methods:
//1.Find the range in which the element exists.
//2.Perform a binary search in that range.
//Time Complexity : O(Log n)

#include <stdio.h>
#include <stdlib.h>
  
int binarySearch(int arr[], int start, int end, int key);

int exponentialSearch(int arr[], int size, int key) 
{ 
   if (arr[0] == key) 
        return 0; 
   int i = 1; 
   while (i < size && arr[i] <= key) 
        i = i*2; 
   int x;
   // i should not be greater than size for searching
   if (i > size)
      x=size;
   else 
      x=i;
   return binarySearch(arr, i/2,x, key); 
} 
  
int binarySearch(int arr[], int start, int end, int key) 
{ 
    if (end >= start) 
    { 
        int mid = start + (end - start)/2; 
        if (arr[mid] == key) 
            return mid; 
        if (arr[mid] > key) 
            return binarySearch(arr, start, mid-1, key); 
        return binarySearch(arr, mid+1, end, key); 
    } 
  return -1; 
} 
  
int main() 
{  
   int size; 
   printf("Enter the size of the array ");
   scanf("%d",&size);
   int arr[size];
   printf("Enter the elements ");
   for (int i=0;i<size;i++)
       scanf("%d",&arr[i] ); 
    
   int key; 
   printf("Enter the element that you want to search ");
   scanf("%d",&key);
   
   int result ;
   result = exponentialSearch(arr,size, key);
   if(result == -1)
      printf("Element is not present in array") ;
   else
      printf("Element is present at index %d", result);
                                                    
   return 0; 
}
//INPUT:Enter the size of the array 5
//Enter the elements 1
//2
//3
//4
//5
//Enter the element that you want to search 4
//OUTPUT:Element is present at index 3
