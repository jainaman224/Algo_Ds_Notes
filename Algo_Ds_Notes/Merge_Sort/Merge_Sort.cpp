#include <iostream>

using namespace std;

int *temp;

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
    if(left < right)
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
    int n, i;
    cout << "Enter number of elements in your array: ";
    cin >> n;
    int array[n];
    cout << "Enter your array: ";
    for(i = 0; i < n; i++)
        cin >> array[i];
    Merge_Sort(array, n);
    Print_Array(array, n);
    return 0;
}

/*
Input:
Enter number of elements in your array: 7
Enter your array: 2
4
3
1
6
8
4
Output:
1 2 3 4 4 6 8 */
