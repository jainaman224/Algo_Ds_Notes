//Cocktail sort is a variation of bubble sort that is both a stable sorting
//algorithm and a comparison sort. The algorithm differs from a bubble sort in 
//that it sorts in both directions on each pass through the list. 
#include <stdio.h>  
   
int main()  
{  
    int n;
    printf("Enter the number of elements ");
    scanf("%d",&n);
    int a[n];
    int i;
    printf("Enter the elements ");
    for (i = 0 ; i < n ; i++ )  
        scanf("%d",&a[i]);
    int temp;
    int swapped = 1;  
    int begin = 0;  
    int end = n - 1;  
   
    while (swapped)
    {  
        swapped = 0; 
        // iterate through every element from left to right
        for (i = begin ; i < end ; ++i) 
        {    
            // Move the bigger element to the right most position as in bubble sort
            if (a[i] > a[i + 1])
            {  
                temp = a[i];  
                a[i] = a[i+1];  
                a[i+1] = temp;                  
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
            if (a[i] > a[i + 1])   
            {
                temp = a[i];  
                a[i] = a[i+1];  
                a[i+1] = temp;  
                swapped = 1;  
            }  
        }  
        ++begin;  
    } 
    
    printf("Sorted array :\n");  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
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
