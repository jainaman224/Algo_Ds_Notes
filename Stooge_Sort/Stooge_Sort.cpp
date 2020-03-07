// C++ code for stooge sort 
#include <iostream> 
using namespace std; 


void stoogesort(int array[], int low, int high) 
{ 
    if (low >= high) 
        return; 

    if (array[low] > array[high]) 
        swap(array[low], array[high]); 

    // If there are two or more elements in array
    if (high - low + 1 > 2) { 
        int t = (high - low + 1) / 3; 

        // Recursion sort for the first two-third elements 
        stoogesort(array, low, high - t); 

        // Recursion sort for the last two-third elements 
        stoogesort(array, low + t, high); 

        // Recursion sort for the first two-third elements 
        stoogesort(array, low, high - t); 
    } 
} 

int main() 
{ 
    int array[50],n,i;
    cout<<"How many numbers do you want to sort : ";
    cin>> n;
    cout << "\nEnter the numbers : ";
    for (i = 0; i < n; i++)
        cin>>array[i] ;
    
    // Call Stooge Sort
    stoogesort(array, 0, n - 1); 

    cout<<"\nThe sorted array is : ";
    // Print the sorted arrayay 
    for (i = 0; i < n; i++) 
        cout<< array[i]<< "  "; 

    return 0;
} 

//SAMPLE INPUT AND OUTPUT

/*SAMPLE-1

How many numbers do you want to sort : 8
Enter the numbers : 12 54 23 41 31 4 1 11
The sorted array is : 1  4  11  12  23  31  41  54  

SAMPLE-2

How many numbers do you want to sort : 8
Enter the numbers : 9 7 5 6 4 11 2  8
The sorted array is : 2  4  5  6  7  8  9  11

*/
