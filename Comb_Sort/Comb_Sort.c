#include <stdio.h>
 
void combSort(int arr[], int n)
{
	// initialize gap with array length
	int gap = n;
	int flag= 1;
	while (gap > 1 || flag == 1) 
	{
		// updating gap value by using shrink factor as 1.3
		gap = (gap * 10) / 13;
		// if Gap is less than 1, take gap as 1
		if(gap<1)
			gap= 1;
    
		flag= 0;
		// Compare all elements with the obtained gap value
		for (int i = 0; i < (n - gap); i++) 
		{
			// Swap arr[i] and arr[i+gap] if arr[i] is greater and update the flag
			if (arr[i] > arr[i + gap]) 
			{
				int temp;
				temp=arr[i];
				arr[i]= arr[i+gap];
				arr[i+gap]=temp;
				flag= 1;
			}
		}
	}
}

// Driver function
int main() 
{ 
	int n;
	printf("Enter the number of elements ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements ");
	for (int i=0;i<n;i++)
		scanf("%d",&arr[i]);
  
	// Call to combSort function
	combSort(arr, n);
  
	// Printing sorted array
	printf("Sorted array:\n");
	for (int i = 0; i < n; i++)
		printf("%d ",arr[i]);
}

// INPUT:Enter the number of elements 5
//Enter the elements -10
//9
//0
//8
//2

//OUTPUT:Sorted array:
//-10 0 2 8 9 
