// Count inversion using merge sort

#include <stdio.h>

//merge two sorted arrays such that resultant array is also sorted
int merge(int array[], int aux[], int low, int mid, int high)
{
    int x = low, y = mid, z = low, count = 0;

    // checking till left and right half of merge sort
    while ((x <= mid-1) && (y <= high)) 
    {
        if (array[x] <= array[y]) 
        {
            aux[z++] = array[x++];
        }
        else
        {
            aux[z++] = array[y++];
            count += mid-x;
        }
    }

    // Copy remaining elements
    while (x <= mid-1)
    {
        aux[z++] = array[x++];
    }
    
    while (y <= high) 
    {
        aux[z++] = array[y++];
    }

    // Sorting the original array with the help of aux array
    for (int i = low; i <= high; i++)
    {
        array[i] = aux[i];
    }
    return count;
}

//merge sort to find inversion count
int mergeSort(int array[], int aux[], int low, int high) 
{
    int count = 0;
    if (high > low)
    {
        int mid = (low + high) / 2;

        // merge sort on Left half of the array
        count = mergeSort(array, aux, low, mid);
        // merge sort on Right half of the array
        count += mergeSort(array, aux, mid + 1, high);
        // Merge the two half
        count += merge(array, aux, low, mid + 1, high);
    }
    return count;
}

//wrapper function that returns number of inversions
int inversions_count(int array[], int n) 
{
    int aux[n];
    return mergeSort(array, aux, 0, n-1);
}

int main()
{       
    int array[] = {1, 2, 7, 6, 8, 9, 1, 2};
    int n = sizeof(array) / sizeof(array[0]);
    printf ("%d", inversions_count(array, n));
    return 0;
}

//OUTPUT:10
