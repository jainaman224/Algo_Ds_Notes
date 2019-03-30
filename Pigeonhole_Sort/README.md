## Pigeonhole Sort

Pigeonhole sorting is a sorting algorithm that is suitable for sorting lists of elements where the number of elements (n) and the length of the range of possible key values (N) are approximately the same. It requires O(n + N) time. It is similar to counting sort, but differs in that it "moves items twice: once to the bucket array and again to the final destination whereas counting sort builds an auxiliary array then uses the array to compute each item's final destination and move the item there.

### The pigeonhole algorithm works as follows:

* Given an array of values to be sorted, set up an auxiliary array of initially empty "pigeonholes," one pigeonhole for each key through the range of the original array.
* Going over the original array, put each value into the pigeonhole corresponding to its key, such that each pigeonhole eventually contains a list of all values with that key.
* Iterate over the pigeonhole array in order, and put elements from non-empty pigeonholes back into the original array.

 ![]( https://github.com/p-rit/Images/blob/master/Pigeonhole_sort_images/Capture.PNG )

 ## Pseudocode

    find max and min from the array list
     holeRange := max – min +1
    define holeRange number of Lists

    for i := 0 to n-1 do
      hole[array[i]-min].append(array[i])
   
    count := 0
    for j := 0 to holeRange-1 do
      while hole[j] is not empty do
         array[count] := get first node of hole[j] and delete it
         count := count +1  

## Time complexity

It requires O(n + Range) time where n is number of elements in input array and ‘Range’ is number of possible values in array.

## Reference
* [Sort](https://riptutorial.com/algorithm/example/24298/pigeonhole-sort-basic-information)
* [Pigeon hole](https://www.geeksforgeeks.org/pigeonhole-sort/)
* [wikipedia](https://en.wikipedia.org/wiki/Pigeonhole_sort)
