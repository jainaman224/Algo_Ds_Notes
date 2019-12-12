#include<stdio.h>
main()
{
	int input[10],i,j,key;
	printf("enter 10 integers:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&input[i]);
	}
	for(i=1;i<10;i++)
	{
		key=input[i];
		j=i-1;
		while(j>0&&key<input[j])
		{
			
			input[j+1]=input[j];
			j--;	
			
			
		}
		input[j+1]=key;
		
	}
	for(i=0;i<10;i++)
	{
		printf("%d\n",input[i]);
	}
}
