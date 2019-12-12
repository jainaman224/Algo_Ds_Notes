//prims mst
//heap implementation
#include<stdio.h>
#include<stdlib.h>


//building adjacency list
void swap_int(int* a,int* b)
{
	int temp;
	temp=(*a);
	(*a)=(*b);
	(*b)=temp;
}
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

//priority queue
struct heap
{
	int vertex;
	int key;
	
};
void swap(struct heap* a,struct heap* b)
{
	struct heap temp;
	temp=(*a);
	(*a)=(*b);
	(*b)=temp;
}
void min_heapify(struct heap* a,int *Q,int i,int n)
{
	
	if(((2*i+2)>=n)||((2*i+1)>=n))
	{
		return;
	}
	
	if(a[2*i+1].key<a[2*i+2].key)
	{
		if(a[2*i+1].key<a[i].key)
		{
			swap_int(&Q[a[2*i+1].vertex],&Q[a[i].vertex]);
			swap(&a[2*i+1],&a[i]);
			min_heapify(a,Q,2*i+1,n);
		}
	}
	else
	{
		if(a[2*i+2].key<a[i].key)
		{
			swap_int(&Q[a[2*i+2].vertex],&Q[a[i].vertex]);
			swap(&a[2*i+2],&a[i]);
			min_heapify(a,Q,2*i+2,n);
		}
		
	}
	
	
}


int extract_min(struct heap *a,int* Q,int n)
{
	struct heap temp=a[0];
	int min=a[0].key;
	Q[a[0].vertex]=9999;
	Q[a[n-1].vertex]=0;
	
	swap(&a[0],&a[n-1]);
	
	min_heapify(a,Q,0,n-1);
	
	return temp.vertex;
}




void update(struct heap* min_heap,int* Q,int v)
{
	int iv=Q[v];
	int parent_iv=(iv-1)/2;
	if(parent_iv<0)
	{
		return;
	}
	int parent_v=min_heap[parent_iv].vertex;
	
	if(min_heap[parent_iv].key>min_heap[iv].key)
	{	
		swap_int(&Q[parent_v],&Q[v]);
		swap(&min_heap[parent_iv],&min_heap[iv]);
		update(min_heap,Q,v);
	}
	else
	{
		return;
	}
}
int* prim(int v, struct adj** Adj)//0th vertex is source
{
	int *Q;
	int i,u;
	int *pi;
	int heap_len=v;
	struct adj *curr;  
	Q=(int *)malloc(sizeof(int)*v);//stores index of vertex v in min_heap
	struct heap* min_heap=(struct heap*)malloc(sizeof(struct heap)*v);
	
	pi=(int *)malloc(sizeof(int)*v);
	for(i=0;i<v;i++)
	{
		Q[i]=i;
		pi[i]=99999;
		min_heap[i].vertex=i;
		min_heap[i].key=10000;
	}
	min_heap[0].key=0;
	
	
	while(heap_len-->0)
	{
		
		u=extract_min(min_heap,Q,heap_len+1);
		
		for(curr=Adj[u];curr!=NULL;curr=curr->next)
		{
			
			int iv=Q[curr->vertex];//iv is index of v in min-heap
			
			
			if(iv!=9999&&curr->weight<min_heap[iv].key)
			{
				
				min_heap[iv].key=curr->weight;
				update(min_heap,Q,curr->vertex);//update function -> T-decrease-key
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
