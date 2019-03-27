# Merge Sort

Merge Sort is an algorithm, which is based on divide and conquer technique. It works by recursively breaking down a problem into two or more sub-problems of the same or related type, until these become simple enough to be solved directly. The solutions to the sub-problems are then combined to give a solution to the original problem. So Merge Sort first divides the array into equal halves and then combines them in a sorted manner.
Merge Sort is a stable sort which means that the same element in an array maintain their original positions with respect to each other.

## Algorithn

1. If it is only one element in the list it is already sorted, return.
2. Divide the list recursively into two halves until it can no more be divided.
3. Merge the smaller lists into new list in sorted order.

## Pseudocode

~~~
mergesort( var a as array )
   if ( n == 1 ) return a

   var l1 as array = a[0] ... a[n/2]
   var l2 as array = a[n/2+1] ... a[n]

   l1 = mergesort( l1 )
   l2 = mergesort( l2 )

   return merge( l1, l2 )
end procedure

merge( var a as array, var b as array )

   var c as array
   while ( a and b have elements )
      if ( a[0] > b[0] )
         add b[0] to the end of c
         remove b[0] from b
      else
         add a[0] to the end of c
         remove a[0] from a
      end if
   end while
   
   while ( a has elements )
      add a[0] to the end of c
      remove a[0] from a
   end while
   
   while ( b has elements )
      add b[0] to the end of c
      remove b[0] from b
   end while
   
   return c
	
end procedure
~~~

## Example

Below given is an array, which needs to be sorted. We will use the Merge Sort Algorithm to sort this array:

![Merge Sort Example 1](https://cdn-images-1.medium.com/max/800/1*nawdz45vLGeyD9zge_PpWA.jpeg)

Here is another example of sorting an array using Merge Sort Algorithm:

![Merge Sort Example 2](https://cdn-images-1.medium.com/max/800/1*aJ1YiME33o0dBZTCmid7iw.png)

## Complexity

The overall **time complexity** of Merge sort is O(nLogn). It is more efficient as it is in worst case also the runtime is O(nlogn).

The **space complexity** of Merge sort is O(n). This means that this algorithm takes a lot of space and may slower down operations for the last data sets.
