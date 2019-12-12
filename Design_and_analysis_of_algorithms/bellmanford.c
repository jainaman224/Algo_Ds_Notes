#include<stdio.h>
#include<stdlib.h>


//building adjacency list
struct edge
{
	int vertex1,vertex2;
	int weight;
	
	
	
};





void print_path(int *path,int vertex)
{
	if(vertex==0)
	{
		printf("0\n");
		return;
	}
	if(path[vertex]<0)
	{
		printf("\nerror in path\n");
	}
	printf("%d<-",vertex);
	print_path(path,path[vertex]);
	
}

struct edge* build_E(int v,int e)
{
	int i,v1,v2,w;//v-#vertices, e-#edges
	struct edge* E;	
	E=(struct edge*)malloc(sizeof(struct edge)*e);
	printf("enter all %d edges [0 based indexing for vertices] along with weights (i.e) enter 3 integers, 1st two being from the vertex set\n",e);
	for(i=0;i<e;i++)
	{
		scanf("%d %d %d",&v1,&v2,&w);
		E[i].vertex1=v1;
		E[i].vertex2=v2;
		E[i].weight=w;
	}
	return E;
}

void bellman(int v,struct edge* E,int e)//0th vertex is source
{
	int *Q;
	int i,u;
	int *path;
	

	
	Q=(int *)malloc(sizeof(int)*v);
	
	path=(int *)malloc(sizeof(int)*v);
	for(i=0;i<v;i++)
	{
		Q[i]=10000;
		path[i]=-1;
		
	}
	Q[0]=0;
	
	for(i=1;i<v;i++)
	{
		for(i=0;i<e;i++)
		{
			if((Q[E[i].vertex1]+E[i].weight)<Q[E[i].vertex2])
			{
				Q[E[i].vertex2]=Q[E[i].vertex1]+E[i].weight;
				path[E[i].vertex2]=E[i].vertex1;
			}
		}
	}
	for(i=0;i<e;i++)
		{
			if((Q[E[i].vertex1]+E[i].weight)<Q[E[i].vertex2])
			{
				printf("\n-ve cycle is present\n");
				return;
			}
		}
	for(i=1;i<v;i++)
	{
		printf("length of shortest path is %d and shortest path is ",Q[i]);
		print_path(path,i);
	}
	
	
}


int main()
{
	struct edge* E;
	int v,e,i;
	printf("enter no. of vertices: ");	
	scanf("%d",&v);
	printf("enter no. of edges: ");
	scanf("%d",&e);
	E=build_E(v,e);
	bellman(v,E,e);
	
	
	
}
