#include<stdio.h>

// Function for selection sort
void Selection_Sort(int array[], int size)
{
    int min_index, temp, i, j;

    for(i = 0; i < size - 1; i++)
    {
        min_index = i;

        for(j = i + 1; j < size; j++)
            if(array[j] < array[min_index])
                min_index = j;

        temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }
}

// Function to print elements of array
void Print_Array(int array[], int size)
{
    int i;
    for(i = 0; i < size; i++)
        printf("%d\t",array[i]);

    printf("\n");
}

// Driver Function
int main()
{
    int array[] = {2, 4, 3, 1, 6, 8, 4};
    Selection_Sort(array, 7);
    Print_Array(array, 7);
    return 0;
}

// Output
// 1 2 3 4 4 6 8
