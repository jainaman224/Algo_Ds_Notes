# Exponential Search

Exponential search (also called doubling search or galloping search or Struzik search) is a searching technique for sorted, unbounded/infinite lists.
There are multiple ways to perform this method, but the most common and useful one is to find the range in which the element to be searched must be present. This is done by applying a Binary Search between the ranges.

The name of this searching algorithm may be misleading but it works in O(Log n) time. The name comes from the way it searches an element.

## Explanation

Exponential search involves two steps:

1. Find range where element is present
2. Do Binary Search in above found range.

The idea is to start with subarray size 1, compare its last element with x, then try size 2, then 4 and so on until last element of a subarray is not greater.
Once we find an index i (after repeated doubling of i), we know that the element must be present between i/2 and i (Why i/2? because we could not find a greater value in previous iteration)

## Algorithm

The algorithm consists of two stages. The first stage determines a range in which the search key would reside if it were in the list. In the second stage, a binary search is performed on this range. In the first stage, assuming that the list is sorted in ascending order, the algorithm looks for the first exponent, j, where the value 2j is greater than the search key. This value, 2j becomes the upper bound for the binary search with the previous power of 2, 2j - 1, being the lower bound for the binary search.[3]

// Returns the position of key in the array arr of length size.
template <typename T>
int exponential_search(T arr[], int size, T key)
{
    if (size == 0)
    {
        return NOT_FOUND;
    }

    int bound = 1;
    while (bound < size && arr[bound] < key)
    {
        bound*= 2;
    }

    return binary_search(arr, key, bound/2, min(bound + 1, size));
}
In each step, the algorithm compares the search key value with the key value at the current search index. If the element at the current index is smaller than the search key, the algorithm repeats, skipping to the next search index by doubling it, calculating the next power of 2.[3] If the element at the current index is larger than the search key, the algorithm now knows that the search key, if it is contained in the list at all, is located in the interval formed by the previous search index, 2j - 1, and the current search index, 2j. The binary search is then performed with the result of either a failure, if the search key is not in the list, or the position of the search key in the list.

## Pseudocode

Input: An sorted array, start and end location, and the search key.

Output: location of the key (if found), otherwise wrong location.

 Begin
   
   if (end – start) <= 0 then
       
       return invalid location
   
   i := 1
   
  while i < (end - start) do
      
      if array[i] < key then   
          
          i := i * 2 //increase i as power of 2
      
      else
        
        terminate the loop
   
    done
   
   call binarySearch(array, i/2, i, key)
 
 End


## Example

Given a sorted array, and an element x to be searched, find position of x in the array.

1. Input:  arr[] = {10, 20, 40, 45, 55}
        x = 45
Output: Element found at index 3

2. Input:  arr[] = {10, 15, 25, 45, 55}
        x = 15
Output: Element found at index 1

## The complexity of Exponential Search Technique

1. Time Complexity: O(1) for the best case. O(log2 i) for average or worst case. Where i is the location where search key is present.

2. Space Complexity: O(1)

## See also

* [Wikipedia : Exponential Search](https://en.wikipedia.org/wiki/Exponential_search)
* [geeksforgeeks : Exponential Search](https://www.geeksforgeeks.org/exponential-search/)
