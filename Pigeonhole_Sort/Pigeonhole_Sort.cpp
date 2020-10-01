//The pigeonhole algorithm works as follows:
//1.Given an array of values to be sorted, set up an auxiliary array of initially empty
//"holes," one pigeonhole for each key through the range of the original array.
//2.Going over the original array, put each value into the pigeonhole corresponding
//to its key, such that each pigeonhole eventually contains a list of all values with that key.
//3.Iterate over the pigeonhole array in order, and put elements from non-empty 
//pigeonholes back into the original array.

#include <stdio.h> 
#include <stdlib.h>
#include <bits/stdc++.h> 
using namespace std; 

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
   cout<<"Enter the size of the array ";
   cin>>size;
   int arr[size];
   cout<<"Enter the elements ";
   for ( i=0;i<size;i++)
       cin>>arr[i] ;
  
   pigeonholesort(arr,size); 
  
   cout<<"Sorted array: \n"; 
   for (i = 0; i < size; i++) 
        cout<<arr[i]<<" "; 
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
