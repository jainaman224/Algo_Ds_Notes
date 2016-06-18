#include <iostream>

using namespace std;

// Function for linear search
int Linear_Search(int array[], int size, int desired)
{
    for(int i = 0; i < size; i++)
    {
        // return position if element is found
        if(array[i] == desired)
        {
            return i;
        }
    }
    return -1;
}

// Driver Function
int main()
{
    int array[] = {2, 4, 6, 7, 3, 1, 5};

    // Element 4 to be searched
    if(Linear_Search(array, 7, 4) != -1)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    //Element 9 to be searched
    if(Linear_Search(array, 7, 9) != -1)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}

// Output
// Found
// Not Found
