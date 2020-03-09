#include <stdio.h>

// Function for bubble sort
void Bubble_Sort(int array[], int size)
{
    int temp, flag;
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
        printf("%d ", array[i]);

    printf("\n");
}

// Driver Function
int main()
{
    int n;
    printf("Enter number of elements in your array: ");
    scanf("%d", &n);
    int array[n];
    printf("Enter your array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    Bubble_Sort(array, n);
    Print_Array(array, n);
    return 0;
}

/* INPUT: 
Enter number of elements in your array: 7
Enter your array: 9
8
7
2
6
3
5
OUTPUT:
2 3 5 6 7 8 9 */
