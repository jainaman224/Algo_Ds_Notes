
// Program to implement Kosaraju Algorithm for Strongly Connected Components
class Graph {
    constructor(nodes) {
        //2 class variables
        this.nodes = nodes; // no of vertices
        this.adj = new Array(nodes); // adjacency list
        for (let i = 0; i < nodes; i++) {
            this.adj[i] = new Array();
        }
    }

    showGraph() {
        const {
            nodes,
            adj
        } = this; // destructuring for clarity

        for (let i = 0; i < nodes; i++) {
            // show graph in readable format
            console.log(`Vertex ${i} is connected to verices `, adj[i]);
        }
    };

    addEdge(x, y) {
        const {
            nodes,
            adj
        } = this;
        // x is connected to y
        adj[x].push(y);
    };

    dfsUtil(arr, start, visited) {
        // utility function of dfs
        const {
            nodes,
            adj
        } = this;

        visited[start] = true;
        arr.push(start);
        for (let x of adj[start]) {
            if (!visited[x]) {
                this.dfsUtil(arr, x, visited);
            }
        }
    };
    //getTranspose function will return a graph
    getTranspose() {
        let gr = new Graph(this.nodes);
        for (let v = 0; v < this.nodes; v++) {
            // Recur for all the vertices adjacent to this vertex 
            let neighNodes = this.adj[v];
            for (let i of neighNodes) {
                gr.adj[i].push(v);
            }
        }
        return gr;
    }

    fillOrder(v, visited, Stack) {
        // Mark the current node as visited and print it 
        visited[v] = true;
        // Recur for all the vertices adjacent to this vertex 

        let neighNodes = this.adj[v];
        for (let i of neighNodes) {
            if (!visited[i])
                this.fillOrder(i, visited, Stack);
        }
        // All vertices reachable from v are processed by now, push v  
        Stack.push(v);
    }

    printSCCs() {
        const {
            nodes,
        } = this;
        let Stack = [];

        // Mark all the vertices as not visited (For first DFS) 
        let visited = new Array(nodes);
        for (let i = 0; i < nodes; i++)
            visited[i] = false;

        // Fill vertices in stack according to their finishing times 
        for (let i = 0; i < nodes; i++)
            if (visited[i] === false)
                this.fillOrder(i, visited, Stack);

        // Create a reversed graph 
        let gr = this.getTranspose();
        // Mark all the vertices as not visited (For second DFS) 
        for (let i = 0; i < nodes; i++)
            visited[i] = false;

        // Now process all vertices in order defined by Stack 
        while (Stack.length) {
            // Pop a vertex from stack 
            let v = Stack[Stack.length - 1];
            Stack.pop();
            // Array used for displaying strongly connected component
            let arr = [];
            // Print Strongly connected component of the popped vertex 
            if (visited[v] == false) {
                gr.dfsUtil(arr, v, visited);
                console.log(arr);
            }
        }
    }
};

// Implementation 
let n = 5; // 5 vertices
let graph = new Graph(n); // initialise the graph

// add edges
graph.addEdge(1, 0);
graph.addEdge(0, 2);
graph.addEdge(2, 1);
graph.addEdge(0, 3);
graph.addEdge(3, 4);

console.log("The Graph is:");
graph.showGraph();
console.log("The Strongly Connected Components by Kosaraju Algorithm are: ");
graph.printSCCs();

// Output:
/*
The Graph is:
Vertex 0 is connected to verices  [ 2, 3 ]
Vertex 1 is connected to verices  [ 0 ]
Vertex 2 is connected to verices  [ 1 ]
Vertex 3 is connected to verices  [ 4 ]
Vertex 4 is connected to verices  []
The Strongly Connected Components by Kosaraju Algorithm are:
[ 0, 1, 2 ]
[ 3 ]
[ 4 ]
*/
