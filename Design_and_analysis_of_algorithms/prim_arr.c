//prims mst
//array implementation
#include<stdio.h>
#include<stdlib.h>


//building adjacency list
struct adj
{
	int vertex;
	int weight;
	struct adj *next;
	
	
};
void insert_begin(struct adj** root_addr,int vertex, int weight)
{
	struct adj *new;
	new=(struct adj*)malloc(sizeof(struct adj));
	new->vertex=vertex;
	new->weight=weight;
	new->next=(*root_addr);
	(*root_addr)=new;
	
}

struct adj** build_adj_list(int v)
{
	int e,i,v1,v2,w;//v-#vertices, e-#edges
	struct adj **A;
	
	A=(struct adj**)malloc(sizeof(struct adj*)*v);
	for(i=0;i<v;i++)
	{
		A[i]=NULL;
	}
	printf("enter no. of edges: ");
	scanf("%d",&e);
	printf("enter all %d edges [0 based indexing for vertices] along with weights (i.e) enter 3 integers, 1st two being from the vertex set\n",e);
	for(i=0;i<e;i++)
	{
		scanf("%d %d %d",&v1,&v2,&w);
		insert_begin(&A[v1],v2,w);
		insert_begin(&A[v2],v1,w);
	}
	return A;
}



//prim
int extract_min(int* Q,int v)
{
	int i; 
	int min_index=-1,min=10000;
	for(i=0;i<v;i++)
	{
		if(Q[i]!=-1)
		{
			if(Q[i]<min)
			{
				min=Q[i];
				min_index=i;
			}
		}
	}
	Q[min_index]=-1;
	return min_index;
	
}
int* prim(int v, struct adj** Adj)//0th vertex is source
{
	int *Q;
	int i,u;
	int *pi;
	int Q_len=v;
	struct adj *curr;
	Q=(int *)malloc(sizeof(int)*v);
	pi=(int *)malloc(sizeof(int)*v);
	for(i=0;i<v;i++)
	{
		Q[i]=10000;
		pi[i]=-1;
	}
	Q[0]=0;
	
	while(Q_len-->0)
	{
		u=extract_min(Q,v);
		for(curr=Adj[u];curr!=NULL;curr=curr->next)
		{
			if(Q[curr->vertex]!=-1&&curr->weight<Q[curr->vertex])
			{
				Q[curr->vertex]=curr->weight;
				pi[curr->vertex]=u;
			}
		}
	}
	return pi;
	
	
}

int main()
{
	struct adj** A;
	int *pi;
	int v,i;
	printf("enter no. of vertices: ");	
	scanf("%d",&v);
	A=build_adj_list(v);
	pi=prim(v,A);
	for(i=1;i<v;i++)
	{
		printf("\n(%d,%d) is an edge",i,pi[i]);
	}
	
	
}
