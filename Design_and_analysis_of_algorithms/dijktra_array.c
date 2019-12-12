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
		//insert_begin(&A[v2],v1,w);
	}
	return A;
}

int extract_min(int* Q,int* S,int v)
{
	int i; 
	int min_index=-1,min=10000;
	for(i=0;i<v;i++)
	{
		if(S[i]!=1)
		{
			if(Q[i]<min)
			{
				min=Q[i];
				min_index=i;
			}
		}
	}
	S[min_index]=1;
	return min_index;
	
}

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

void dijktra(int v, struct adj** Adj)//0th vertex is source
{
	int *Q;
	int i,u;
	int *path;
	int *S;
	int Q_len=v;
	struct adj *curr;
	Q=(int *)malloc(sizeof(int)*v);
	S=(int *)malloc(sizeof(int)*v);
	path=(int *)malloc(sizeof(int)*v);
	for(i=0;i<v;i++)
	{
		Q[i]=10000;
		path[i]=-1;
		S[i]=0;
	}
	Q[0]=0;
	
	while(Q_len-->0)
	{
		u=extract_min(Q,S,v);
		for(curr=Adj[u];curr!=NULL;curr=curr->next)
		{
			if(S[curr->vertex]!=1&&(curr->weight+Q[u])<Q[curr->vertex])
			{
				Q[curr->vertex]=curr->weight+Q[u];
				path[curr->vertex]=u;
			}
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
	struct adj** A;
	int *pi;
	int v,i;
	printf("enter no. of vertices: ");	
	scanf("%d",&v);
	A=build_adj_list(v);
	dijktra(v,A);
	
	
	
}
