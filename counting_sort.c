//Implementation of counting sort in c language

#include <stdio.h>

int main() 
{
    // initializing the variables of use
    int *arr ,*sort,i,max=0,j,size;

    printf("Enter the size of array:");
    scanf("%d",&size);

    //making dynamic array for actual array and resulting array of size variable named size
  	
    arr = (int*)malloc(size*sizeof(int));//actual array

    sort = (int*)malloc(size*sizeof(int));//resulting array

    printf("Enter array elements:\n");
    //taking array elements as input
    for (i=1;i<=size;i++)
    {
        scanf("%d",&arr[i]);
        if(max<arr[i])
        max=arr[i];
    }
    //making dynamic intermediate array which will be used for hashing
    int *temp;
    temp = (int*)malloc(max*sizeof(int));
    //initializing temporary array with all values as zero
    for (i = 0; i <= max; i++)
    {
        temp[i] = 0;
    }

    for (j = 1; j <= size; j++)
    {
        temp[arr[j]] = temp[arr[j]] + 1;
    }
	
    for (i = 1; i <= max; i++)
    {
        temp[i] = temp[i] + temp[i-1];
    }
	
    //storing sorted elements in sort array in order
    for (j = size; j >= 1; j--)

    {
        sort[temp[arr[j]]] = arr[j];
        temp[arr[j]] = temp[arr[j]] - 1;
    }
    //printing the sorted array
    printf("The sorted array is:\n");
    for(i=1;i<=size;i++)
    {
        printf("%d\t",sort[i]);
    }
    
}

//Input and output pattern
//Input will be in two lines first size of input array and second array elements
//size = 5;  size of input array
//5 4 2 8 1  input array elements


//Output
// 1  2  4  5  8


