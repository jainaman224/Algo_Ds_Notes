#include<stdio.h>

int Parition(int array[], int left, int right)
{
    int pivot = array[left];
    int index = right;
    int temp;
    int j;

    for(j = right; j > left; j--)
    {
        if(array[j] > pivot)
        {
            temp = array[j];
            array[j] = array[index];
            array[index] = temp;
            index--;
        }
    }

    array[left] = array[index];
    array[index] = pivot;
    return index;
}

void Quick(int array[], int left, int right)
{
    int pivot;
    if(left < right)
    {
        pivot = Parition(array, left, right);

        Quick(array, left, pivot - 1);
        Quick(array, pivot + 1, right);
    }
}

void Quick_Sort(int array[], int size)
{
    Quick(array, 0, size - 1);
}

// Function to print elements of array
void Print_Array(int array[], int size)
{
    int i;
    for(i = 0; i < size; i++)
        printf("%d\t",array[i]);

    printf("\n");
}

int main()
{
    int array[] = {2, 4, 3, 1, 6, 8, 4};
    Quick_Sort(array, 7);
    Print_Array(array, 7);
    return 0;
}

// Output
// 1 2 3 4 4 6 8
