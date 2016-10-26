#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maximun 10000000

struct eddges
{
    int my_source, my_destination, edge_weights;
};
struct MST
{   int V, E;  
    struct eddges* edge;
};
struct subset
{   int parent;  int rank;
};
struct MST* forming_graph_MST(int V, int E)
{
    struct MST* graph = (struct MST*) malloc( sizeof(struct MST) );
    graph->V = V;  graph->E = E;
    graph->edge = (struct eddges*) malloc( graph->E * sizeof( struct eddges ) );
    return graph;
}

void mg_sort(int arr[],int low,int mid,int high);
void sort11_merge(int arr[],int low,int high);
void mg_sort(int arr[],int low,int mid,int high)
{    int i,m,k,l,temporary[maximun];

    l=low; i=low;  m=mid+1;
//printf("Booooo!!!!\n");
    while((l<=mid)&&(m<=high))
    {         if(arr[l]<=arr[m]){
             temporary[i]=arr[l];

             //printf("Booooo!!!!\n");
             l++;
}
         else{  temporary[i]=arr[m];
             m++;
         }i++;
         //printf("Booooo!!!!\n");
    }
    if(l>mid)
    {
         for(k=m;k<=high;k++){
            //printf("Booooo!!!!\n");
             temporary[i]=arr[k];  i++;
         }
    }
    else
    {
         for(k=l;k<=mid;k++){  temporary[i]=arr[k];
             //printf("Booooo!!!!\n");
             i++;
    }
    }
    for(k=low;k<=high;k++)
    {  arr[k]=temporary[k];
        //printf("Booooo!!!!\n");
    }
}
void sort11_merge(int arr[],int low,int high)
{
    int mid;
    if(low<high){
         mid=(low+high)/2;
         sort11_merge(arr,low,mid);
         //printf("Booooo!!!!\n");
         sort11_merge(arr,mid+1,high);
         //printf("Booooo!!!!\n");
         mg_sort(arr,low,mid,high);
    }
}
int searching(struct subset subsets[], int i);
void finding_union(struct subset subsets[], int x, int y);
int HSS(const void* a, const void* b);
int MST_algorithm(struct MST* graph)
{
    int v;
    int V = graph->V;  struct eddges result[V];  
    int e = 0;  int i = 0; 
    //printf("Booooo!!!!\n");
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), HSS);
    struct subset *subsets = (struct subset*) malloc( V * sizeof(struct subset) );
    //printf("Booooo!!!!\n");
    for (v = 0; v < V; ++v)
    { subsets[v].parent = v;subsets[v].rank = 0;
    }
    //printf("Booooo!!!!\n");
    while (e < V - 1)
    {         struct eddges next_edge = graph->edge[i++];   int x = searching(subsets, next_edge.my_source);
        int y = searching(subsets, next_edge.my_destination);
       if (x != y)
        {   result[e++] = next_edge;  finding_union(subsets, x, y);
            //printf("Booooo!!!!\n");
        }      
    }
    int sum=0;
    //printf("Booooo!!!!\n");
    for (i = 0; i < e; ++i)
        sum+=result[i].edge_weights; 
        //printf("Booooo!!!!\n");                                                                              
    return sum;
}
int main()
{
    int n,r1,r2,p,q,c;
    scanf("%d %d %d", &n,&r1,&r2);
    struct MST* graphtwo = forming_graph_MST(n, r1+r2);  struct MST* graphfour = forming_graph_MST(n, r2);
    int i;
    for(i=0;i<r1;i++)
    {
        //printf("Booooo!!!!\n");
        scanf("%d %d %d", &p,&q,&c);
        graphtwo->edge[i].my_source = p-1;   graphtwo->edge[i].my_destination = q-1;  graphtwo->edge[i].edge_weights = c;
        //printf("Booooo!!!!\n");

    }
    int j;
      for(j=0;j<r2;j++)
    {
        scanf("%d %d %d", &p,&q,&c);
        graphtwo->edge[i+j].my_source = p-1;  graphtwo->edge[i+j].my_destination = q-1;  graphtwo->edge[i+j].edge_weights = c;
        //printf("Booooo!!!!\n");
        graphfour->edge[j].my_source = p-1; graphfour->edge[j].my_destination = q-1;
        //printf("Booooo!!!!\n");
        graphfour->edge[j].edge_weights = c;
    }
    int sum1=MST_algorithm(graphtwo);
    //printf("Booooo!!!!\n");
     int sum2=MST_algorithm(graphfour);
     //printf("Booooo!!!!\n");
     printf("%d %d\n", sum1,sum2);

    return 0;
}
void finding_union(struct subset subsets[], int x, int y)
{
    int xroot = searching(subsets, x);    int yroot = searching(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    //printf("Booooo!!!!\n");
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    //printf("Booooo!!!!\n");
   else
    {
        subsets[yroot].parent = xroot;        subsets[xroot].rank++;
        //printf("Booooo!!!!\n");
    }
}
int HSS(const void* a, const void* b)
{
    struct eddges* a1 = (struct eddges*)a;
    //printf("Booooo!!!!\n");
    struct eddges* b1 = (struct eddges*)b;
    return a1->edge_weights > b1->edge_weights;
    //printf("Booooo!!!!\n");
}
int searching(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = searching(subsets, subsets[i].parent);
    return subsets[i].parent;
    //printf("Booooo!!!!\n");
}
