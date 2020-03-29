// Program to implement Topological Sort
class Graph {
    constructor(nodes) {
        //2 class variables
        this.nodes = nodes; // no of vertices
        this.adj = new Array(nodes); // adjacency list
        for (let i = 0; i < nodes; i++) {
            this.adj[i] = new Array();
        }
        this.stack = []; // a stack for storing the ending times of dfs
    }

    showGraph = () => {
        const {
            nodes,
            adj
        } = this; // destructuring for clarity

        for (let i = 0; i < nodes; i++) {
            // show graph in readable format
            console.log(`Vertex ${i} is connected to verices `, adj[i]);
        }
    };

    addEdge = (x, y) => {
        const {
            nodes,
            adj
        } = this;
        // x is connected to y
        adj[x].push(y);
    };

    topoSort = () => {
        const {
            nodes,
            adj
        } = this;

        let visited = new Array(nodes); // visited array
        for (let i = 0; i < nodes; i++) visited[i] = false;

        for (let i = 0; i < nodes; i++)
            if (!visited[i]) this.topoUtil(i, visited);
    };

    topoUtil = (start, visited) => {
        // utility function of topoSort
        const {
            nodes,
            adj
        } = this;

        visited[start] = true;

        for (let x of adj[start]) {
            if (!visited[x]) {
                this.topoUtil(x, visited);
            }
        }

        this.stack.push(start); // push the node when we have completed it
    };
}

// implement
let n = 6; // 6 vertices
let graph = new Graph(n); // initialise the graph

// add edges
graph.addEdge(5, 2);
graph.addEdge(5, 0);
graph.addEdge(4, 0);
graph.addEdge(4, 1);
graph.addEdge(2, 3);
graph.addEdge(3, 1);

console.log("The Graph is:");
graph.showGraph();

graph.topoSort();
console.log(`The Topological sort is `, graph.stack.reverse());

// Output:
// The Graph is:
// Vertex 0 is connected to verices  []
// Vertex 1 is connected to verices  []
// Vertex 2 is connected to verices  [ 3 ]
// Vertex 3 is connected to verices  [ 1 ]
// Vertex 4 is connected to verices  [ 0, 1 ]
// Vertex 5 is connected to verices  [ 2, 0 ]
// The topological sort is  [ 5, 4, 2, 3, 1, 0 ]
