//C++ code for Kadane's algorithm i.e. Largest Sum Contiguous Subarray
#include<iostream> 
using namespace std; 

int maxSubArraySum(int array[], int size) 
{ 
    int maximum = array[0];                 //assuming first element of the array as the maximum sum
    int pres_max = array[0];                // the maximum sum which hold the value presently

    for (int i = 1; i < size; i++) 
    { 
	    	pres_max = max(array[i], pres_max + array[i]); 
	    	maximum = max(maximum, pres_max); 
    } 
    return maximum; 
} 

/* Main function */
int main() 
{ 
    int a_size;                             // size of the array
    cin>>a_size;                            // taking the size of the array from the user
    int array[a_size]; 
    for(int i=0; i<a_size;i++){             //for loop for taking the input value of the elements of the array
        cin>>array[i];
    }
    int n = sizeof(array)/sizeof(array[0]); 
    int max_sum = maxSubArraySum(array, n); // the return value of the function stored in max_sum
    cout << "Maximum sum of contiguous subarray is  " << max_sum; 
return 0; 
} 
