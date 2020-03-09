// C implementation of Shell Sort
#include <stdio.h>

void Shell_Sort(int array[], int size)
{
	int gap, i, temp, j;

	for (gap = size / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			for (j = i; j >= gap && array[j-gap] > temp; j -= gap)
				array[j] = array[j - gap];

			array[j] = temp;
		}
	}
}

void Print_Array(int array[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", array[i]);

	printf("\n");
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
