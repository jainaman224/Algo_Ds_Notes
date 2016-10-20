#include <iostream>
#include <vector>

using namespace std;


// Function for insertion sort
void Insertion_Sort(vector<int> &array)
{
    auto size = array.size();

    for(int i = 1; i < size; i++)
    {
        int temp = array[i];
        int j = i - 1;

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
void Print_Array(vector<int> array)
{
    auto size = array.size();
    for(int i = 0; i < size; i++)
        cout << array[i] << " ";

    cout << endl;
}


// Driver Function
int main()
{
    vector<int> array = {2, 4, 3, 1, 6, 8, 4};
    Insertion_Sort(array);
    Print_Array(array);
    return 0;
}

// Output
// 1 2 3 4 4 6 8
