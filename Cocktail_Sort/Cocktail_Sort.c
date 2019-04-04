//Cocktail sort is a variation of bubble sort that is both a stable sorting
//algorithm and a comparison sort. The algorithm differs from a bubble sort in 
//that it sorts in both directions on each pass through the list. 
#include <stdio.h>

void swap (int *a, int *b) //swapping function
{ 
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}   
   
int main()  
{  
    int num;
    printf("Enter the number of elements ");
    scanf("%d",&num);
    int arr[num];
    int i;
    printf("Enter the elements ");
    for (i = 0 ; i < num ; i++ )  
        scanf("%d",&arr[i]);
    
    int swapped = 1;  
    int begin = 0;  
    int end = num - 1;  
   
    while (swapped)
    {  
        swapped = 0; 
        // iterate through every element from left to right
        for (i = begin ; i < end ; ++i) 
        {    
            // Move the bigger element to the right most position as in bubble sort
            if (arr[i] > arr[i + 1])
            {  
                swap (&arr[i],&arr[i+1]);                  
                swapped = 1;  
            }  
        } 
        // if nothing moved, then array is sorted. 
        if (!swapped)  
            break;  
        swapped = 0; 
        // moving the smaller elements to left part of the array which is modification over bubble sort
        for (i = end - 1; i >= begin; --i)
        {  
            if (arr[i] > arr[i + 1])   
            {
                swap (&arr[i],&arr[i+1]); 
                swapped = 1;  
            }  
        }  
        ++begin;  
    } 
    
    printf("Sorted array :\n");  
    for (i = 0; i < num; i++)  
        printf("%d ", arr[i]);  
    printf("\n");  
    return 0;  
}  
/*Enter the number of elements 5
Enter the elements 5
4
3
2
1
Sorted array :
1 2 3 4 5 */
