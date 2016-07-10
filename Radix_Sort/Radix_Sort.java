// Java Implementation of Radix Sort

public class Radix_Sort 
{
    // Function implementing Radix Sort
    public static void radix_sort(int input[]) 
    {
        int i;
        int max = input[0]; // Maximum Element in input array
        int size = input.length;

        // Find the Maximum element in array
        for (i = 1; i < size; i++) 
        {
            if (input[i] > max)
                max = input[i];
        }

        for (int exp = 1; max / exp > 0; exp *= 10) 
        {
            Counting_Sort(input, size, exp); // Subroutine call to Counting_Sort
        }

    }

    // Counting_Sort
    public static void Counting_Sort(int input[], int size, int exp) 
    {
        int output[] = new int[size];
        int i;
        int count[] = new int[10];

        for (i = 0; i < size; i++)
            count[(input[i] / exp) % 10]++;

        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (i = size - 1; i >= 0; i--) 
        {
            output[count[(input[i] / exp) % 10] - 1] = input[i];
            count[(input[i] / exp) % 10]--;
        }

        for (i = 0; i < size; i++)
            input[i] = output[i];
    }

    // Driver Function
    public static void main(String[] args) 
    {
        int i;
        int input[] = {1, 123, 458, 789, 85, 25, 75}; 

        radix_sort(input); 

        // Printing Sorted Array 
        for (i = 0; i < input.length; i++)
            System.out.print(input[i] + " ");

        System.out.println();
    }

}


/*

Output: 1 25 75 85 123 458 789 

*/
