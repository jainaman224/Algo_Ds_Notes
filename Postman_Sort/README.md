# Postman Sort

Postman sort works by sorting the integers of an array from their most significant digits to their least 
significant digits. In the Postman sort the integer having most significant digits and the number of
elements in that integer is determined, the length of the longest integer is stored. All the elements in the 
array are divided by a particular base. The elements of the array are sorted on the basis of the most significant
digit to the least significant digit i.e. from leftmost to rightmost digit.

## Example

Let's arrange the numbers in ascending order using postman sort.

- Unsorted List

The input array contains 7 elements which are {25, 432, 788, 130, 23, 121, 564}

- Iteration 1

The elements of the array being sorted on the basis of the most significant digit, *it becomes {25, 23, 130, 121, 432, 564, 788}*

- Iteration 2

The elements of the array being sorted on the basis of the second most significant digit, *it becomes {25, 23, 121, 130, 432, 564, 788}*

- Iteration 3

At last those elements of the array are compared which have same value of significant digit and if they are not in correct 
order, the elements gets swapped and are arranged in desired order. The array after getting sorted *becomes
{23, 25, 121, 130, 432, 564, 788}*

*In this way the elements of the array are sorted on the basis of their significant digits.*

## Algorithm

1.Compare the leftmost digit of the elements of the array then the next to it and so on.<br/>

2.If the elements are not in correct order swap them according to their significant digit.<br/>

3.The function recurses which compares the elements having same value of significant digit and arranges the elements in correct order.<br/>

## Pseudocode
```
declare temp, max, count, maxdigits = 0, c = 0
declare t1, t ,i, j
Initialise n = 1
Input the number of elements in the array and store their values in arr[], arr1[]
for(i = 0; i < count; i++)
    t = arr[i]
    while(t > 0)
        c++
        t = t/10
    if(maxdigits < c)
        maxdigits = c
    c = 0
    
for(i = 0; i < maxdigits; i++)
    n = n * 10

for(i = 0; i < count; i++)
    max = arr[i] / n
    t = i
    for(j = i + 1; j < count; j++)
        if(max > (arr[j] / n))
            max = arr[j] / n
            t = j       
    temp = arr1[t]
    arr1[t] = arr1[i]
    arr1[i] = temp
    temp = arr[t]
    arr[t] = arr[i]
    arr[i] = temp

while(n >= 1)
    for(i = 0; i < count;)
        t1 = arr[i] / n
        for(j = i + 1; t1 == (arr[j]/n); j++);
            arrange(i, j)
        i = j
    n = n / 10
              
void arrange(int k, int n)
    for(i = k; i < n - 1; i++)
        for(j = i + 1; j < n; j++)
            if(arr1[i] > arr[j])
                temp = arr1[i]
                arr1[i] = arr1[j]
                arr1[j] = temp
                temp = arr[i] % 10
                arr[i] = arr[j] % 10
                arr[j] = temp
            
```

## Time Complexity

    Best Case complexity =  d * (n + k) 
    Worst case complexity =  n * k / d
    Space complexity = n + 2^d
where
>d = number of digits<br/>
>n = number of keys<br/>
>k = size of bucket
      
## Implementation
* [C# Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Postman_Sort/Postman_Sort.cs)


