#include <iostream>

using namespace std;

// Function for binary search
int Binary_Search(int array[], int size, int desired)
{
    int left = 0, right = size - 1, middle;

    while (left <= right)
    {
        middle = left + (right - left) / 2;

        if (array[middle] == desired)
            return middle;
        else if (desired < array[middle])
            right = middle - 1;
        else
            left = middle + 1;
    }

    return -1;
}


// Function for lower bound:
// finds the position of the lowest number greater than or equal to desired
int Lower_Bound(int array[], int size, int desired)
{
    int left = -1, right = size, middle;
    while (right - left > 1)
    {
        middle = left + (right - left) / 2;

        if (array[middle] < desired)
            left = middle;
        else
            right = middle;
    }
    return right;
}


// Function for upper bound:
// finds the position of the lowest number strictly greater than desired
int Upper_Bound(int array[], int size, int desired)
{
    int left = -1, right = size, middle;
    while (right - left > 1)
    {
        middle = left + (right - left) / 2;

        if (array[middle] <= desired)
            left = middle;
        else
            right = middle;
    }
    return right;
}


// Driver Function
int main()
{
    int array[] = {1, 2, 3, 4, 5, 5, 7};

    // Element 4 to be searched
    if (Binary_Search(array, 7, 4) != -1)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    //Element 9 to be searched
    if (Binary_Search(array, 7, 9) != -1)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    // Element greater than or equal than 5
    cout << Lower_Bound(array, 7, 5) << endl;

    // Element greater than or equal than 6
    cout << Lower_Bound(array, 7, 6) << endl;

    // Element greater than 5
    cout << Upper_Bound(array, 7, 5) << endl;

    // Element greater than 0
    cout << Upper_Bound(array, 7, 0) << endl;

    return 0;
}

/* Output

Found
Not Found
4
6
6
0

*/
