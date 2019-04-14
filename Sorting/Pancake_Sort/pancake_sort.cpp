
#include <stdlib.h> 
#include <iostream>

using namespace std; 
void reverse(int a[], int i) ;
int max(int a[], int n);
void print(int a[], int n) ;
int pancakesort(int *a, int size);
  
//function to perform reversing or flipping of array
void reverse(int a[], int i) 
{ 
    int temp, s1 = 0; 
    while (s1 < i) 
    { 
        temp = a[s1]; 
        a[s1] = a[i]; 
        a[i] = temp; 
        s1++; 
        i--; 
    } 
} 
  
// Returns index of the  max element in the given portion of array
 
int max(int a[], int n) 
{ 
int j, i; 
for (j = 0, i = 0; i < n; ++i) 
    if (a[i] > a[j]) 
            j = i; 
return j; 
} 
  
//pancake sort function 
int pancakesort(int *a, int size) 
{ 
    int i,pos;
    for ( i = size; i > 1; --i) 
    { 
       
         pos = max(a, i);//pos holds the index of element in the array 
  
        
        if (pos != i-1) //to replace max element at the end of array if it's not at the end
        { 
            
            reverse(a, pos); 
  
            //reversing current array to move maximum number to end
            reverse(a, i-1); 
        } 
    } 
} 
  
//  function to print the sorted array 
 
void print(int a[], int n) 
{ 
    for (int i = 0; i < n; ++i) 
         cout<<a[i]<<"  "; 
} 
  

int main() 
{ 
	int size,i;
	cin>>size;
    int a[size] ;
	for(i=0;i<size;i++)
		cin>>a[i];
    
    pancakesort(a, size);
    print(a, size);
  
    return 0; 
} 
