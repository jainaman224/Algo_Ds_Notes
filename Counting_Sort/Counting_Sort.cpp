// C++ implementation of Counting Sort
#include <iostream>

using namespace std;

// Function that sort the given input
void counting_sort(int input[], int n)
{

    int output[n]; // The output will have sorted input array
    int max = input[0];
    int min = input[0];

    for(int i = 1; i < n; i++)
    {
        if(input[i] > max)
            max = input[i]; // Maximum value in array
        else if(input[i] < min)
            min = input[i]; // Minimum value in array
    }

    int k = max - min + 1; // Size of count array

    int count_array[k]; // Create a count_array to store count of each individual input value
    fill_n(count_array, k, 0); // Initialize count_array elements as zero

    for(int i = 0; i < n; i++)
        count_array[input[i] - min]++; // Store count of each individual input value

    /* Change count_array so that count_array now contains actual
     position of input values in output array */
    for(int i = 1; i < k; i++)
        count_array[i] += count_array[i - 1];


    // Populate output array using count_array and input array
    for(int i = 0; i < n; i++)
    {
        output[count_array[input[i] - min] - 1] = input[i];
        count_array[input[i] - min]--;
    }


    for(int i = 0; i < n; i++)
        input[i] = output[i]; // Copy the output array to input, so that input now contains sorted values

}


// Driver program to test above function
int main()
{
    int n = 9, i;

    int input[] = {1, 5, 2, 7, 3, 4, 4, 1, 5};

    counting_sort(input, n);

    cout << "Sorted Array : ";
    for(i = 0; i < n; i++)
        cout << input[i] << "  ";

    return 0;
}


/* Output

Sorted Array : 1  1  2  3  4  4  5  5  7

*/
