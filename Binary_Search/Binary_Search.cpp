#include <iostream>

using namespace std;

// Function for binary search
int binarySearch(int array[], int size, int desired)
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
int lowerBound(int array[], int size, int desired)
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
int upperBound(int array[], int size, int desired)
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
    int num;
    scanf("%d", &num);
    int array[num];
    for (int i = 0; i < num; i++) {
        scanf("%d", &array[i]);
    }
    int desired;
    scanf("%d", &desired);
    if (binarySearch(array, num, desired) != -1)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    // Element greater than or equal than 5
    cout << lowerBound(array, num, 5) << endl;

    // Element greater than or equal than 6
    cout << lowerBound(array, num, 6) << endl;

    // Element greater than 5
    cout << upperBound(array, num, 5) << endl;

    // Element greater than 0
    cout << upperBound(array, num, 0) << endl;

    return 0;
}

/* 
Input:
num = 7
array = {1, 2, 3, 4, 5, 6, 7}
desired = 4

Output:
Found
4
6
6
0

Input:
num = 5
array = {1, 3, 5, 7, 9}
desired = 2

Output:
Not Found
2
3
3
0
*/
