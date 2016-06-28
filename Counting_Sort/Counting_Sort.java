// Java implementation of Counting Sort
public class Counting_Sort {
    // Function that sort the given input
    public static void sort(int input[])
    {
        int n = input.length;
        int output[] = new int[n]; // The output will have sorted input array

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
        int count_array[] = new int[k]; // Create a Count array

        for(int i = 0; i < n; i++)
            count_array[input[i] - min]++; // Store count of each individual input value

        // Change count_array so that count_array now contains actual
        // position of input values in output array
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
    public static void main(String[] args)
    {
        int input[] = {1, 5, 2, 7, 3, 4, 4, 1, 5};

        sort(input);

        System.out.print("Sorted Array : ");
        for(int i = 0; i < input.length; i++)
            System.out.print(input[i] + " "); // Printing the sorted array

        System.out.println();
    }
}


/* Output

Sorted Array : 1  1  2  3  4  4  5  5  7

*/
