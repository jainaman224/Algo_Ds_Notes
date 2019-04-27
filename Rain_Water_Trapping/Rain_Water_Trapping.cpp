//Rain_Water_Trapping
#include <bits/stdc++.h> 

using namespace std; 
  
int Find_Water(int a[], int size) 
{ 
    // left[i] is for height of tallest bar to the left of it including itself    
    int left[size]; 
  
    // Right [i] contains height of tallest bar to the right of it including itself
    int right[size]; 
  
    // Initializing result 
    int water_volume = 0; 
  
    left[0] = a[0]; 
    for (int i = 1; i < size; i++) 
       left[i] = max(left[i - 1], a[i]); 
  
    right[size - 1] = a[size - 1]; 
    for (int i = size - 2; i >= 0; i--) 
       right[i] = max(right[i + 1], a[i]); 
  
    // Calculating the amount of accumulated water 
    for (int i = 0; i < size; i++) 
       water_volume += min(left[i], right[i]) - a[i]; 
  
    return water_volume; 
} 
  
// Driver program 
int main() 
{ 
    int n, i;
    cin >> n;  // taking input for the size of array
    int a[n];
    for (i = 0; i < n; i++)
    	cin >> a[i];  // input of array or height of Tower
    cout << "The maximum water trapped is " << Find_Water(a, n); 
    return 0; 
}
// Input:
// 12
// 0 1 0 2 1 0 1 3 2 1 2 1
// Output:
// The maximum water trapped is 6
