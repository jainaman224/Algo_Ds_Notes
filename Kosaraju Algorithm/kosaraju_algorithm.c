#include <stdio.h>
#include <stdlib.h>

#define MAX_DEG 5
#define MAX_VERTEX 20

struct Graph {
    int visited;
    int deg;
    int adj[MAX_DEG]; /* < 0 if incoming edge */
} vertex[] = {
    {0, 3, {2, -3, 4}},
    {0, 2, {-1, 3}},
    {0, 3, {1, -2, 7}},
    {0, 3, {-1, -5, 6}},
    {0, 2, {4, -7}},
    {0, 3, {-4, 7, -8}},
    {0, 4, {-3, 5, -6, -12}},
    {0, 3, {6, -9, 11}},
    {0, 2, {8, -10}},
    {0, 3, {9, -11, -12}},
    {0, 3, {-8, 10, 12}},
    {0, 3, {7, 10, -11}}
};
int n_vertex = sizeof(vertex) / sizeof(struct Graph);

//struct stk{
//    int top;
//    int items[MAX_VERTEX];
//} stack = {-1, {}};
int top =-1;
int stk[MAX_VERTEX];

void push(int v) 
{
    if (top >= MAX_VERTEX)
       printf("Stack is full!\n");
    else {
	   top++;
	   stk[top] = v;
    }
}

int pop() 
{
    if(top<=-1)
       exit(1);
    else
      return stk[top--] ;
}


void dfs(int v, int trans) {
    int i, c, n;
    vertex[v].visited = 1;
    for (i = 0, c = vertex[v].deg; i < c; ++i)
	 {
	      n = vertex[v].adj[i] * trans;
	  if (n > 0)
	    if (vertex[n - 1].visited == 0)
	     	dfs(n - 1, trans);
     }
    if (trans < 0)
	    push(v);
    else
	   printf("%d ", v + 1);
}

void set_visited() 
{
    int i;
    for (i = 0; i < n_vertex; ++i)
	    vertex[i].visited = 0;
}

void pass() 
{
    int i;
    for (i = 0; i < n_vertex; ++i)
	if (vertex[i].visited == 0)
	    dfs(i, -1);
}

void scc() {
    int i = 0, v;
	while((v = pop())!= -1) {
	if (vertex[v].visited == 0) 
	{
	    printf("Strongly Connected Components : %d: ", ++i);
	    dfs(v, 1);
	    printf("\n");
	    
	}
    }
}

int main() {
    pass();
    set_visited();
    scc();
    return 0;
}
