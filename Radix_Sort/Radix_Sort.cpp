// C++ implementation of Radix Sort
#include <iostream>

using namespace std;

int Max_Element(int array[], int size)
{
    int max = array[0];

    for(int i = 1; i < size; i++)
        if(array[i] > max)
            max = array[i];

    return max;
}

void Counting_Sort(int array[], int size, int exp)
{
    int output[size];
    int i, count[10] = {0};

    for(i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for(i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for(i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for(i = 0; i < size; i++)
        array[i] = output[i];
}

void Radix_Sort(int array[], int size)
{
    int max = Max_Element(array, size);

    for(int exp = 1; max / exp > 0; exp *= 10)
        Counting_Sort(array, size, exp);
}

void Print_Array(int array[], int size)
{
    for(int i = 0; i < size; i++)
        cout << array[i] << " ";

    cout << endl;
}

int main()
{
    int array[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int size = 8;

    Radix_Sort(array, size);

    Print_Array(array, size);

    return 0;
}


/* Output

2 24 45 66 75 90 170 802

*/
