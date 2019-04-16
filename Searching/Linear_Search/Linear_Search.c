#include <stdio.h>

int search(int a[],int size, int elt)
{
	int i,flag = -1;
	for (i=0;i<size;i++)
		if (a[i] == elt)
		{
			flag = i+1;
			break;
		}
	return flag;	//Return position
}

int main()
{
	int arr[] = {23,43,2,67,90,2,6,19};
	int pos;
	//Search 6 in the list
	pos = search(arr,8,6);
	if (pos != -1)
		printf("Number found at %d\n", pos);
	else
		printf("Number not found\n");
	//Search 4 in the list
	pos = search(arr,8,4);
		if (pos != -1)
		printf("Number found at %d\n", pos);
	else
		printf("Number not found\n");
}

/*Output
Number found at 7
Number not found
*/
