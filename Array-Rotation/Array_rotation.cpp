//Program to rotate array Arr[] of size n by d Elements
#include<iostream>
using namespace std;

void leftRotate(int arr[], int n) 
{ 
    int temp = arr[0], i; 
    for (i = 0; i < n - 1; i++) 
        arr[i] = arr[i + 1]; 
  
    arr[i] = temp; 
} 
  
void Rotate(int arr[], int d, int n) 
{ 
    for (int i = 0; i < d; i++) 
        leftRotate(arr, n); 

    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";    
} 

int main() 
{ 
    int arr[] = { 1, 2, 3, 4, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    Rotate(arr, 2, n);
    return 0; 
} 
/*
Input array: {1, 2, 3, 4, 5}
Expected Output
3 4 5 1 2 
*/
