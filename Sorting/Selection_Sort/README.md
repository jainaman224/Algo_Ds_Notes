# SELECTION SORT

The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from the unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.
1. The subarray which is already sorted.
2. Remaining subarray which is unsorted.

In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.

## Example

![Selection Sort](http://www.cs.rmit.edu.au/online/blackboard/chapter/05/documents/contribute/chapter/09/images/selection-sort.gif)

## Algorithm

```
Step 1 − Set MIN to location 0
Step 2 − Search the minimum element in the list
Step 3 − Swap with value at location MIN
Step 4 − Increment MIN to point to next element
Step 5 − Repeat until list is sorted
```

## PSEUDOCODE

Pseudocode of Selection Sort algorithm can be expressed as −

```
procedure selection sort
    list  : array of items
    n     : size of list

    for i = 1 to n - 1
        /* Set current element as minimum */
        min = i

        /* Check the element to be minimum */

        for j = i+1 to n
            if list[j] < list[min] then
                min = j;
            end if
        end for

        /* Swap the minimum element with the current element */
        if indexMin != i  then
            swap list[min] and list[i]
        end if

    end for

end procedure
```

## COMPLEXITY

**Time complexity**  - О(n^2), where n is the number of items being sorted.
**Space complexity** - O(1), due to auxillary space only.

#### Stability

The definition of stable is that the relative order of elements with the same value is maintained even after sorting.

Selection Sort is `Not Stable`

For eg: when we sort `5 1 2 3 4 5 0` using `selection sort`, After first round 0 will be the minimum value and it will be swapped with the 5 in first position causing change in relative order of the 5's.
(`0 1 2 3 4 5 5`)

As the relative order of elements having same value(5) is changed, we can clearly state that Selection Sort is not stable.

## Implementation

- [C++ Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Selection_Sort/Selection_Sort.cpp)
> :rocket: [Compile Online](https://repl.it/C6sP) :rocket:

- [Java Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Selection_Sort/Selection_Sort.java)
> :rocket: [Compile Online](https://repl.it/C6sW) :rocket:

- [Python Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Selection_Sort/Selection_Sort.py)
> :rocket: [Compile Online](https://repl.it/C6sT) :rocket:
