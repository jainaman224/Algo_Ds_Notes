   /*The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem.
   The problem is to find shortest distances between every pair of vertices in a given
   edge weighted directed Graph.This is Floyd Warshall algorithm in java script.*/
   class Graph {
       constructor() {
           this.edges = {};
           this.nodes = [];
       }

       addNode(node) {
           this.nodes.push(node);
           this.edges[node] = [];
       }

       addEdge(node1, node2, weight = 1) {
           this.edges[node1].push({ node: node2, weight: weight });
           this.edges[node2].push({ node: node1, weight: weight });
       }
       
       floydWarshallAlgorithm() {
           let dist = {};
           for (let i = 0; i < this.nodes.length; i++) {
               dist[this.nodes[i]] = {};

               // For existing edges assign the dist to be same as weight
               this.edges[this.nodes[i]].forEach(e => (dist[this.nodes[i]][e.node] = e.weight));

               this.nodes.forEach(n => {
                   // For all other nodes assign it to infinity
                   if (dist[this.nodes[i]][n] == undefined)
                       dist[this.nodes[i]][n] = Infinity;
                       // For self edge assign dist to be 0
                       if (this.nodes[i] === n) dist[this.nodes[i]][n] = 0;
              });
           }

           this.nodes.forEach(i => {
               this.nodes.forEach(j => {
                   this.nodes.forEach(k => {
                       // Check if going from i to k then from k to j is better
                       // than directly going from i to j. If yes then update
                       // i to j value to the new value
                       if (dist[i][k] + dist[k][j] < dist[i][j])
                          dist[i][j] = dist[i][k] + dist[k][j];
                   });
                });
            });
            return dist;
        }
    }

    let g = new Graph();

    var edges = prompt("Please enter number of edges", "5");

    var vertices = prompt("Please enter number of vertices", "5");

    for(let i = 0;i < vertices; i++){
        var e=prompt("Please enter vertex name", "A");
        g.addNode(e);
    }

    /*g.addNode("A");
    g.addNode("B");
    g.addNode("C");
    g.addNode("D");*/

    for(let i = 0;i < edges; i++){
        var e1=prompt("Please enter start edge name", "A");
        var e2=prompt("Please enter start edge name", "A");
        var w=prompt("Please enter start edge name", 100);
        g.addEdge(e1, e2, w);
    }

    /*g.addEdge("A", "C", 100);
    g.addEdge("A", "B", 3);
    g.addEdge("A", "D", 4);
    g.addEdge("D", "C", 3);*/

    console.log(g.floydWarshallAlgorithm());

    /* output : 
    A: {C: 7, B: 3, D: 4, A: 0}
    B: {A: 3, B: 0, C: 10, D: 7}
    C: {A: 7, D: 3, B: 10, C: 0}
    D: {A: 4, C: 3, B: 7, D: 0}*/

