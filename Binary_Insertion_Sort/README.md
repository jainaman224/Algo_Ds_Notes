     BINARY INSERTION SORT:

Binary Insertion sort is a special type up of Insertion sort which uses binary search algorithm to find out the correct position of the inserted element in the array.

Binary search is searching technique that works by finding the middle of the array for finding the element.

Insertion sort is sorting technique that works by finding the correct position of the element in the array and then inserting it into its correct position.

Binary Insertion Sort uses binary search to find the proper location to insert the selected item at each iteration.
In normal insertion sort, it takes O(n) comparisons(at nth iteration) in worst case. We can reduce it to O(log n) by using binary search.

    TIME COMPLEXITY:

|ALGORITHM            |              BEST-CASE   |  AVG-CASE |     WORST-CASE|
|---------------------|--------------------------|-----------|---------------|
|INSERTION SORT  |                O(N)      |    O(N^2) |        O(N^2) |    
|BINARY INSERTION SORT|       O(N log N)         |     O(N^2)|        O(N^2) |     


    ADVANTAGE of BINARY INSERTION SORT over INSERTION SORT:

  The binary insertion sort does fewer array element comparisons than insertion sort.

  The number of comparisons required by the normal insertion sort is O(N^2) in the worst case as well as on average. Therefore on average, the binary insertion sort uses fewer comparisons than normal insertion sort.
          
