#include <stdio.h>
int i, j, temp, max, count, maxdigits = 0, c = 0;

/* Function to arrange the of sequence having same base */
void arrange(int array[], int array1[], int k , int n)
{
    for (i = k; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (array1[i] > array1[j])
            {
                temp = array1[i];          // swapping of elements
                array1[i] = array1[j];
                array1[j] = temp;

                temp = (array[i] % 10);       // swapping of elements after reducing length of digits
                array[i] = (array[j] % 10);
                array[j] = temp;
            }
        }
    }
}

int main()
{
    int temp, t, n = 1;
    printf("Enter the size of array : ");
    scanf("%d", &count);  // size of array

    int array[count], array1[count];

    printf("Enter the elements of array : ");
    for (i = 0; i < count; i++)
    {
        scanf("%d", &array[i]);  // array elements
        array1[i] = array[i];   // duplicate array for output
    }

    printf("\nInput Array (Without sorting) :");
    for (i = 0; i < count; i++)
        printf("%d ", array1[i]);

    for (i = 0; i < count; i++)
    {
        t = array[i];        /*first element in t */
        while(t > 0)
        {
            c++;
            t = t / 10;        /* Find MSB */
        }

        if (maxdigits < c)  maxdigits = c;   /* number of digits of a each number */
        c = 0;
    }

    while(--maxdigits) n = n * 10;

    for (i = 0; i < count; i++)
    {
        max = array[i] / n;        /* MSB - Dividing by particular base */
        t = i;
        for (j = i + 1; j < count;j++)
        {
            if (max > (array[j] / n))
            {
                max = array[j] / n;   /* greatest MSB */
                t = j;
            }
        }

        temp = array1[t];           // swapping of elements
        array1[t] = array1[i];
        array1[i] = temp;

        temp = array[t];           // swapping of elements
        array[t] = array[i];
        array[i] = temp;

    }

    while (n >= 1)
    {
        for (i = 0; i < count;)
        {
            temp = array[i] / n;
            for (j = i + 1; temp == (array[j] / n); j++);
            arrange(array, array1, i, j);
            i = j;
        }
        n = n / 10;
    }

    printf("\nSorted Array (Postman sort) :");
    for (i = 0; i < count; i++)
        printf("%d ", array1[i]);

    printf("\n");
    return 0;

}

/*
Enter the size of array : 5
Enter the elements of array : 50 40 20 10 5

Input Array (Without sorting) :50 40 20 10 5
Sorted Array (Postman sort) :5 10 20 40 50
*/
