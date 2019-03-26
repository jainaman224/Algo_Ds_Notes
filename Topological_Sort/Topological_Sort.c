#include <stdio.h>

void topologicalsort(int a[][10],int num)
{ 
	int indegree[10],flag[10],count=0;
	int k,j,i;

	for(i=0;i<num;i++)
	{
		indegree[i]=0;
		flag[i]=0;
	}
 
	for(i=0;i<num;i++)
		for(j=0;j<num;j++)
			indegree[i]=indegree[i]+a[j][i];
 
	printf("\nThe topological order is:");
 
	while(count<num)
	{
		for(k=0;k<num;k++)
		{
			if((indegree[k]==0) && (flag[k]==0))
			{
				printf("%d ",(k+1));
				flag [k]=1;
			}
 
			for(i=0;i<num;i++)
			{
				if(a[i][k]==1)
					indegree[k]--;
			}
		}
 
		count++;
	}
}

int main()
{
	int i,j,num,a[10][10];
 
	printf("Enter the no of vertices:\n");
	scanf("%d",&num);
 
	printf("Enter the adjacency matrix:\n");
	for(i=0;i<num;i++)
	{
		printf("Enter row %d\n",i+1);
		for(j=0;j<num;j++)
			scanf("%d",&a[i][j]);
	}
	
	topologicalsort( a, num);
	return 0;
}

//INPUT:Enter the no of vertices:
//4
//Enter the adjacency matrix:
//Enter row 1
//0
//1
//1
//0
//Enter row 2
//0
//0
//0
//1
//Enter row 3
//0
//0
//0
//1
//Enter row 4
//0
//0 
//0
//0

//OUTPUT:The topological order is:1 2 3 4 
