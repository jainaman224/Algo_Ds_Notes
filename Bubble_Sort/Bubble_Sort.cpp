#include <iostream>

using namespace std;

// Function for bubble sort
void Bubble_Sort(int array[], int size)
{
    int temp, flag;
    // flag keeps track if any swap happened or not, if swap not happened then array is sorted and it will break out of the loop
    // and will save time from running for loop unnecessarily
    for (int i = 0; i < size - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            // Do swapping
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                flag++;
            }
        }
        if (!flag)
            break;
    }

}

// Function to print elements of array
void Print_Array(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";

    cout << endl;
}

// Driver Function
int main()
{
    int array[] = {2, 4, 3, 1, 6, 8, 4};
    Bubble_Sort(array, 7);
    Print_Array(array, 7);
    return 0;
}

// Output
// 1 2 3 4 4 6 8
