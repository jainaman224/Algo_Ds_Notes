# Shell Sort

![Sorting_shellsort_anim](https://user-images.githubusercontent.com/28682701/58122889-39193480-7c28-11e9-83b1-081f2396e129.gif)

Shell Sort is a generalization of a insertion sort.  
In this sorting algorithm we compare elements that are distant apart rather than adjacent. We started by comparing elements that are at
a certain distance apart. Hence if there are **N** elements then we start with a value **gap < N**.  
In each pass we keep reducing the value of gap till we reach the last pass when gap is 1. In the last pass shell sort is like a insertion sort. 

## Example 

Let's arrange the numbers in ascending order using Shell Sort.

- Unsorted List

![Screenshot (137)](https://user-images.githubusercontent.com/28682701/58199213-9e832900-7ced-11e9-8ba5-b202c032e571.png)

- Iteration 1

Gap = 4 (number of elements in the array/ 2)<br />
We compare values in each sub-list and swap them if it is not in the correct order.<br />
![Screenshot (131)](https://user-images.githubusercontent.com/28682701/58199440-16e9ea00-7cee-11e9-8364-9d13f8dfc2bd.png)

- Iteration 2

New Gap Value = 4/2 = 2<br />
![Screenshot (132)](https://user-images.githubusercontent.com/28682701/58199710-bdce8600-7cee-11e9-9644-27ded783d201.png)

- Iteration 3

New Gap Value = 2/2 = 1<br />
Finally, we sort the rest of the array using interval of value 1. Shell sort uses insertion sort to sort the array.<br />
![Screenshot (134)](https://user-images.githubusercontent.com/28682701/58199919-30d7fc80-7cef-11e9-878e-8aa87e17a7c5.png)

## Algorithm

Step 1 − Initialize the value of h(Gap value)<br />
Step 2 − Divide the list into smaller sub-list of equal interval h <br />
Step 3 − Sort these sub-lists using insertion sort <br />
Step 3 − Repeat until complete list is sorted <br />

## Pseudocode
```
function shellSort( array : list of sortable items)

    length = length(array)
    gap = length / 2

    loop while(gap >= 1)
  
    for i = 0 to i <= length-1 do 
        if ( i + gap > length-1 )
            continue
        end if
        
        if ( array[i] > array[i+gap] )
            swap( array, i , i+gap )
        end if
    end for
    
    gap /= 2
    end loop
end function

function swap(a : list of sortable items,input x, input y)

    temp = a[x]
    a[x] = a[y]
    a[y] = temp
end function
```
## Time complexity

Worst complexity: Depends on gap sequence<br />
Average complexity: n*log(n)^2 or n^(3/2)<br />
Best complexity: n
