# Ternary Search

Ternary search is a searching technique that is used to search the position of a specific value in an array. Ternary search is a divide-and-conquer algorithm. It is mandatory for the array to be sorted (in which you will search for an element).

The array is divided into three parts and then we determine in which part the element exists. In this search, after each iteration it neglects ⅓ part of the array and repeats the same operations on the remaining ⅔.

## Algorithm

  1.mid1 = start + (end - start) / 3 and mid2 = mid1 + (end - start) / 3.

  2.Compare the element to be searched with the element at mid1. If they are equal then return mid1.
 
  3.Compare the element to be searched with the element at mid2. If they are equal then return mid2.
  
  4.If the element to be searched is less than element at mid1 recur to the first part, otherwise if it is greater than  the element at mid2 recur to the third part. If not both, then recur to the second part.

## Pseudo Code

```
    ternarySearch(array, start, end, searchKey)
        if start <= end then   
            mid1 = start + (end - start) / 3
            mid2 = mid1 + (end - start) / 3
            if array[mid1] = searchKey then
                return mid1
            if array[mid2] = searchKey then
            	return mid2
            if searchKey < array[mid1] then
                call ternarySearch(array, start, mid1 - 1, searchKey)
            if searchKey > array[mid2] then
                call ternarySearch(array, mid2 + 1, end, searchKey)
            else
                call ternarySearch(array, mid1 + 1, mid2-1, searchKey)
```

## Complexity
       Time Complexity: O(log3 n)
       Space Complexity: O(1)
       
 ## Implementation
 * [C Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Ternary_Search/Ternary_Search.c)
 * [C++ Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Ternary_Search/Ternary_Search.cpp)
 * [Java Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Ternary_Search/Ternary_Search.java)
 * [Coffee Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Ternary_Search/Ternary_Search.coffee)
 * [Python Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Ternary_Search/Ternary_Search.py)
 * [JS Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Ternary_Search/Ternary_Search.js)
 * [C# Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Ternary_Search/Ternary_Search.cs)
 * [Kotlin Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Ternary_Search/Ternary_Search.kt)
