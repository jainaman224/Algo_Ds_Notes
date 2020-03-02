#include <iostream> 

using namespace std; 
  
// A function which is used to sort the algorithm using gnome sort 
void gnome_sort(int arr[], int n) 
{   
    // 
    int index = 0; 
  
    while (index < n) { 
        // Intially Index is set to Zero then It will be incremented to 1
        if (index == 0) 
            index++; 
        // Checking the values between the array elements
        if (arr[index] >= arr[index - 1]) 
            index++; 
        else { 
            swap(arr[index], arr[index - 1]); 
            index--; 
        } 
    } 
   
} 
  
  
// Sample Test cases to test above function. 
int main() 
{ 
    int arr[] = {3, 2, 1, -5, 7}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    gnome_sort(arr, n); 

    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
  
    return 0; 
} 