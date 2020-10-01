#include <stdio.h>

// Function that sort the given input
void counting_sort(int input[], int n)
{
    int output[n]; // The output will have sorted input array
    int max = input[0];
    int min = input[0];

	int i;
    for(i = 1; i < n; i++)
    {
        if(input[i] > max)
            max = input[i]; // Maximum value in array
        else if(input[i] < min)
            min = input[i]; // Minimum value in array
    }

    int k = max - min + 1; // Size of count array

    int count_array[k]; // Create a count_array to store count of each individual input value
    for(i=0; i<k; i++)
        count_array[i]=0;

    for(i = 0; i < n; i++)
        count_array[input[i] - min]++; // Store count of each individual input value

    /* Change count_array so that count_array now contains actual
     position of input values in output array */
    for(i = 1; i < k; i++)
        count_array[i] += count_array[i - 1];

    // Populate output array using count_array and input array
    for(i = 0; i < n; i++)
    {
        output[count_array[input[i] - min] - 1] = input[i];
        count_array[input[i] - min]--;
    }

    for(i = 0; i < n; i++)
        input[i] = output[i]; // Copy the output array to input, so that input now contains sorted values

}


// Driver program to test above function
int main()
{
    int n, i;
    printf("Enter number of elements in your array: ");
    scanf("%d", &n);

    int input[n];
    printf("Enter your array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &input[i]);

    counting_sort(input, n);

    printf("Sorted Array : ");
    for (i = 0; i < n; i++)
        printf("%d ", input[i]);

    return 0;
}

/* Enter number of elements in your array: 9
Enter your array: 1
5
2
7
3
4
4
1
5
Sorted Array : 1 1 2 3 4 4 5 5 7
*/
