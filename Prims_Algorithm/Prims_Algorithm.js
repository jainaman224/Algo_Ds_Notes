/* Prim's algorithm is used to find minimum cost spanning tree (MST). It uses the greedy approach. */

// Represents a weighted edge from first to second
var Edge = function(first, second, weight) {
    this.first = first;
    this.second = second;
    this.weight = weight;
};

// To create graph
var Graph = function() {
    this.vertices = [];
    this.edges = {};
    
    // Add a node to the graph
    this.addVertex = function(vertex) {
        this.vertices.push(vertex);
        this.edges[vertex] = [];
    };

    // Add a weighted edge from first to second
    this.addEdge = function(first, second, weight) {    
        this.edges[first].push(new Edge(first, second, weight));
        this.edges[second].push(new Edge(second, first, weight));
    };
};

// To get nearest vertex to visited vertices
function getMinVertex(g, result, visitedVertices) {
    var min = [Infinity , null];
    for(var i = 0; i < result.length; i++) 
        for(var j = 0; j < g.edges[result[i]].length; j++) 
            if(g.edges[result[i]][j].weight < min[0] && visitedVertices[g.edges[result[i]][j].second] === undefined)
                min = [g.edges[result[i]][j].weight, g.edges[result[i]][j].second];
    return min[1];
}

// To perform Prim's algorithm
function Prims(g) {
    var result = [];
    var visitedVertices = {};
    
    // Start from node 0
    var start = g.vertices[0];
    result.push(start);
    visitedVertices[start] = true;
    
    var min = getMinVertex(g, result, visitedVertices);
    while(min != null) {
        result.push(min);
        visitedVertices[min] = true;
        min = getMinVertex(g, result, visitedVertices);
    }
    
    return result;
};

var g = new Graph();

// Vertices for the graph - Sample Input
g.addVertex(0);
g.addVertex(1);
g.addVertex(2);
g.addVertex(3);

// Weighted edges for the graph - Sample Input
g.addEdge(0, 1, 3);
g.addEdge(1, 3, 1);
g.addEdge(1, 2, 5);
g.addEdge(2, 3, 8);

var result = Prims(g);
console.log("Order in which vertices are visited during the implementation of Prim's Algorithm: ")
console.log(result);

/*
    Sample Input is as taken in the code.
    Sample Output:
    Order in which vertices are visited during the implementation of Prim's Algorithm:
    0,1,3,2
*/
