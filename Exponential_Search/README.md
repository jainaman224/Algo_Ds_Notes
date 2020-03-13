# Exponential Search

Exponential search (also called doubling search or galloping search or Struzik search) is a searching technique for sorted, unbounded/infinite lists.

 ![alt text](https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.youtube.com%2Fwatch%3Fv%3DBDVYtuWXgXE&psig=AOvVaw0GNhWGATKKDle-deGn2mwG&ust=1584177000138000&source=images&cd=vfe&ved=0CAIQjRxqFwoTCKCQqZaNl-gCFQAAAAAdAAAAABAD)

 The name of this searching algorithm may be misleading but it works in O(Log n) time. The name comes from the way it searches an element.

 Exponential search involves two steps:

 1. Find range where element is present
 2. Do Binary Search in above found range.

 ## Now, the question arises -

### How to find the range where element may be present?

The idea is to start with subarray size 1, compare its last element with x, then try size 2, then 4 and so on until last element of a subarray is not greater.
Once we find an index i (after repeated doubling of i), we know that the element must be present between i/2 and i (Why i/2? because we could not find a greater value in previous iteration)

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
