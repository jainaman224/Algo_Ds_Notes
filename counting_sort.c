//Implementation of counting sort in c language

#include <conio.h>
#include <stdio.h>

int main() 
{
	// initializing the variables of use
    int *a ,*c,i,max=0,j,n;

    printf("Enter the size of array:");
    scanf("%d",&n);

    //making dynamic array for actual array and resulting array of size n
  	
    a = (int*)malloc(n*sizeof(int));//actual array

    c = (int*)malloc(n*sizeof(int));//resulting array

    printf("Enter array elements:\n");
    //taking array elements as input
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(max<a[i])
        max=a[i];
    }
    //making dynamic intermediate array which will be used for hashing
    int *b;
    b = (int*)malloc(max*sizeof(int));
    //initializing temporary array with all values as zero
    for (i = 0; i <= max; i++)
    {
        b[i] = 0;
    }

    for (j = 1; j <= n; j++)
    {
        b[a[j]] = b[a[j]] + 1;
    }
    for (i = 1; i <= max; i++)
    {
        b[i] = b[i] + b[i-1];
    }
    //storing sorted elements in c array in order
    for (j = n; j >= 1; j--)

    {
        c[b[a[j]]] = a[j];
        b[a[j]] = b[a[j]] - 1;
    }
    printf("The sorted array is:\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",c[i]);
    }
    //to hold the result in turboc++ it takes a single charater and program ends
    getch();
}

