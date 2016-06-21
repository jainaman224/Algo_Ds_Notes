# BUBBLE SORT

[Bubble Sort](https://en.wikipedia.org/wiki/Bubble_sort) is the simplest sorting algorithm that works by repeatedly swapping the
adjacent elements if they are in wrong order. It makes multiple passes through a
 list, compares adjacent items and exchanges those that are out of
 order. Each pass through the list places the next largest value in its proper
  place.

## EXAMPLE

  Given below is an unsorted array. Bubble sort takes Ο(n2) time.

![image](http://www.tutorialspoint.com/data_structures_algorithms/images/bubble_sort_0.jpg)

Bubble sort starts with very first two elements, comparing them to check which one is greater.

![image](http://www.tutorialspoint.com/data_structures_algorithms/images/bubble_sort_1.jpg)

In this case, value 33 is greater than 14, so it is already in sorted locations. Next, we compare 33 with 27.

![image](http://www.tutorialspoint.com/data_structures_algorithms/images/bubble_sort_2.jpg)

We find that 27 is smaller than 33 and these two values must be swapped.

![image](http://www.tutorialspoint.com/data_structures_algorithms/images/bubble_sort_3.jpg)

The new array should look like this −

![image](http://www.tutorialspoint.com/data_structures_algorithms/images/bubble_sort_4.jpg)

Next we compare 33 and 35. We find that both are in already sorted positions.

![image](http://www.tutorialspoint.com/data_structures_algorithms/images/bubble_sort_5.jpg)

Then we move to next two values, 35 and 10.

![image](http://www.tutorialspoint.com/data_structures_algorithms/images/bubble_sort_6.jpg)

We know than 10 is smaller 35. Hence they are not sorted.

![image](http://www.tutorialspoint.com/data_structures_algorithms/images/bubble_sort_7.jpg)

We swap these values. We find that we reach at the end of the array. After one iteration the array should look like this −

![image](http://www.tutorialspoint.com/data_structures_algorithms/images/bubble_sort_8.jpg)

To be precise, we are now showing that how array should look like after each iteration. After second iteration, it should look like this −

![image](http://www.tutorialspoint.com/data_structures_algorithms/images/bubble_sort_9.jpg)

Notice that after each iteration, at least one value moves at the end.

![image](http://www.tutorialspoint.com/data_structures_algorithms/images/bubble_sort_10.jpg)

And when there's no swap required, bubble sorts learns that array is completely sorted.

![image](http://www.tutorialspoint.com/data_structures_algorithms/images/bubble_sort_11.jpg)

## ALGORITHM

We assume list is an array of n elements. We further assume that swap function, swaps the values of given array elements.

```
begin BubbleSort(list)

for all elements of list
  if list[i] > list[i+1]
     swap(list[i], list[i+1])
  end if
end for

return list

end BubbleSort
```
## PSEUDOCODE

We use one flag variable swapped which will help us to see if any swap is happened or not. If no swap is occurred, i.e. the array requires no more processing to be sorted, it will come out of the loop.

Pseudocode of BubbleSort algorithm can be expressed as −

```
procedure bubbleSort( list : array of items )

   loop = list.count;

   for i = 0 to loop-1 do:
      swapped = false

      for j = 0 to loop-1 do:

         /* compare the adjacent elements */   
         if list[j] > list[j+1] then
            /* swap them */
            swap( list[j], list[j+1] )		 
            swapped = true
         end if

      end for

      /*if no number was swapped that means
      array is sorted now, break the loop.*/

      if(not swapped) then
         break
      end if

   end for

end procedure return list
```
## COMPLEXITY

Bubble sort has **worst-case** and **average complexity** both О(n2), where n is the number of items being sorted.
When the list is already sorted (**best-case**), the complexity of bubble sort is O(n).
