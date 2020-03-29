# BINARY INSERTION SORT

Binary Insertion sort is a special type up of Insertion sort which uses binary search algorithm to find out the correct position of the inserted element in the array.

Binary search is searching technique that works by finding the middle of the array for finding the element.

Insertion sort is sorting technique that works by finding the correct position of the element in the array and then inserting it into its correct position.

Binary Insertion Sort uses binary search to find the proper location to insert the selected item at each iteration.
In normal insertion sort, it takes O(n) comparisons(at nth iteration) in worst case. We can reduce it to O(log n) by using binary search.

## PSEUDOCODE

```
binary_search(arr, val, start, end) 
  {  
    if start == end 
        if arr[start] > val 
            return start 
        else 
            return start+1
            
    if start > end: 
        return start 
  
    mid = (start+end)/2
    
    if arr[mid] < val 
        return binary_search(arr, val, mid+1, end) 
        
    elif arr[mid] > val 
        return binary_search(arr, val, start, mid-1) 
    else 
        return mid 
  }
  
  
 insertion_sort(arr) 
  {
    for i=1 to len(arr) 
        val = arr[i] 
        j = binary_search(arr, val, 0, i-1) 
        arr = arr[0->j] + [val] + arr[j->i] + arr[i+1->n-1] 
    return arr 
  }
```

### Example
           {9,7,6,15,17,5,10,11}
   In normal insertion, sort it takes O(i) (at ith iteration) in worst case. we can reduce it to O(logi) by using binary search.
   ![Binary Insertion Sort](https://www.wikitechy.com/technology/wp-content/uploads/2017/10/insertion_sort-recursion.png)


## TIME COMPLEXITY

|ALGORITHM            |              BEST-CASE   |  AVG-CASE |     WORST-CASE|
|---------------------|--------------------------|-----------|---------------|
|INSERTION SORT  |                O(N)      |    O(N^2) |        O(N^2) |    
|BINARY INSERTION SORT|       O(N log N)         |     O(N^2)|        O(N^2) |     


## ADVANTAGE of BINARY INSERTION SORT over INSERTION SORT

  The binary insertion sort does fewer array element comparisons than insertion sort.

  The number of comparisons required by the normal insertion sort is O(N^2) in the worst case as well as on average. Therefore on average, the binary insertion sort uses fewer comparisons than normal insertion sort.
