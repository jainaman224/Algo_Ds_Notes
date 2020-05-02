#include<stdio.h>

void main()
{
	int arr[100] , i , j , k , p , n , value , index , l , temp;
    //input for array size
	printf("enter the number of elements required \n");
	scanf("%d" , &n);
    printf("enter the elements of the array \n");
	for(i = 0;i < n;i++)
	{
		scanf("%d", &arr[i]);
	}
    //this sorting follows comparing process,with it's right elements hence loop goes to n-2 to avoid garbage values in the output
	for(k = 0;k < n - 2;k++)
	{ 
		value = arr[k];
		index = k;
        //loop to find number of elements less than the element in consideration 
		for(j = k + 1;j < n;j++)
		{
			if(arr[j] < value)
			{
				index++ ;
			}
		}
        //if the element is at right position
		if(index == k)
		{
			continue ;
	    }
        //skipping duplicate elements
		while(arr[index] == value)
		{

			index++ ;
	    }
        //providing the correct position to the element
		if(index != k)
		{
			temp = value;
			value = arr[index];
			arr[index] = temp;
		}
        //rotate rest of the cycle
		while(index != k)
		{
			index = k;
			for(p = k + 1;p < n;p++ )
			{
				if(arr[p] < value)
				{
					index++ ;
				}
			}

		while(arr[index] == value)
		{

			index++ ;
     	}
     	if(index != k)
		{
			temp = value;
			value = arr[index];
			arr[index] = temp;
		}

		}
		arr[k] = value;
	}
	//print resulting sorted array		
	printf("the sorted array is");
	for(l = 0;l < n;l++ )
	{
		printf("%d\t",arr[l]);
	}
}

//sample input-output
/*enter the number of elements required
6
enter the elements of the array
4
9
3
2
4
6
the sorted array is 2 3 4 4 6 9*/
