#include <stdio.h>

// Function for insertion sort
void Insertion_Sort(int array[], int size)
{
    int temp, j, i;

    for(i = 1; i < size; i++)
    {
        temp = array[i];
        j = i - 1;

        // Do swapping
        while(j >= 0 && array[j] > temp)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = temp;
    }
}

// Function to print elements of array
void Print_Array(int array[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%d\t",array[i]);

    printf("\n");
}

// Driver Function
int main()
{
    int array[] = {2, 4, 3, 1, 6, 8, 4};
    Insertion_Sort(array, 7);
    Print_Array(array, 7);
    return 0;
}

// Output
// 1 2 3 4 4 6 8