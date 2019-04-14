// C++ implementation of Shell Sort
#include <iostream>

using namespace std;

int Shell_Sort(int array[], int size)
{
    for(int gap = size / 2; gap > 0; gap /= 2)
    {
        for(int i = gap; i < size; i++)
        {
            int temp = array[i], j;

            for(j = i; j >= gap && array[j - gap] > temp; j -= gap)
                array[j] = array[j - gap];

            array[j] = temp;
        }
    }

    return 0;
}

void Print_Array(int array[], int size)
{
    for(int i = 0; i < size; i++)
        cout << array[i] << " ";

    cout << endl;
}

int main()
{
    int array[] = {12, 34, 54, 2, 3};
    int size = 5;

    Shell_Sort(array, size);
    Print_Array(array, size);

    return 0;
}


/* Output

2 3 12 34 54

*/
