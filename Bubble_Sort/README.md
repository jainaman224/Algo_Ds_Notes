# BUBBLE SORT

[Bubble Sort](https://en.wikipedia.org/wiki/Bubble_sort) is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order. It makes multiple passes through a list, compares adjacent items and exchanges those that are out of order. Each pass through the list places the next largest value in its proper place.

## EXAMPLE

Given below is an unsorted array. `Bubble sort` takes Ο(n^2) time.

![Bubble Sort](http://www.tutorialspoint.com/data_structures_algorithms/images/bubble_sort_0.jpg)

`Bubble sort` starts with very first two elements, comparing them to check which one is greater.

![Bubble Sort](http://www.tutorialspoint.com/data_structures_algorithms/images/bubble_sort_1.jpg)

In this case, value 33 is greater than 14, so it is already in sorted locations. Next, we compare 33 with 27.

![Bubble Sort](http://www.tutorialspoint.com/data_structures_algorithms/images/bubble_sort_2.jpg)

We find that 27 is smaller than 33 and these two values must be swapped.

![Bubble Sort](http://www.tutorialspoint.com/data_structures_algorithms/images/bubble_sort_3.jpg)

The new array should look like this −

![Bubble Sort](http://www.tutorialspoint.com/data_structures_algorithms/images/bubble_sort_4.jpg)

Next we compare 33 and 35. We find that both are in already sorted positions.

![Bubble Sort](http://www.tutorialspoint.com/data_structures_algorithms/images/bubble_sort_5.jpg)

Then we move to next two values, 35 and 10.

![Bubble Sort](http://www.tutorialspoint.com/data_structures_algorithms/images/bubble_sort_6.jpg)

We know than 10 is smaller 35. Hence they are not sorted.

![Bubble Sort](http://www.tutorialspoint.com/data_structures_algorithms/images/bubble_sort_7.jpg)

We swap these values. We find that we reach at the end of the array. After one iteration the array should look like this −

![Bubble Sort](http://www.tutorialspoint.com/data_structures_algorithms/images/bubble_sort_8.jpg)

To be precise, we are now showing that how array should look like after each iteration.

After second iteration, it should look like this −

![Bubble Sort](http://www.tutorialspoint.com/data_structures_algorithms/images/bubble_sort_9.jpg)

Notice that after each iteration, at least one value moves at the end.

![Bubble Sort](http://www.tutorialspoint.com/data_structures_algorithms/images/bubble_sort_10.jpg)

And when there's no swapping required, bubble sorts learns that array is completely sorted.

![Bubble Sort](http://www.tutorialspoint.com/data_structures_algorithms/images/bubble_sort_11.jpg)

## PSEUDOCODE

We use one flag variable swapped which will help us to see if any swap is happened or not. If no swap is occurred, i.e. the array requires no more processing to be sorted, it will come out of the loop.

Pseudocode of BubbleSort algorithm can be expressed as −

```
procedure bubbleSort(list : array of items)

    loop = list.count;

    for i = 0 to loop-1 do:
        swapped = false

        for j = 0 to loop-i-1 do:

            /* compare the adjacent elements */
            if list[j] > list[j+1] then
                /* swap them */
                swap(list[j], list[j+1])
                swapped = true
            end if

        end for

        /*if no number was swapped that means
        array is sorted now, break the loop.*/

        if(not swapped) then
            break
        end if
    end for

end procedure and return list
```

## COMPLEXITY

**Time complexity**  - О(n^2), where n is the number of items being sorted.

**Space complexity** - O(1), due to auxillary space only.

## Implementation

- [C Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Bubble_Sort/Bubble_Sort.c)
> :rocket: [Compile Online](https://repl.it/EKfI) :rocket:

- [CoffeeScript Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Bubble_Sort/Bubble_Sort.coffee)
> :rocket: [Compile Online](https://repl.it/Cx3l) :rocket:

- [C++ Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Bubble_Sort/Bubble_Sort.cpp)
> :rocket: [Compile Online](https://repl.it/C4eS) :rocket:

- [C# Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Bubble_Sort/Bubble_Sort.cs)
> :rocket: [Compile Online](https://repl.it/Cx3r) :rocket:

- [Java Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Bubble_Sort/Bubble_Sort.java)
> :rocket: [Compile Online](https://repl.it/C4eX) :rocket:

- [JavaScript Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Bubble_Sort/Bubble_Sort.js)
> :rocket: [Compile Online](https://repl.it/Cx3t) :rocket:

- [PHP Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Bubble_Sort/Bubble_Sort.php)
> :rocket: [Compile Online](https://repl.it/Cx4B) :rocket:

- [Python Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Bubble_Sort/Bubble_Sort.py)
> :rocket: [Compile Online](https://repl.it/C4eV) :rocket:
