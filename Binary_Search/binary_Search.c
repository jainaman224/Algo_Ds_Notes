#include <stdio.h>

int binary_search(int array[], int size, int desired)
{
	int left = 0,
		right = size - 1,
		middle;

	while(left <= right)
	{
		middle = (left + right) / 2;
		if(desired == array[middle])
			return middle;
		else if(desired > array[middle])
			left = middle;
		else if(desired < array[middle])
			right = middle;
	}

	return -1;
}

int main()
{
	// Binary search works with sorted arrays only
	int array[10], found, desired;
	
	printf("\n Enter an integer array of length 10 in ascending order : ");
	for(int i = 0;  i < 10; i++)
		scanf("%d", &array[i]);

	printf("\n Enter the number you want to search for : ");
	scanf("%d", &desired);

	/*
		Suppose we want to search the number 7 in the array below
		{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

		The algorithm proceeds as follows

		left	right	middle	desired		found
		  0		  9	  	  4		   7
		  4		  9		  6		   7
		  6		  9		  7		   7		  7
	*/ 

	found = binary_search(array, 10, 7);
	if(found != -1)
		printf("\n %d found at position %d", desired, found);
	else
		printf("%d not found in array", desired);

	return 0;
}