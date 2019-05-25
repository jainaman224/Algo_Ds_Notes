# Shaker Sort

![Sorting_shaker_sort_anim](https://user-images.githubusercontent.com/28682701/57974596-640d4980-79d8-11e9-80e4-c5172de5f421.gif)

Shaker Sort also known as bidirectional bubble sort, cocktail sort, ripple sort, shuffle sort, or shuttle sort.Shaker Sort is an exchange sort 
similar to Bubble Sort except items are compared in both directions.This algorithm provides marginal performance improvements over Bubble Sort.

## Example

Let's arrange the numbers in ascending order using Shaker Sort.

### Unsorted List

![Screenshot (80)](https://user-images.githubusercontent.com/28682701/57974882-4c848f80-79dd-11e9-83c5-2a226f17afae.png)

### First Forward Pass

Shaker Sort starts with very first two elements, comparing them to check which one is greater.

In this case, value 9 is greater than 8 so two values must be swapped.
![Screenshot (83)](https://user-images.githubusercontent.com/28682701/57974934-14ca1780-79de-11e9-8a92-70f59d598a84.png) 

We find that 9 is greater than 6 and these two values must be swapped.
![Screenshot (85)](https://user-images.githubusercontent.com/28682701/57975005-3972bf00-79df-11e9-84e6-a923c38671a4.png)

![Screenshot (95)](https://user-images.githubusercontent.com/28682701/57975050-2ca29b00-79e0-11e9-9b42-d9e0f074016a.png)

![Screenshot (96)](https://user-images.githubusercontent.com/28682701/57975065-6e334600-79e0-11e9-8424-9ae6fbbe31fa.png)

### First Backward Pass

In Backward Pass it starts with last elements, comparing them to check which one is lesser.<br />

In this case, value 2 is lesser than 4, so it is already in sorted locations. Next, we compare 2 with 6.
![Screenshot (97)](https://user-images.githubusercontent.com/28682701/57975127-6031f500-79e1-11e9-9b34-440e6f5ae03c.png)

We find that 2 is smaller than 6 and these two values must be swapped.
![Screenshot (96)](https://user-images.githubusercontent.com/28682701/57975177-1c8bbb00-79e2-11e9-8c3d-f4f9e3a4b320.png)

![Screenshot (98)](https://user-images.githubusercontent.com/28682701/57975198-59f04880-79e2-11e9-8ac2-4a98ee1d0be8.png)

### Second Forward Pass

![Screenshot (99)](https://user-images.githubusercontent.com/28682701/57975227-a89de280-79e2-11e9-80f4-61f0934a00e7.png)

![Screenshot (100)](https://user-images.githubusercontent.com/28682701/57975240-d420cd00-79e2-11e9-8fdb-5673ae7cf510.png)

### Second Backward Pass

![Screenshot (101)](https://user-images.githubusercontent.com/28682701/57975264-2eba2900-79e3-11e9-8e6a-bf079b6e4241.png)

### Sorted List

![Screenshot (102)](https://user-images.githubusercontent.com/28682701/57975293-9ff9dc00-79e3-11e9-849f-109f7cb1957c.png)

## Algorithm

Each iteration of the algorithm is broken up into 2 stages: <br />
1. In the first stage loops through the array from left to right. During the loop, adjacent items are compared and 
if value on the left is greater than the value on the right, then values are swapped. <br />
2. In the second stage loops through the array from right to left. During the loop, adjacent items are compared and 
if value on the right is lesser than the value on the left, then values are swapped.

## Pseudocode
```
function CocktailSort(int a[], int n)
 
    bool  swapped = true 
    int start = 0
    int end = n - 1
  
    while (swapped)
        swapped = false 
    
        for each i in 0 to end - 1 do:
            if (a[i] > a[i + 1]) 
                swap(a[i], a[i + 1]) 
                swapped = true 
            end if
        end for
    
        if (!swapped) 
            break
    
        swapped = false
    
        --end
    
        for each i in end - 1 to start do:
            if (a[i] > a[i + 1]) 
                swap(a[i], a[i + 1]) 
                swapped = true
            end if
        end for
     
        ++ start

    end while 

end function
```

## Time complexity

Best Case complexity = O(n)<br />
Worst case complexity = O(n*n)
