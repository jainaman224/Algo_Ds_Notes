#include <stdio.h>

// conquer
// places the new added element to its right position while building a heap
void Heapify(int array[], int root, int size)
{
    int left = 2 * root + 1, largest;
    int right = left + 1, temp;

    if(left < size && array[left] > array[root])
        largest = left;
    else
        largest = root;

    if(right < size && array[right] > array[largest])
        largest = right;

    if(largest != root)
    {
        temp = array[root];
        array[root] = array[largest];
        array[largest] = temp;
        Heapify(array, largest, size);
    }
}

// Divide array into halves
// call for heapify
void Build_Heap(int array[], int size)
{
    for(int i = (size - 1) / 2; i >= 0; i--)
        Heapify(array, i, size);
}


void Heap_Sort(int array[], int size)
{
    Build_Heap(array, size);
    int temp, i;

    for(i = size - 1; i > 0; i--)
    {
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        Heapify(array, 0, i);
    }
}

// Function to print elements of array
void Print_Array(int array[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ",array[i]);

    printf("\n");
}

int main()
{
    int array[] = {10, 2, 4, 3, 1, 6, 8, 5};
    Heap_Sort(array, 7);
    Print_Array(array, 7);
    return 0;
}

// Output
// 1 2 3 4 5 6 8 10