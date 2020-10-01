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
	int num;
	scanf("%d", &num);
	int arr[num];
	for (int i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}
	int pos;
	int desired;
	scanf("%d", &desired);
	pos = search(arr, num, desired);
	if (pos != -1)
		printf("Number found at %d\n", pos);
	else
		printf("Number not found\n");
}

/*
Input :
num = 5
arr = [1,4,5,6,3]
desired = 3

Output :
Number not found
*/
