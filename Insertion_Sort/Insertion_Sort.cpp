#include <iostream>

using namespace std;

// Function for insertion sort
void Insertion_Sort(int array[], int size)
{
    int temp, j;

    for(int i = 1; i < size; i++)
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
        cout << array[i] << " ";

    cout << endl;
}

// Driver Function
int main()
{
    int num;
    cin >> num;
    int array[num];
    for (int i = 0; i < num; i++) {
        cin >> array[i];
    }
    Insertion_Sort(array, num);
    Print_Array(array, num);
    return 0;
}

/*
Input :
num = 6
array = [1, 6, 3, 3, 5, 2]

Output :
[1, 2, 3, 3, 5, 6]
*/
