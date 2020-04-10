# Introsort 

1. It was invented by David Musser in 1997.
2. It is also known as introspective sort.
3. It is a hybrid sorting algorithm(combines two or more other algorithms that solve the same problem,either choosing one depending upon the data or switching between them over the course of algorithm).
4. It provides both fast average performance and optimal worst performance,thus allowing the performance requirement to become more strict and effective.
5. It combines the good part of three algorithm i.e quick sort, heap sort,insertion sort.

## Pseudocode 

```
procedure sort(A : array):

    let maxdepth = ⌊log(length(A))⌋ × 2
    
    introsort(A, maxdepth)
   
procedure introsort(A, maxdepth):

    n ← length(A)
    
    if n ≤ 1:
    
        return  // base case
        
    else if maxdepth = 0:
    
        heapsort(A)
        
    else:
    
        p ← partition(A)  // assume this function does pivot selection, p is the final position of the pivot

         introsort(A[0:p-1], maxdepth- 1)
        
        introsort(A[p+1:n], maxdepth - 1)
        
The factor 2 in the maximum depth is arbitrary; it can be tuned for practical performance. A[i:j] denotes the array slice of items i to j.
```

### Example

**Input:**
  2,10,24,2,10,11,27,4,2,4,28,16,9,8,28,10,13,24,22,28,0,13,27,13,3,23,18,22,8,8

**Step 1:**
      begin=0, end=29
      depthLimit=8,
       a[pivot]=8
 As th number of elements>16,the pivot element is calculated based on the quicksort algorithm.Using the median-of-3 concept,the pivot element is calculated and the a[pivot]=8.
The method partition() finds the correct position of the a[pivot] and helps in array split-up for further recursion.
Here,the element 8(in comment)lies in the correct position and in the further steps recursion will be carried over for the sub array before and after 8.
 2,2,4,2,4,8,0,3,8,/8/,28,16,9,11,28,10,13,24,22,28,27,13,27,13,24,23,18,22,10,10 

**Step 2:**
   From the previous step,
   begin=0, end=29,
   a[pivot]=8
  The recursion starts for the sub-array a[begin,pivot-1] and a[pivot+1,end]
   2,2,4,2,4,8,0,3,8,  8  ,28,16,9,11,28,10,13,24,22,28,27,13,27,13,27,13,24,23,18,22,10,10
   depthLimit=7,                    depthLimit=7,
   begin=0,end=8                   begin=10,end=29
  number of element<=16          Number of element>16,hence sortDataUtil(10,29) that calculates the pivot and a[partition]=27
 hence insertionSort(0,8)

0,2,2,2,3,4,4,8,8,  8,   16,9,11,10,13,24,22,10,13,27,13,24,23,18,22,10,  27,  28,28,28

**Step 3:**
  From the previous step, depthLimit=6,begin=10, end=29
 The recursion starts fo the sub-array a[begin,partition-1] and a[partition+1,end]

     0,2,2,2,3,4,4,8,8,8,16,9,11,10,13,24,22,10,13,27,13,24,23,18,22,10,27,28,28,28
     
        sorted!                         depthLimit=6                             depthLimit=6
   Hence,no further recursion       begin=10, end=25                                    begin=10, end=25
                                 As the number of elements<16,insertionSort(10,25)      As the number of element<16,insertionSort(27,29)
    
     0,2,2,2,3,4,4,8,8,8,9,10,10,10,11,13,13,13,16,18,22,22,23,24,27,27,28,28,28

       Sorted!                               Sorted!                    Sorted!                        
  hence no further recursion      hence no further recursion                               hence no further recursion
                                       
**Step 4:** 
   output:
       0,2,2,2,3,4,4,8,8,8,9,10,10,11,13,13,13,16,18,22,22,23,24,24,27,27,28,28,28
     In the above example, the depthLimit came until 6, and for bigger datasets the depthLimit might reach 0 for certain sub-array.
     The heapSort is carried out only for those sub-array for sorting them.

Output:
   0,2,2,2,3,4,4,8,8,8,9,10,10,10,11 13,13,13,16,18,22,22,23,24,24,27,27,28 28,28

#### Time Complexity
Average performance O(n log n)
Optimal worst performance O(n log n) 
where, n = number of elements to be sorted.

##### See also
1. https://www.geeksforgeeks.org/introsort-or-introspective-sort/
2. https://en.wikipedia.org/wiki/Introsort


