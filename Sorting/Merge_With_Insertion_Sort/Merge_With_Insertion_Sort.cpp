#include <iostream>

using namespace std;

int *temp;

void insertion(int array[], int left, int right)
{
    for(int i = left; i <= right; i++)
    {
        int j = i;
        int key = array[i];
        while((j > left) && (array[j-1] > key))
        {
            array[j] = array[j-1];
            j--;
        }
        array[j] = key;
    }
}

// Conquer
void conquer_merge(int array[], int left, int right, int mid)
{
    int k = left, i, j;

    for(i = left, j = mid + 1; i <= mid && j <= right; k++)
    {
        if(array[i] <= array[j])
        {
            temp[k] = array[i];
            i++;
        }
        else
        {
            temp[k] = array[j];
            j++;
        }
    }

    while(i <= mid)
    {
        temp[k] = array[i];
        i++;
        k++;
    }

    while(j <= right)
    {
        temp[k] = array[j];
        j++;
        k++;
    }

    for(i = left; i <= right; i++)
        array[i] = temp[i];
}


// Divide array into halves
void divide(int array[], int left, int right)
{
    // If the size of subarray to be sorted is less than or equal to 8.
    // Perform Insertion Sort
    if(right - left <= 8)
        insertion(array, left, right);
    // If size of array is greater than 8.
    // Perform Merge_Sort
    else
    {
        int mid = left + (right - left) / 2;

        divide(array, left, mid);
        divide(array, mid + 1, right);

        conquer_merge(array, left, right, mid);
    }
}

void Merge_Sort(int array[], int size)
{
    temp = new int[size];
    divide(array, 0, size - 1);
    delete [] temp;
}

// Function to print elements of array
void Print_Array(int array[], int size)
{
    for(int i = 0; i < size; i++)
        cout << array[i] << " ";

    cout << endl;
}

int main()
{
    int array[] = {2, 4, 3, 1, 6, 8, 4, 10, 11, 0, 15, 7, 9};
    Merge_Sort(array, 13);
    Print_Array(array, 13);
    return 0;
}

// Output
// 0 1 2 3 4 4 6 7 8 9 10 11 15
