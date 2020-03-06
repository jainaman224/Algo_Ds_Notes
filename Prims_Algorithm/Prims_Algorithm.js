primsMST() {
   // Initialize graph that'll contain the MST
   const MST = new Graph();
   if (this.nodes.length === 0) {
      return MST;
   }


   // Select first node as starting node
   let s = this.nodes[0];


   // Create a Priority Queue and explored set
   let edgeQueue = new PriorityQueue(this.nodes.length * this.nodes.length);
   let explored = new Set();
   explored.add(s);
   MST.addNode(s);


   // Add all edges from this starting node to the PQ taking weights as priority
   this.edges[s].forEach(edge => {
      edgeQueue.enqueue([s, edge.node], edge.weight);
   });


   // Take the smallest edge and add that to the new graph
   let currentMinEdge = edgeQueue.dequeue();
   while (!edgeQueue.isEmpty()) {


      // COntinue removing edges till we get an edge with an unexplored node
      while (!edgeQueue.isEmpty() && explored.has(currentMinEdge.data[1])) {
         currentMinEdge = edgeQueue.dequeue();
      }
      let nextNode = currentMinEdge.data[1];


      // Check again as queue might get empty without giving back unexplored element
      if (!explored.has(nextNode)) {
         MST.addNode(nextNode);
         MST.addEdge(currentMinEdge.data[0], nextNode, currentMinEdge.priority);
         // Again add all edges to the PQ
         this.edges[nextNode].forEach(edge => {
            edgeQueue.enqueue([nextNode, edge.node], edge.weight);
         });


         // Mark this node as explored explored.add(nextNode);
         s = nextNode;
      }
   }
   return MST;
}

/* Sample INPUT:
let g = new Graph();
g.addNode("A");
g.addNode("B");
g.addNode("C");
g.addNode("D");
g.addNode("E");
g.addNode("F");
g.addNode("G");


g.addEdge("A", "C", 100);
g.addEdge("A", "B", 3);
g.addEdge("A", "D", 4);
g.addEdge("C", "D", 3);
g.addEdge("D", "E", 8);
g.addEdge("E", "F", 10);
g.addEdge("B", "G", 9);
g.primsMST().display();
*/

/* Sample Output:
A->B, D
B->A, G
D->A, C, E
C->D
E->D, F
G->B
F->E
*/

