# COCKTAIL SORT

Cocktail Sort is a variation of Bubble sort. The Bubble sort algorithm always traverses elements from left and moves the largest element to its correct position in first iteration and second largest in second iteration and so on. Cocktail Sort traverses through a given array in both directions alternatively.

## EXAMPLE

Given below is an unsorted array [1,2,6,4,3,7,5,8]. Cocktail Sort take O(n^2) time.

![Cocktail_Sort](https://github.com/archi14/Algo_Ds_Notes/blob/Cocktail_Sort/Cocktail_Sort/gif1.gif)

1 and 2 have element bigger than them next to them hence starting with six and swapping positions with the elements smaller than 6 until found an element bigger than 6, then taking that and doing the same procedure like with 7 in first forward iteration in above gif.

![Cocktail_Sort](https://github.com/archi14/Algo_Ds_Notes/blob/Cocktail_Sort/Cocktail_Sort/gif2.gif)

Doing backward iteration and swapping 5 with elements bigger than it, if a smaller element is found then we take that and do the same for it also.

![Cocktail_Sort](https://github.com/archi14/Algo_Ds_Notes/blob/Cocktail_Sort/Cocktail_Sort/gif3.gif)

Continues till a sorted array is obtained.

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
