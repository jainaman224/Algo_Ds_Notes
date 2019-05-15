### Circle Sort 

Circle sort can be done by drawing concentric circle on an array of integers. In the Circle sort the first element compared with the last element and the second element compared with the second last element and so on. If the elements are found in the wrong order, then they are swapped. This process goes on a recursively in which the  array is divided into sub-arrays and repeat the above process until we get pairs of sorted elements. 

 **Example**

Let's arrange the numbers in ascending order using circle sort.

-Unsorted List

![Screenshot (56)](https://user-images.githubusercontent.com/28682701/57585928-260db280-750c-11e9-84e7-dd6e9f5784eb.png)

-Iteration 1

 compare, swap and divide the array

![Screenshot (51)](https://user-images.githubusercontent.com/28682701/57585795-a3d0be80-750a-11e9-8db5-8369d9678538.png)

-Iteration 2

![Screenshot (53)](https://user-images.githubusercontent.com/28682701/57585844-28234180-750b-11e9-9835-e7541dc10d9e.png)

-Iteration 3

![Screenshot (55)](https://user-images.githubusercontent.com/28682701/57585917-024a6c80-750c-11e9-87f2-22f97c2d377d.png)

-Iteration 4

![Screenshot (54)](https://user-images.githubusercontent.com/28682701/57585886-a2ec5c80-750b-11e9-8b47-53a60440b2dc.png)

**Algorithm** 

1.Compare the first element with the last element and second element with the second last element and so on.<br />
2.If the element are not in the correct order swap.<br />
3.Split the array in two parts and recurse until there is only one single element in the array.

**Pseudocode**

> function boolean circleSort(a: array of items, int low, int high)<br />
>  
>   boolean swap = false <br />
>   
>   int l = low, h = high<br />
>   
>   while(l<h)<br />
>     if a[l] > a[h]<br />
>       swap ( a[l], a[h] )<br />
>       swap = true<br />
>       <br />
>    end if<br />
>    
>    l++<br />
>    h--<br />
>    
>   end while<br />
>   
>   if l == hi<br />
>     if( a[l] > a[h+1] )<br />
>       swap ( a[l], a[h+1] )<br />
>       swap=true<br />
>     end if <br />
>     
>   int mid = (high-low)/2<br />
>   bool firstArray=circleSort(a, low, low+mid)<br />
>   bool secondArray=circleSort(a, low+mid+1, high)<br />
>   
>   return swap || firstArray || secondArray<br />
>   
>  end function
>  
**Time complexity**

Best Case complexity =  O(n log n)<br />
Worst case complexity =  O(n log n log n)
