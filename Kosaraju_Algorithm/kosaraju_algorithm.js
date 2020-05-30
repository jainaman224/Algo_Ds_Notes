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
    //A function to print graph in readable format
    showGraph() {
        const {
            nodes,
            adj
        } = this; // destructuring for clarity

        for (let i = 0; i < nodes; i++) {
            console.log(`Vertex ${i} is connected to verices `, adj[i]);
        }
    };
    //Create Graph by adding edge between the nodes
    addEdge(x, y) {
        const {
            nodes,
            adj
        } = this;
        // x is connected to y 
        // Directed Graph
        adj[x].push(y);
    };
    // Recursive function to visit neighbouring nodes
    dfsHelper(arr, start, visited) {
        const {
            nodes,
            adj
        } = this;

        visited[start] = true;
        arr.push(start);
        for (let x of adj[start]) {
            if (!visited[x]) {
                this.dfsHelper(arr, x, visited);
            }
        }
    };
    //A function which will return transpose of a graph
    transposeGraph() {
        const gr = new Graph(this.nodes);
        for (let v = 0; v < this.nodes; v++) {
            // Reverse the edges of each node
            let neighNodes = this.adj[v];
            for (let i of neighNodes) {
                gr.adj[i].push(v);
            }
        }
        return gr;
    };
    // A Function to create stack in order to process nodes in DFS
    // Stack will be created according to the finish time of node
    // The node with maximum finish time will be at the top of stack
    createStackOrder(v, visited, Stack) {
        // Current node marked as visited
        visited[v] = true;

        let neighNodes = this.adj[v];
        for (let i of neighNodes) {
            if (!visited[i])
                this.createStackOrder(i, visited, Stack);
        }
        // All the nodes reachable by v has been traversed, pushing vertix 'v' 
        Stack.push(v);
    };
    // A Function to print strongly connected components in a graph
    stronglyConnectedComponents() {
        const {
            nodes,
        } = this;
        let Stack = [];
        // All the values by default are undefined in JavaScript
        // Therefore creating a visited array and marking all the nodes as not visited. 
        let visited = new Array(nodes);
        for (let i = 0; i < nodes; i++)
            visited[i] = false;

        // Creating order of stack in which the nodes will be processed 
        for (let i = 0; i < nodes; i++)
            if (visited[i] === false)
                this.createStackOrder(i, visited, Stack);

        // Create a reverse graph 
        let gr = this.transposeGraph();

        // Now to perform DFS on transpose graph unmark all the visited nodes 
        for (let i = 0; i < nodes; i++)
            visited[i] = false;

        // Performing DFS by poping each node from stack as start node, if it is not visited.
        while (Stack.length) {
            // Pop a vertex from stack 
            let n = Stack[Stack.length - 1];
            Stack.pop();
            // Array used for displaying strongly connected component in each line separately
            let arr = [];
            // Strongly connected component of node n
            if (visited[n] == false) {
                gr.dfsHelper(arr, n, visited);
                console.log(arr);
            }
        }
    }
};

// Implementation 
let n = 7; // 7 vertices
let graph = new Graph(n); // initialise the graph

// add edges
graph.addEdge(1, 0);
graph.addEdge(0, 2);
graph.addEdge(2, 1);
graph.addEdge(0, 3);
graph.addEdge(3, 4);
graph.addEdge(4, 5);
graph.addEdge(5, 3);
graph.addEdge(5, 6);

console.log("The Graph is:");
graph.showGraph();
console.log("The Strongly Connected Components by Kosaraju Algorithm are: ");
graph.stronglyConnectedComponents();

// Output:
/*
The Graph is:
Vertex 0 is connected to verices  [ 2, 3 ]
Vertex 1 is connected to verices  [ 0 ]
Vertex 2 is connected to verices  [ 1 ]
Vertex 3 is connected to verices  [ 4 ]
Vertex 4 is connected to verices  [ 5 ]
Vertex 5 is connected to verices  [ 3, 6 ]
Vertex 6 is connected to verices  []
The Strongly Connected Components by Kosaraju Algorithm are:
[ 0, 1, 2 ]
[ 3, 5, 4 ]
[ 6 ]
*/
