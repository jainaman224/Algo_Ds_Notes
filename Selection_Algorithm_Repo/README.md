# SELECTION ALGORITHM

This is type of algorithm, where  to find the k-th smallest element in an unordered list. It is related to the quick sort sorting algorithm.
The algorithm is similar to QuickSort. The difference is, instead of recurring for both sides (after finding pivot), it recurs only for the part that contains the k-th smallest element. 
The logic is simple, if index of partitioned element is more than k, then we recur for left part. 
If index is same as k, we have found the k-th smallest element and we return. 
If index is less than k, then we recur for right part. This reduces the expected complexity from O(n log k) to O(n), with a worst case of O(n^2).
Like quicksort, it is fast in practice, but has poor worst-case performance.
The partition process is same as QuickSort, only recursive code differs.
There exists an algorithm that finds k-th smallest element in O(n) in worst case, but QuickSelect performs better on average.

## Example

![Selection Algorithm](https://upload.wikimedia.org/wikipedia/commons/0/04/Selecting_quickselect_frames.gif)

## Algorithm

```
Step 1 − Move pivot to end
Step 2 − Move pivot to its final place
Step 3 − Returns the k-th smallest element of list within left..right inclusive
Step 4 − The search space within the array is changing for each round - but the list
Step 5 − is still the same size. Thus, k does not need to be updated with each round.
Step 6 - If the list contains only one element,return that element
Step 7 - select a pivotIndex between left and right
Step 8 - The pivot is in its final sorted position
Step 9 - select pivotIndex between left and right

```

## PSEUDOCODE

Pseudocode of Selection  algorithm can be expressed as −

```
function partition(list, left, right, pivotIndex)
     pivotValue := list[pivotIndex]
     swap list[pivotIndex] and list[right]  
     storeIndex := left
     for i from left to right-1
         if list[i] < pivotValue
             swap list[storeIndex] and list[i]
             increment storeIndex
     swap list[right] and list[storeIndex]  
     return storeIndex
function select(list, left, right, k)
     if left = right        
         return list[left]  
     pivotIndex  := ...     
     pivotIndex  := partition(list, left, right, pivotIndex)
     if k = pivotIndex
         return list[k]
     else if k < pivotIndex
         return select(list, left, pivotIndex - 1, k)
     else
         return select(list, pivotIndex + 1, right, k)
function select(list, left, right, k)
     loop
         if left = right
             return list[left]
         pivotIndex := ...     // select pivotIndex between left and right
         pivotIndex := partition(list, left, right, pivotIndex)
         if k = pivotIndex
             return list[k]
         else if k < pivotIndex
             right := pivotIndex - 1
         else
             left := pivotIndex + 1

```

## COMPLEXITY

**Time complexity**  - О(nlogk)[average case],O(n^2)[worst case], where n is the number of items being sorted.

