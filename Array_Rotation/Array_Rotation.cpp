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
    int n, r;
    cout << "Enter number of elements in your array: ";
    cin >> n;
    int arr[n];
    cout << "Enter your array: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the value for rotation cycle: ";
	cin >> r;
    
    Rotate(arr, r, n);
    return 0; 
} 

/*
INPUT:
Enter number of elements in your array: 5
Enter your array: 1
2
3
4
5
Enter the value for rotation cycle: 2
OUTPUT:
3 4 5 1 2
*/
