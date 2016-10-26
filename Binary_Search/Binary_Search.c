#include <stdio.h>

// Function for binary search
int Binary_Search(int *array, int size, int desired)
{
    unsigned int left = 0, right = size - 1;

    while(left<=right)
    {
        // Return position if found
        unsigned int middle = left + (right - left) / 2;

        if(array[middle] == desired)
            return middle;
        else if(desired < array[middle])
            right = middle - 1;
        else if(desired > array[middle])
            left = middle + 1;
    }

    return -1;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7};

    // Element 4 to be searched
    if(Binary_Search(array, 7, 4) != -1)
        printf("Found\n");
    else
        printf("Not Found\n");

    //Element 9 to be searched
    if(Binary_Search(array, 7, 9) != -1)
        printf("Found\n");
    else
        printf("Not Found\n");

    return 0;
}

/* Output

Found
Not Found

*/
