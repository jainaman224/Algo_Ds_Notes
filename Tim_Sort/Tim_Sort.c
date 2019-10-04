//GSSoC
//TimSort

#include<stdio.h>  

int minimum(int a, int b)  
{  
    if(a<b)  
        return a;   
    else   
        return b;   
}  
 
//MERGE SORT FUNCTION :   
void merge(int array[], int left, int mid, int right)  
{  
    int leftLength = mid - left + 1, rightLength = right - mid;  
    int Left[leftLength], Right[rightLength];  
    int i,j,k;  
    for (i = 0; i < leftLength; i++)  
        Left[i] = array[left + i];  
    for (i = 0; i < rightLength; i++)  
        Right[i] = array[mid + 1 + i];  
       
    i = 0;  
    j = 0;  
    k = left;  
       
    while (i < leftLength && j < rightLength)  
    {  
        if (Left[i] <= Right[j])  
        {  
            array[k] = Left[i];  
            i++;  
        }  
        else  
        {  
            array[k] = Right[j];  
            j++;  
        }  
        k++;  
    }  
    while (i < leftLength)  
    {  
        array[k] = Left[i];  
        k++;  
        i++;  
    }  
       
    while (j < rightLength)  
    {  
        array[k] = Right[j];  
        k++;  
        j++;  
    }  
}  

// INSERTION SORT FUNCTION :
void insertionSort(int array[], int left, int right)  
{  
    int temp, i, j;   
    for (i = left + 1; i <= right; i++)  
    {  
        temp = array[i];  
        j = i - 1;  
        while (array[j] > temp && j >= left)  
        {  
            array[j+1] = array[j];  
            j--;  
        }  
        array[j+1] = temp;  
    }  
} 
      
int main()  
{  
    int n;
    printf("Enter number of elements in your array: ");
    scanf("%d", &n);    
    int array[n]; 
    printf("Enter your array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    printf("Unsorted Array : \n");  
    for (int i = 0; i < n; i++)  
        printf("%d  ", array[i]);  
    printf("\n");  
       

    int size,left,mid,right,Limit=32;  
    for (int i = 0; i < n; i+=Limit)  
        insertionSort(array, i, minimum((i+31), (n-1)));  
    for (size = Limit; size < n; size = 2*size)  
    {  
        for (left = 0; left < n; left += 2*size)  
        {  
            mid = left + size - 1;  
            right = minimum((left + 2*size - 1), (n-1));  
       
            merge(array, left, mid, right);  
        }  
    } 

    printf("Sorted Array : \n");  
    for (int i = 0; i < n; i++)  
        printf("%d  ", array[i]);  
    printf("\n");  
    return 0;  
}  

/*
INPUT:
Enter number of elements in your array: 5
Enter your array: 50
39
89
10
8
OUTPUT
----------------
Unsorted Array :
50 39 89 10 8 
Sorted Array :
8 10 39 50 89
----------------
*/

// Happy Coding! 
 

