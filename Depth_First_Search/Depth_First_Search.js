// Program to implement Depth First Search
class Graph {
    constructor(nodes) {
        //2 class variables
        this.nodes = nodes; // no of vertices
        this.adj = new Array(nodes); // adjacency list
        for (let i = 0; i < nodes; i++) {
            this.adj[i] = new Array();
        }
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

    dfs = start => {
        const {
            nodes,
            adj
        } = this;

        let visited = new Array(nodes); // visited array
        for (let i = 0; i < nodes; i++) visited[i] = false;

        for (let i = 0; i < nodes; i++)
            if (!visited[i]) this.dfsUtil(i, visited);
    };

    dfsUtil = (start, visited) => {
        // utility function of dfs
        const {
            nodes,
            adj
        } = this;

        visited[start] = true;
        console.log(start);

        for (let x of adj[start]) {
            if (!visited[x]) {
                this.dfsUtil(x, visited);
            }
        }
    };
}

// implement
let n = 8; // 8 vertices
let graph = new Graph(n); // initialise the graph

// add edges
graph.addEdge(0, 1);
graph.addEdge(0, 2);
graph.addEdge(1, 2);
graph.addEdge(1, 4);
graph.addEdge(2, 0);
graph.addEdge(2, 3);
graph.addEdge(3, 3);
graph.addEdge(3, 6);
graph.addEdge(4, 0);
graph.addEdge(4, 5);
graph.addEdge(5, 6);
graph.addEdge(5, 7);
graph.addEdge(6, 2);
graph.addEdge(7, 3);

console.log("The Graph is:");
graph.showGraph();
console.log("The DFS Traversal is: ");
graph.dfs(0); // start from node 0

// Output:
// The Graph is:
// Vertex 0 is connected to verices  [ 1, 2 ]
// Vertex 1 is connected to verices  [ 2, 4 ]
// Vertex 2 is connected to verices  [ 0, 3 ]
// Vertex 3 is connected to verices  [ 3, 6 ]
// Vertex 4 is connected to verices  [ 0, 5 ]
// Vertex 5 is connected to verices  [ 6, 7 ]
// Vertex 6 is connected to verices  [ 2 ]
// Vertex 7 is connected to verices  [ 3 ]
// The DFS Traversal is:
// 0
// 1
// 2
// 3
// 6
// 4
// 5
// 7
