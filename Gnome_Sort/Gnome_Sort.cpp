#include <iostream> 

using namespace std; 
  
// A function that is used to sort the algorithm using gnome sort 
void gnome_sort(int arr[], int n) {   

    // Implementation Logic Begins here
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
  
// Main function. 
int main() 
{ 
    
    int n;
    cout << "Enter the size of an Array: ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    gnome_sort(arr, n); 

    for(int i = 0; i < n; i++){
        cout << arr[i] <<endl;
    }
  
    return 0; 
} 

/*
    Sample Driver Code:
    INPUT: 
    Enter the size of an Array: 5
    3
    2
    1
    -5
    7

    OUTPUT:
    -5
    1
    2
    3
    7

*/
