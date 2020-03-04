#Array Rotation
A function `rotate(arr[], k, n)` that rotates `arr[]` of size `n` by `k` elements either to the left or the right.

For example:
For the array given below, `n=7` 
![Array Rotation](https://media.geeksforgeeks.org/wp-content/uploads/simplearray.png)
For `k=2`, array after left rotation will be:
![Array Rotation](https://media.geeksforgeeks.org/wp-content/uploads/arrayRotation.png)

This can be achieved by various methods, some of which are listed below.

##I. Using `temp` array

###Algorithm

1. Take an array `arr[]` of length `n` and an integer `k<=n` as input.
2. If rotating to left:
      i.   Store the first `k` elements in a temporary array `temp[]`.
      ii.  Shift the remaining `n-k` elements to the left/forward.
      iii. Copy elements from `temp[]`as the last `k` elements of `arr`.
   If rotating to right:
      i.   Store the last `k` elements in a temporary array `temp[]`.
      ii.  Shift the remaining `n-k` elements to the left/forward.
      iii. Copy elements from `temp[]`as the first `k` elements of `arr`.
      
###Psuedocode

```
procedure left-rotate(arr[]: array of items, n: length of array, k: number of elements to rotate by)
  
  //initialising temp array
  temp[];
  
  //adding first k elements to temp[] array
  for i=0 to k:
    temp[i]=arr[i]
  
  //moving remaining elements to the left by k
  for i=k to n:
    arr[i-k]=arr[i]
    
  //copying the elements from temp[] to last k elements of arr[]    
  for i=0 to k:
    arr[n-1-i]=temp[i]

procedure right-rotate(arr[]: array of items, n: length of array, k: number of elements to rotate by)
  //initialising temp array
  temp[];
  
  //adding last k elements to temp[] array
  for i=0 to k:
    temp[i]=arr[n-1-i]
  
  //moving remaining elements to the right by k
  for i=0 to n-k:
    arr[i+k]=arr[i]
  
  //copying the elements from temp[] to first k elements of arr[]    
  for i=0 to k:
    arr[i]=temp[i]    
 ```
 
 ###Complexity
 **Time Complexity**  - `0(n)` where `n` is number of elemnets in array
 **Space Complexity** - `O(k)` where `k` is number of elements to rotate by
 
 ##II. Rotate one by one
 
 ###Algorithm
 
 1. Take an array `arr[]` of length `n` and an integer `k<=n` as input.
 2. If rotating to left:
      Repeat `k` times:
        Store first element `arr[0]` in a temporary variable `temp`
        Shift all elements of array to the left by one
        Store temp in last element of array
    If rotating to right:
      Repeat `k` times:
        Store last element `arr[n-1]` in a temporary variable `temp`
        Shift all elements of array to the right by one
        Store temp in first element of array

###Psuedocode

```
procedure left-rotate(arr[]: array of items, n: length of array, k: number of elements to rotate by)
  //Repeat k times
  for i=0 to k:
    //Store first element in temporary variable
    temp=arr[0]
    //Shift all elements to left by one
    for i=1 to n:
      arr[i-1]=arr[i]
    //Store temp into last element of array
    arr[n-1]=temp
    
procedure right-rotate(arr[]: array of items, n: length of array, k: number of elements to rotate by)
  for i=0 to k:
    //Store last element in temporary variable
    temp=arr[n-1]
    //Shift all elements to right by one
    for i=0 to n-1:
      arr[i+1]=arr[i]
    //Store temp into first element of array
    arr[0]=temp
```   

###Complexity
 **Time Complexity**  - `0(n*k)` where `n` is number of elemnets in array and `k` is number of elements to rotate by
 **Space Complexity** - `O(1)` 
      

    
