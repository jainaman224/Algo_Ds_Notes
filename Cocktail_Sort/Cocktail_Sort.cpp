#include <stdio.h> 
#include <string.h> 
#include<bits/stdc++.h>
using namespace std; 

void CocktailSort(int a[], int n) 
{ 
    bool swapped = true; 
    int start = 0; 
    int end = n - 1; 
  
    while (swapped) 
    { 
        
        swapped = false; 
  
        for (int i = start; i < end; ++i) 
        { 
            if (a[i] > a[i + 1]) 
            { 
                swap(a[i], a[i + 1]); 
                swapped = true; 
            } 
        } 
  
        if (!swapped) 
            break; 
  
        
        swapped = false; 
 
        --end; 
  
        for (int i = end - 1; i >= start; --i) 
        { 
            if (a[i] > a[i + 1]) 
            { 
                swap(a[i], a[i + 1]); 
                swapped = true; 
            } 
        } 
  
        ++start; 
    } 
} 
  

void printArray(int a[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout<< a[i]; 
 
} 
  

int main() 
{ 
    int a[] = { 6, 1, 4, 2, 5, 4, 2 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    CocktailSort(a, n); 
    cout<<"Sorted array :\n"; 
    printArray(a, n); 
    return 0; 
} 
