# COCKTAIL SORT

Cocktail Sort is a variation of Bubble sort. The Bubble sort algorithm always traverses elements from left and moves the largest element to its correct position in first iteration and second largest in second iteration and so on. Cocktail Sort traverses through a given array in both directions alternatively.

## EXAMPLE

Given below is an unsorted array [11,33,88,66,22,44,55,99]. Cocktail Sort take O(n^2) time.

![Cocktail_Sort](https://www.researchgate.net/profile/Ashraf_Maghari/publication/314753240/figure/fig1/AS:669485262454802@1536629133857/cocktail-sort.ppm)

Alternate forward and backward iteration is done, In forward iteration bigger element is moved forward like 99 in first iteration and in backward smaller iteration is moved forward like the element 11 in second iteration and this process continues till a sorted array is obtained.
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

## COMPLEXITY

**Time complexity** - O(n^2), where n is the number of items being sorted.

**Space complexity** -O(1), due to auxillary space only.
