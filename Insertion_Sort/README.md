# Insertion Sort



It iterates the input elements by adding them to the sorted array at each iteration.

  - It compares the current element with the largest value in the sorted array. If the current element is greater, then it leaves the element in its place and moves on to the next element else it finds its correct position in the sorted array and moves it to that position. This is done by shifting all the elements, which are larger than the current element, in the sorted array to one position ahead.
 
#   Algorithm
### Input
Array and array size.
### Output
Sorted Array.
### Steps
insertionSort(arr, n)
Loop from i = 1 to n-1.
     Pick element arr[i] and insert it into sorted sequence arr[0…i-1]

# EXAMPLE
[![N|Solid](https://www.testingdocs.com/questions/wp-content/uploads/InsertionSort.png)](https://nodesource.com/products/nsolid)

12, 11, 13, 5, 6
loop for i = 1 (second element of the array) to 4 (last element of the array)
-	i = 1. Since 11 is smaller than 12, move 12 and insert 11 before 12
11, 12, 13, 5, 6
-	i = 2. 13 will remain at its position as all elements in A[0..i-1] are smaller than 13
11, 12, 13, 5, 6
-	i = 3. 5 will move to the beginning and all other elements from 11 to 13 will move one position ahead of their current position.
5, 11, 12, 13, 6
-	i = 4. 6 will move to position after 5, and elements from 11 to 13 will move one position ahead of their current position.
5, 6, 11, 12, 13

# Time Complexity
O(n^2)

# Implementation

 - # [c code]
 - # [coffee code]
 - # [cpp code]
 - # [c# code]
 - # [go code]
 - # [java code]
 - # [javaScript code]
 - # [kotlin code]
 - # [python code]
 - # [ruby code]
 - # [dart code]



[c code]: <http://github.com/jainaman224/Algo_Ds_Notes/blob/master/Insertion_Sort/Insertion_Sort.c>
[coffee code]: <https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Insertion_Sort/Insertion_Sort.coffee>
  [cpp code]: <https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Insertion_Sort/Insertion_Sort.cpp>
   [c# code]: <https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Insertion_Sort/Insertion_Sort.cs>
   [go code]: <https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Insertion_Sort/Insertion_Sort.go>
   [java code]: <https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Insertion_Sort/Insertion_Sort.java>
   [javaScript code]: <https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Insertion_Sort/Insertion_Sort.js>
   [kotlin code]: <https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Insertion_Sort/Insertion_Sort.ky>
   [python code]: <https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Insertion_Sort/Insertion_Sort.py>
   [ruby code]: <https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Insertion_Sort/Insertion_Sort.rb>
   [dart code ]: <https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Insertion_Sort/Insertion_Sort.dart>
   
  
