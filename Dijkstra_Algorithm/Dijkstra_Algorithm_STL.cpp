/* Amit Bansal - amitbansal7 */
#include <bits/stdc++.h>
using namespace std;

//Dijkstra's Algorithm for single source shortest paths using STL
//adjacency list implementation.

void printpath(int parent[],int v)
{
	//recursive function to print path.
	if(parent[v] == v)
		return;

	printpath(parent,parent[v]);
	printf("%d->",parent[v]);
}

void addEdge(vector<pair<int,int> >adj[], int src,int dest, int w)
{
	//Undirected Graph
	adj[src].push_back(make_pair(dest,w));
	adj[dest].push_back(make_pair(src,w));
}

void Dijkstra(vector <pair<int, int> >adj[],int src,int v)
{
	priority_queue< pair<int, int>, vector<pair<int,int> >,greater<pair<int, int> > > pq;
	//Using priority Queue to implement Min Heap.

	vector<int >dist(v,INF);
	int parent[v];
	parent[src] = src;

	pq.push(make_pair(0,src));
	dist[src] = 0;

	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		vector <pair<int,int> >::iterator it;

		for(it = adj[u].begin(); it != adj[u].end(); it++)
		{
			int v = (*it).first;
			int w = (*it).second;

			if(dist[v] > dist[u] + w)
			{
				dist[v] = dist[u]+w;
				pq.push(make_pair(dist[v],v));
				parent[v] = u;
			}
		}
	}

	printf("Vertex   distance from  %d       Path\n",src);
	for(int i=0;i<v;i++)
	{
		printf("%d \t\t%d  \t\t",i,dist[i]);
		printpath(parent,i);
		printf("%d \n",i);
	}
}

int main(int argc, char const *argv[])
{
	int v = 9;
	vector <pair <int, int> >adj[v];

	/* 
		Using array of vectors to represent vertices.

		for example

		vector[0] contains two pairs (4,1) and (8,7)
		weight of vertex is added as a first element of a pair 
		as by default min heap uses first element for comparison.

		0,7,1 are three vertex.
		4 is weight of vertex from 0 to 1
		and 8 is weight of vertex from 0 to 7


            0
          4/ \ 8
          /   \
         1    7

	*/



	addEdge(adj,0, 1, 4);
    addEdge(adj,0, 7, 8);
    addEdge(adj,1, 2, 8);
    addEdge(adj,1, 7, 11);
    addEdge(adj,2, 3, 7);
    addEdge(adj,2, 8, 2);
    addEdge(adj,2, 5, 4);
    addEdge(adj,3, 4, 9);
    addEdge(adj,3, 5, 14);
    addEdge(adj,4, 5, 10);
    addEdge(adj,5, 6, 2);
    addEdge(adj,6, 7, 1);
    addEdge(adj,6, 8, 6);
    addEdge(adj,7, 8, 7);
	
	Dijkstra(adj,1,v);


	/*
	output

           Vertex   distance from  1       Path
                0 		       4  		   1->0 
                1 		       0  		   1 
                2 		       8  		   1->2 
                3 		       15  		   1->2->3 
                4 		       22  		   1->2->5->4 
                5 		       12  		   1->2->5 
                6 		       12  		   1->7->6 
                7 		       11  		   1->7 
                8 		       10  		   1->2->8
	*/

	return 0;
}