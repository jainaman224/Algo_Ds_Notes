#include <iostream>

using namespace std;

// Quick Sort using Bentley-McIlroy 3-way Partitioning
void Quick_Sort_3way(int array[], int left, int right)
{
    int pivot = array[right];
    int i = left -1;
    int j = right;
    int p = left - 1;
    int q = right;

    if(right <= left) return;

    while(true)
    {
        while(array[++i] < pivot) {}

        while(pivot < array[--j])
        {
              if (j == left) break;
        }

        if(i >= j) break;
        swap(array[i], array[j]);

        if(array[i] == pivot)
        {
            p++;
            swap(array[p], array[i]);
        }

        if(array[j] == pivot)
        {
            q--;
            swap(array[j], array[q]);
        }
    }

    swap(array[i], array[right]);
    j = i - 1;
    i = i + 1;

    for(int k = left; k < p; k++, j--)
        swap(array[k], array[j]);

    for(int k = right - 1; k > q; k--, i++)
        swap(array[i], array[k]);

    Quick_Sort_3way(array, left, j);
    Quick_Sort_3way(array, i, right);
}

// Function to print elements of array
void Print_Array(int array[], int size)
{
    for(int i = 0; i < size; i++)
        cout << array[i] << " ";

    cout << endl;
}

// Driver Function
int main()
{
    int array[] = {2, 4, 3, 1, 6, 8, 4};
    int size = sizeof(array) / sizeof(int);
    Quick_Sort_3way(array, 0, size - 1);
    Print_Array(array, size);
    return 0;
}

// Output
// 1 2 3 4 4 6 8
