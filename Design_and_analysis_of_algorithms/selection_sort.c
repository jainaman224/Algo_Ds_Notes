#include<stdio.h>
int main()
{
	int input[10],i,j;
	printf("enter 10 integers:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&input[i]);
	}
	for(i=9;i>=0;i--)
	{
		int max=input[0];
		int max_index=0;
		for(j=1;j<=i;j++)
		{
			if(input[j]>max)
			{
				max=input[j];
				max_index=j;
			}
			int temp=input[max_index];
			input[max_index]=input[i];
			input[i]=temp;
			
		}
	}
	for(i=0;i<10;i++)
	{
		printf("%d\n",input[i]);
	}
}
