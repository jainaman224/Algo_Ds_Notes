# INSERTION SORT

[Insertion Sort](https://en.wikipedia.org/wiki/Insertion_Sort) is a simple sorting algorithm that builds the final sorted array (or list) one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.

## EXAMPLE

Given below is an unsorted array. `Insertion sort` takes O(n) time in Best Case and Ο(n<sup>2</sup>) time for Average and Worst Case.

![Insertion Sort](https://www.tutorialspoint.com/data_structures_algorithms/images/unsorted_array.jpg)

`Insertion sort` compares the first two elements

![Insertion Sort](https://www.tutorialspoint.com/data_structures_algorithms/images/insertion_sort_1.jpg)

It finds that both 14 and 33 are already in ascending order. For now, 14 is in sorted sub-list.

![Insertion Sort](https://www.tutorialspoint.com/data_structures_algorithms/images/insertion_sort_2.jpg)

Insertion sort moves ahead and compares 33 with 27.

![Insertion Sort](https://www.tutorialspoint.com/data_structures_algorithms/images/insertion_sort_3.jpg)

And finds that 33 is not in the correct position.

![Insertion Sort](https://www.tutorialspoint.com/data_structures_algorithms/images/insertion_sort_4.jpg)

It swaps 33 with 27. It also checks with all the elements of sorted sub-list. Here we see that the sorted sub-list has only one element 14, and 27 is greater than 14. Hence, the sorted sub-list remains sorted after swapping.

![Insertion Sort](https://www.tutorialspoint.com/data_structures_algorithms/images/insertion_sort_5.jpg)

By now we have 14 and 27 in the sorted sub-list. Next, it compares 33 with 10.

![Insertion Sort](https://www.tutorialspoint.com/data_structures_algorithms/images/insertion_sort_6.jpg)

These values are not in a sorted order.

![Insertion Sort](https://www.tutorialspoint.com/data_structures_algorithms/images/insertion_sort_7.jpg)

So we swap them.

![Insertion Sort](https://www.tutorialspoint.com/data_structures_algorithms/images/insertion_sort_8.jpg)

However, swapping makes 27 and 10 unsorted.

![Insertion Sort](https://www.tutorialspoint.com/data_structures_algorithms/images/insertion_sort_9.jpg)

Hence, we swap them too.

![Insertion Sort](https://www.tutorialspoint.com/data_structures_algorithms/images/insertion_sort_10.jpg)

Again we find 14 and 10 in an unsorted order.

![Insertion Sort](https://www.tutorialspoint.com/data_structures_algorithms/images/insertion_sort_11.jpg)

We swap them again. By the end of third iteration, we have a sorted sub-list of 4 items.

![Insertion Sort](https://www.tutorialspoint.com/data_structures_algorithms/images/insertion_sort_12.jpg)

This process goes on until all the unsorted values are covered in a sorted sub-list. Now we shall see some programming aspects of insertion sort.

## ALGORITHM

```
Step 1 − If it is the first element, it is already sorted. return 1;
Step 2 − Pick next element
Step 3 − Compare with all elements in the sorted sub-list
Step 4 − Shift all the elements in the sorted sub-list that is greater than the value to be sorted
Step 5 − Insert the value
Step 6 − Repeat until list is sorted
```

## PSEUDOCODE

Pseudocode of InsertionSort algorithm can be expressed as −

```
procedure insertionSort( A : array of items )
   int holePosition
   int valueToInsert

   for i = 1 to length(A) inclusive do:

      /* select value to be inserted */
      valueToInsert = A[i]
      holePosition = i

      /*locate hole position for the element to be inserted */

      while holePosition > 0 and A[holePosition-1] > valueToInsert do:
         A[holePosition] = A[holePosition-1]
         holePosition = holePosition -1
      end while

      /* insert the number at hole position */
      A[holePosition] = valueToInsert

   end for

end procedure
```

## COMPLEXITY

**Time complexity**

_Best Case_: O(n)

_Average and Worst Case_: О(n<sup>2</sup>)

where _n_ is the number of items being sorted.

**Space complexity** - O(1), due to auxillary space only.

## Implementation

- [C Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Insertion_Sort/Insertion_Sort.c)

- [CoffeeScript Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Insertion_Sort/Insertion_Sort.coffee)

- [C++ Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Insertion_Sort/Insertion_Sort.cpp)

- [C# Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Insertion_Sort/Insertion_Sort.cs)

- [Java Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Insertion_Sort/Insertion_Sort.java)

- [JavaScript Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Insertion_Sort/Insertion_Sort.js)

- [PHP Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Insertion_Sort/Insertion_Sort.php)

- [Python Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Insertion_Sort/Insertion_Sort.py)
