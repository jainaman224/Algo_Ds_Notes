#include <iostream>

using namespace std;

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
        cout<<array[i] << " ";

    cout<<endl;
}

int main()
{
    int n, i;
    cout<<"Enter number of elements in your array: ";
    cin>>n;
    int array[n];
    cout<<"Enter your array: ";
    for (i = 0; i < n; i++)
    {
        cin>>array[i];
    }
    Heap_Sort(array, n);
    Print_Array(array, n);
    return 0;
}

/*Enter number of elements in your array: 7
Enter your array: 2
4
3
1
6
8
4
1 2 3 4 4 6 8*/
