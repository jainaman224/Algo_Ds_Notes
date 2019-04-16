#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Graph {
	int numVertex;
	vector<int> *adj;

	public:
		// Constructor to initialise graph
		Graph(int numVertex) {
			this->numVertex = numVertex;
			adj = new vector<int> [numVertex];
		}

		// Function to add edge between source and destination
		void addEdge(int src, int dest) {
			adj[src].push_back(dest);
		}
		void topologicalSort();
		void topologicalSortUtil(int vertex, vector<bool> &visited, stack<int> &Stack);
};

void Graph::topologicalSortUtil(int vertex, vector<bool> &visited, stack<int> &Stack) {
	visited[vertex] = true;

	for(int i = 0; i < adj[vertex].size(); i++) {
		if(!visited[adj[vertex][i]]) {
			topologicalSortUtil(adj[vertex][i], visited, Stack);
		}
	}

	Stack.push(vertex);
}

void Graph::topologicalSort() {
	stack<int> Stack;

	vector<bool> visited(numVertex, false);
	for(int i = 0; i < numVertex; i++) {
		if(!visited[i]) {
			topologicalSortUtil(i, visited, Stack);
		}
	}

	while(!Stack.empty()) {
		cout << Stack.top() << " ";
		Stack.pop();
	}
}

int main() {
	Graph graph(6);
	graph.addEdge(5, 2);
	graph.addEdge(5, 0);
	graph.addEdge(4, 0);
	graph.addEdge(4, 1);
	graph.addEdge(2, 3);
	graph.addEdge(3, 1);

	cout << "Topological Sort: ";
	graph.topologicalSort();

	return 0;
}

/* Output
  Topological Sort: 5 4 2 3 1 0
*/
