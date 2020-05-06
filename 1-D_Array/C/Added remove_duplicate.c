#include<stdio.h>    /*Header file inclusion statement*/
int main()           /*Driver function*/
{
    int i,n,j,k;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int a[n];
    printf("The array elements are : ");    /*Taking input from user*/
    for(i=0;i<n;i++)
    {
    	scanf("%d",&a[i]);
    }
	printf("The array without duplicates : ");
	for(i=0;i<n;i++)
	{
	    for(j=i+1;j<n;j++)
	    {
	        if(a[i]==a[j])
	        {
		        for(k=j;k<n;k++)
		        {
			        a[k]=a[k+1];    /*Logic statement for removing duplicates*/
		        }
		n--;
		j--;
	            }	
            }
    }
    for (i = 0; i < n; i++) 
	{
        printf("%d ", a[i]);   /*Printing the new array without duplicates*/
    }

	return 0;  /*Return statement*/
}
