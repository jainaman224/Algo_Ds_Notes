#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h> 

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


bool circle_sort_rec(int *arr,int n)
{
	bool swaped =false;
	int mid,i;
	if(n<=2)
	{
		if(arr[0]>arr[n-1])
		{
			swap(&arr[0],&arr[n-1]);
			swaped = true;
		}
		return swaped;
	}
	mid = (n+1)/2;
	for(i=0;i<mid;i++)
	{
		if(i == n-i-1)
		{
			if(arr[i]>arr[i+1])
			{
				swap(&arr[i],&arr[i+1]);
				swaped = true;
			}
		}
		else
		{
			if(arr[i]>arr[n-i-1])
			{
				swap(&arr[i],&arr[n-i-1]);
				swaped = true;
			}
		}
	}
	if(circle_sort_rec(arr,mid))
		swaped = true;
	if(circle_sort_rec(arr+mid,n-mid))
		swaped =true;
	return swaped;
}

void circle_sort(int *arr,int size)
{
	while(circle_sort_rec(arr,size))
	{
		;
	}
	return;
}

void main()
{
	int *arr;
	int size,i;
	printf("Enter the size of the array : ");
	scanf("%d", &size);
	arr = (int *)malloc(size * sizeof(int));
	printf("Enter the elements of the array : ");
	for(i=0;i<size;i++)
		scanf("%d",arr+i);
	circle_sort(arr,size);
	for(i=0;i<size;i++)
		printf("%d ", arr[i]);
	free(arr);
}
