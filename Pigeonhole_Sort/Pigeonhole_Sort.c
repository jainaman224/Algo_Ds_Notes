#include<stdio.h>
#include<stdlib.h>
 
void pigeonholesort(int arr[], int size) 
{ 
   int min = arr[0], max = arr[0]; 
   // Finding min value and max values in the array arr[]
   for (int i = 1; i < size; i++) 
   { 
        if (arr[i] < min) 
            min = arr[i]; 
        if (arr[i] > max) 
            max = arr[i]; 
   } 
   int range;
   range = max - min + 1;
   //Creating the holes
   int holes[range];
   for(int i=0;i<range;i++)
           holes[i]=0;
   //Filling the holes
   for (int j=0; j < size;j++)
          holes[arr[j] - min]++;
 
   // Put the elements back into the array in order.
   // k is the index of sorted array
   int k=0;
   for (int count = 0; count < range; count++)
      while (holes[count]-- > 0)
        {
              arr[k] = count + min;
              k=k+1;
        }
}
int main()
{ 
   int size,i;
   printf("Enter the size of the array ");
   scanf("%d",&size);
   int arr[size];
   printf("Enter the elements ");
   for ( i=0;i<size;i++)
       scanf("%d",&arr[i]) ;
   
   pigeonholesort(arr, size);
   
   printf("Sorted array :\n");
   for ( i = 0; i < size; i++)
         printf("%d ",arr[i]);
                        
   return 0;
}

//INPUT:Enter the size of the array 5
//Enter the elements -10
//5
//0
//9
//8
//OUTPUT:Sorted array: 
//-10 0 5 8 9 
