//+++++++++++++++Utility+++++++++++++++++
//Queue Data Structure implemented 
function Queue() {
    this.elements = [];
 }
 Queue.prototype.enqueue = function (e) {
    this.elements.push(e);
 };
 // remove an element from the front of the queue
Queue.prototype.dequeue = function () {
    return this.elements.shift();
};
// check if the queue is empty
Queue.prototype.isEmpty = function () {
    return this.elements.length == 0;
};
// get the element at the front of the queue
Queue.prototype.peek = function () {
    return !this.isEmpty() ? this.elements[0] : undefined;
};
Queue.prototype.length = function() {
    return this.elements.length;
}

//++++++++++++++++++++++++++++++++++++++++++
//Function to do breadth first search in graph 
function bfs(reducedGraph, source, sink, path, V)
{
    //array to store if the node is visited or not 
    var visited = [V];
    //intially no node is visited 
    for (var i = 0; i < V; i++)
        visited[i] = false;
    let q = new Queue();
    //Starting from source
    q.enqueue(source);
    visited[source] = true;
    //parent of starting node will be nothing hence -1 is stored in it
    path[source] = -1;

    while (!q.isEmpty())
    {
        var u = q.peek();
        q.dequeue();
        for(var v = 0; v < V; v++)
        {
            if(visited[v] === false && reducedGraph[u][v] > 0)
            {
                q.enqueue(v);
                path[v] = u;
                visited[v] = true;
            }
        }
    }
    //If there exist path from source to sink then it will return true else false
    return (visited[sink] === true);
}

function fordFulkerson(graph,source,sink,V)
{
    //reducedGraph is used to store the remaining capacity. reducedGraph[i][j] 
    //indicates remaining capacity of edge from i to jif edge exists.
    var reducedGraph = [];
    for( var i = 0; i < V; i++)
    {
        reducedGraph[i] = [];
        for(var j = 0; j < V; j++)
        {
            reducedGraph[i][j] = graph[i][j];
        }
    }
    //Path is used to store parent  
    var path = [V];
    //variable to store maximum flow in the path chosen
    var max_flow = 0;
    while (bfs(reducedGraph, source, sink, path, V))
    {
        var path_flow = Number.MAX_VALUE;
        //Finding maximum flow in the path selected
        for(var v = sink; v != source; v = path[v])
        {
            var u = path[v];
            path_flow = Math.min( path_flow, reducedGraph[u][v]);
        }
        //Updating remaining capacity odf the edges
        for( var v = sink ; v != source; v = path[v])
        {
            var u = path[v];
            reducedGraph[u][v] -= path_flow;
            reducedGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}
//Used synchronous readline package to take console input 
var readlineSync = require('readline-sync');
//Input number of nodes in a graph
var V = readlineSync.question('Enter number of nodes in a graph: ');
//Input the weight matrix for the directed graph

var graph = [];
for(var i = 0; i < V; i++)
{
    graph[i] = [];
    for(var j = 0; j < V; j++)
    {
        console.log(`Enter the weight form ` , i , `to `,j, `: `);
        var a = readlineSync.question();
        graph[i][j] = a;
    }
}
var source = readlineSync.question("Enter source: ");
var sink = readlineSync.question("Enter Sink: ");
var ans = fordFulkerson(graph,source,sink,V);
console.log('Maximum flow from source to sink is: ', ans);
/*Input1:
V = 6
graph = [ [0, 16, 13, 0, 0, 0], 
        [0, 0, 10, 12, 0, 0], 
        [0, 4, 0, 0, 14, 0], 
        [0, 0, 9, 0, 0, 20], 
        [0, 0, 0, 7, 0, 4], 
        [0, 0, 0, 0, 0, 0] 
      ];
source = 0 sink = 5
Output1: 23

Input2:
V = 6
graph = [ [0, 10, 0, 3, 0, 0], 
        [0, 0, 8, 2, 0, 0], 
        [0, 0, 0, 0, , 10], 
        [0, 0, 6, 0, 7, 0], 
        [0, 0, 0, 0, 10, 0], 
        [0, 0, 0, 0, 0, 0] 
      ];
source = 0
sink = 5
Output2: 10
*/

