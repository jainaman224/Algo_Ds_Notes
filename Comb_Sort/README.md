### Comb Sort

![Comb_sort_demo](https://user-images.githubusercontent.com/28682701/56884536-c1704380-6a87-11e9-9cf9-fb8cba477a53.gif)

Comb sort is an improvement of the bubble sort algorithm.In the comb sort,the items are sorted in a specific gap. 
After completing each phase,the gap decreased.

With compared to the bubble sort this sorting algorithm remove the worst-case scenario and improved on the time complexity of Bubble sort.



**Example**

Let's arrange the numbers in ascending order using Comb sort.

Unsorted List

![Screenshot (35)](https://user-images.githubusercontent.com/28682701/56882906-b666e480-6a82-11e9-94f4-b3446f13ebf6.png)

- Iteration 1

Gap = 8 (number of elements in the array/ 1.3)

![Screenshot (36)](https://user-images.githubusercontent.com/28682701/56883448-56713d80-6a84-11e9-97ad-32337c030b64.png)


The distance of 8 from the first element 5 to the next element, leads to the element of 2.These numbers are not in the right order,so they have to swap.Then the second element compared with the last element,they are not in the order so again swap is required.


- Iteration 2

New Gap Value = 8/1.3 = 6

![Screenshot (38)](https://user-images.githubusercontent.com/28682701/56883662-fcbd4300-6a84-11e9-9a56-74f90a468644.png)


- Iteration 3

New Gap Value = 6/1.3 = 4

![Screenshot (41)](https://user-images.githubusercontent.com/28682701/56883774-4efe6400-6a85-11e9-9287-b78a046c466b.png)



- Iteration 4


New Gap Value = 4/1.3 = 3

![Screenshot (42)](https://user-images.githubusercontent.com/28682701/56883861-8f5de200-6a85-11e9-8ffe-f2b730804a00.png)


- Iteration 5

New Gap value = 3/1.3 = 2

![Screenshot (43)](https://user-images.githubusercontent.com/28682701/56883958-de0b7c00-6a85-11e9-8d56-2497dbe4b89c.png)

- Iteration 6

New Gap Value = 2/1.3 = 1

![Screenshot (44)](https://user-images.githubusercontent.com/28682701/56884136-76a1fc00-6a86-11e9-9c5a-176c1af7f025.png)

***Algorithm***

1. Calculate the Gap value.
2. Iterate over dataset and compare each element with the gap element then move to swapping.  
3. if the gap value has reached one then terminating the loop.

***Pseudocode***

function comboSort( array : list of sortable items)

    length = length(array)
    gap = length / 1.3
    
    loop while(gap >= 1)
    
        for i = 0 to i <= n-1 do 
            
            if ( i + gap > n-1 )
                continue
            end if
            
            if ( array[i] > array[i+gap] )
                swap( array, i , i+gap )
            end if
            
        end for
        
       gap /= 1.3
    end loop
 
 end function
 
 function swap(a : list of sortable items,input x, input y)
 
    temp = a[x]
    a[x] = a[y]
    a[y] = temp
    
 end function
 
            

***Time complexity***

  Best Case complexity = O(n)<br />
  Worst case complexity = O(n*n)
  
 
