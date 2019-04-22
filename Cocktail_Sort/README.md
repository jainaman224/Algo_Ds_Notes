# COCKTAIL SORT
<p>Cocktail Sort is just like Bubble Sort, the only difference is, in Bubble sort list is traversed only in forward direction while in Cocktail
Sort it is traversed both forward and backward alternatively.</p>

## EXAMPLE

Given below is an unsorted array [1,2,6,4,3,7,5,8]. Cocktail Sort take O(n^2) time.

![Cocktail_Sort]
## PSEUDOCODE
<p> We will keep a swap variable to see if the swap has happened or not. If no swap happens then no more processing on the array is required and it comes out of the loop.
During forward iteration we will swap if the selected element is greater than the next element and during the backward iteration we will swap if the selected element is smaller than the next element in iteration.

Pseudocode of the Cocktail Sort algorithm can be expressed as -
```
  procedure cocktailSort(list : array of items)
    
    start = 0
    end = list.count-1;
    swapped = true;
  
    while swapped do:
    
      swapped = false;
    
      for i = start to end do:
        if list[i]>list[i+1] then:
          swap(list[i],list[i+1]);
          swapped = true;
        
      if !swapped then:
        break;
      
      swapped = false;
      end = end - 1;
    
    for i = end - 1 to start-1 do:
      if list[i]>list[i+1] then:
        swap(list[i],list[i+1]);
        swapped = true;
        
    start = start + 1;
```    
