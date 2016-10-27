#include <stdio.h>

int Binary_Search(int array[], int size, int desired)
{
    int left = 0, right = size - 1, middle;

    while(left <= right)
    {
        middle = left + (right - left) / 2;

        if(array[middle] == desired)
            return middle;

        else if(desired < array[middle])
            right = middle - 1;
        
        else if(desired > array[middle])
            left = middle + 1;
    }

    return -1;
}

// main unction
int main()
{
    int array[] = {2, 8, 23, 44, 235, 547};

    if(Binary_Search(array, 6, 44) != -1)
        printf("Found \n" );
    else
        printf("Not Found \n" );

    if(Binary_Search(array, 7, 976) != -1)
        printf("Found \n" );
    else
        printf("Not Found \n" );

    return 0;
}