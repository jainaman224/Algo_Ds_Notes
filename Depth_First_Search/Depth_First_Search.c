#include <stdio.h>
#include<stdbool.h>

#define STACK_SIZE 20
#define MAX 20

void dfs(int Adj[][MAX], int n, int source);

int main(void) {
	//Adjacency matrix
	int Adj[][MAX] = {
		{0,1,0,0},
		{0,1,1,1},
		{1,0,0,1},
		{0,0,1,0}
	};
	
	int n = 4;	//Number of Vertex
	int starting_vertex = 3;
	
	dfs(Adj, n, starting_vertex);
	
	return 0;
}

//DFS Function
void dfs(int Adj[][MAX], int n, int source) {

	int i, j;
	bool change = false;
	int visited[MAX];
	int tos = 0; //top of stack
	int stack[STACK_SIZE];
	
	for(i = 0; i < MAX; i++) {
		visited[i] = 0;
	}

	visited[source] = 1;
	stack[tos] = source;
	printf("%d ", source);
	
	while(tos >= 0) {
		change = false;
		i = stack[tos];
		for(j = 0; j < n; j++) {
			if(visited[j] == 0 && Adj[i][j] == 1) {
				visited[j] = 1;
				tos++;
				stack[tos] = j;
				
				printf("%d ", j);
				
				change = true;
				break;
			}
		}
		if(change == false) {
			tos--;
		}
	}
	printf("\n");
}
/* Output

Depth First Traversal is : 3 2 0 1

*/
