//Program for Binary Seach implemented in C
#include<stdio.h>

void binary_search(int ele,int a[10],int array_size)
{
	int mid,first,last,flag=0; // flag checks wether we found the element or not
	first=0;
	last=array_size-1;

	while(first<=last)
	{
		mid=(first+last)/2;
		if(a[mid]==ele)
		{
			flag=1;
			break;
		}
		else if(a[mid]>ele)
			last=mid-1;
		else
			first=mid+1;
	}

	//printf("%d %d",mid,flag);
	if(flag==1)
		printf("\nThe element %d was found at position %d\n",ele,mid+1);
	else
		printf("\nThe element %d was not found in the array you entered\n",ele);
}

int main()
{
	int ele; //ele is the element we are searching for in the array
	int a[10]={9,15,23,45,67,82,91}; // Inserted array to be sorted,
	ele=67;                          // as then only binary search will be able to work
	binary_search(ele,a,7);
	ele=24;
	binary_search(ele,a,7);
	return 0;
	
}
//OUTPUT:-
//
//The element 67 was found at position 5
//
//The element 24 was not found in the array you entered
