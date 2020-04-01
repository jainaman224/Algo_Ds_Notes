# [Pancake Sort](https://www.youtube.com/watch?v=kk-_DDgoXfk)
In Pancake sort, we are allowed to do only following operation on array in order to sort it.
```
flip(arr, i): Reverse array from 0 to i 
```
It is like sorting a disordered stack of pancakes in order of size when a spatula can be inserted at any point in the stack
and used to flip all pancakes above it. A pancake number is the minimum number of flips required for a given number of pancakes.

![Image](https://upload.wikimedia.org/wikipedia/commons/0/0f/Pancake_sort_operation.png)
>_The spatula is flipping over the top three pancakes, with the result seen in second part._

Unlike a traditional sorting algorithm, which attempts to sort with the fewest comparisons possible, the goal is to sort the sequence in as few reversals as possible.

Following are the detailed steps. Let given array be arr[] and size of array be n.
1. Start from current size equal to n and reduce current size by one while it’s greater than 1.
1. Let the current size be current_size. Do following for every current_size.
   - Find index of the maximum element in arr[0..current_szie-1]. Let the index be ‘max_index’.
   - Call flip(arr, max_index).
   - Call flip(arr, current_size-1).




