// Javascript Implementation of Kruskals Algorithm

class UnionFind {
    constructor(elements) {
        this.count = elements.length;
        this.parent = {};
        elements.forEach(e => (this.parent[e] = e));
    }

    union(a, b) {
        let rootA = this.find(a);
        let rootB = this.find(b);
        if (rootA === rootB) return;
        if (rootA < rootB) {
            if (this.parent[b] != b) this.union(this.parent[b], a);
            this.parent[b] = this.parent[a];
        } else {
              if (this.parent[a] != a) this.union(this.parent[a], b);
              this.parent[a] = this.parent[b];
          }
    }
   
    find(a) {
        while (this.parent[a] !== a) {
            a = this.parent[a];
        }
        return a;
    }
   
    connected(a, b) {
        return this.find(a) === this.find(b);
    }
}

class PriorityQueue {
    constructor(maxSize) {
        if (isNaN(maxSize)) {
            maxSize = 10;
        }
        this.maxSize = maxSize;
        this.container = [];
    }
   
    isEmpty() {
        return this.container.length === 0;
    }
   
   isFull() {
      return this.container.length >= this.maxSize;
   }
}

PriorityQueue.prototype.Element = class {
    constructor (data, priority) {
        this.data = data; this.priority = priority;
    }
}

function kruskalsMST() {
    const MST = new Graph();
    this.nodes.forEach(node => MST.addNode(node));
    if (this.nodes.length === 0) {
        return MST;
    }

    edgeQueue = new PriorityQueue(this.nodes.length * this.nodes.length);

  
    for (let node in this.edges) {
        this.edges[node].forEach(edge => {
            edgeQueue.enqueue([node, edge.node], edge.weight);
        });
    }

    let uf = new UnionFind(this.nodes);

   
    while (!edgeQueue.isEmpty()) {
        let nextEdge = edgeQueue.dequeue();
        let nodes = nextEdge.data;
        let weight = nextEdge.priority;

        if (!uf.connected(nodes[0], nodes[1])) {
            MST.addEdge(nodes[0], nodes[1], weight);
            uf.union(nodes[0], nodes[1]);
        }
    }
    return MST;
}

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
g.addEdge("E", "G", 50);

g.kruskalsMST().display();

///Sample Input
// let g = new Graph();
// g.addNode("A");
// g.addNode("B");
// g.addNode("C");
// g.addNode("D");
// g.addNode("E");
// g.addNode("F");
// g.addNode("G");

// g.addEdge("A", "C", 100);
// g.addEdge("A", "B", 3);
// g.addEdge("A", "D", 4);
// g.addEdge("C", "D", 3);
// g.addEdge("D", "E", 8);
// g.addEdge("E", "F", 10);
// g.addEdge("B", "G", 9);
// g.addEdge("E", "G", 50);

/// Sample Output
// A->B, D
// B->A, G
// C->D
// D->C, A, E
// E->D, F
// F->E
// G->B
