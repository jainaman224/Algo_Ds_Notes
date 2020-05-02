// Description: Function to perform the Dijkstra algorithm on a weighted graph
// Expected Output: returns the shorted path

// class for new node
class NewNode {
    val: string;
    priority: number;
    constructor(val: string, priority: number) {
        this.val = val;
        this.priority = priority;
    }
}

// class for graph
class WeightedGraph {
    adjacencyList: {};
    constructor() {
        this.adjacencyList = {};
    }
    // function to add vertex on graph
    addVertex = (vertex: string) => {
        if (!this.adjacencyList[vertex]) this.adjacencyList[vertex] = [];
    };

    // function to add weight of the edge between two vertices
    addEdge = (vertex1: string, vertex2: string, weight: number) => {
        this.adjacencyList[vertex1].push({ node: vertex2, weight });
        this.adjacencyList[vertex2].push({ node: vertex1, weight });
    };

    // main function to implement Dijkstra Algorithm from start to end node
    DijkstraFunction = (start: string, finish: string) => {
        const nodes: PriorityQueue = new PriorityQueue();
        const distances = {};
        const previous = {};
        // to return at end
        let path = [];
        let smallest;

        // build up initial state
        for (let vertex in this.adjacencyList) {
            if (vertex === start) {
                distances[vertex] = 0;
                nodes.enqueue(vertex, 0);
            } else {
                distances[vertex] = Infinity;
                nodes.enqueue(vertex, Infinity);
            }
            previous[vertex] = null;
        }

        // as long as there is something to visit, visit the node
        while (nodes.values.length) {
            smallest = nodes.dequeue().val;
            if (smallest === finish) {
                // reached the end , need to form the path now and return
                while (previous[smallest]) {
                    path.push(smallest);
                    smallest = previous[smallest];
                }
                break;
            }

            if (smallest || distances[smallest] !== Infinity) {
                for (let neighbor in this.adjacencyList[smallest]) {
                    // find neighboring node
                    let nextNode = this.adjacencyList[smallest][neighbor];
                    // calculate new distance to neighboring node
                    let candidate = distances[smallest] + nextNode.weight;
                    let nextNeighbor = nextNode.node;
                    if (candidate < distances[nextNeighbor]) {
                        // updating new smallest distance to neighbor
                        distances[nextNeighbor] = candidate;
                        // updating previous - How we got to neighbor
                        previous[nextNeighbor] = smallest;
                        // enqueue in priority queue with new priority
                        nodes.enqueue(nextNeighbor, candidate);
                    }
                }
            }
        }
        return path.concat(smallest).reverse();
    };
}

// class defnition for Priority Queue
class PriorityQueue {
    values: NewNode[];
    constructor() {
        this.values = [];
    }
    enqueue = (val: string, priority: number) => {
        let newNode = new NewNode(val, priority);
        this.values.push(newNode);
        this.bubbleUp();
    };
    bubbleUp = () => {
        let idx: number = this.values.length - 1;
        const element: NewNode = this.values[idx];
        while (idx > 0) {
            let parentIdx: number = Math.floor((idx - 1) / 2);
            let parent: NewNode = this.values[parentIdx];
            if (element.priority >= parent.priority) break;
            this.values[parentIdx] = element;
            this.values[idx] = parent;
            idx = parentIdx;
        }
    };
    dequeue = () => {
        const min: NewNode = this.values[0];
        const end: NewNode = this.values.pop();
        if (this.values.length > 0) {
            this.values[0] = end;
            this.sinkDown();
        }
        return min;
    };
    sinkDown = () => {
        let idx: number = 0;
        const length: number = this.values.length;
        const element: NewNode = this.values[0];
        while (true) {
            let leftChildIdx: number = 2 * idx + 1;
            let rightChildIdx: number = 2 * idx + 2;
            let leftChild: NewNode, rightChild: NewNode;
            let swap: number = null;
            if (leftChildIdx < length) {
                leftChild = this.values[leftChildIdx];
                if (leftChild.priority < element.priority) swap = leftChildIdx;
            }
            if (rightChildIdx < length) {
                rightChild = this.values[rightChildIdx];
                if (
                    (swap === null && rightChild.priority < element.priority) ||
                    (swap !== null && rightChild.priority < leftChild.priority)
                )
                swap = rightChildIdx;
            }
            if (swap === null) break;
            this.values[idx] = this.values[swap];
            this.values[swap] = element;
            idx = swap;
        }
    };
}

function main() {
    const wtdGraph = new WeightedGraph();
    // INPUT WEIGHTED GRAPH
    // adding vertices of the graph
    wtdGraph.addVertex("A");
    wtdGraph.addVertex("B");
    wtdGraph.addVertex("C");
    wtdGraph.addVertex("D");
    wtdGraph.addVertex("E");
    wtdGraph.addVertex("F");
    // addition weight of the edges
    wtdGraph.addEdge("A", "B", 1);
    wtdGraph.addEdge("A", "C", 3);
    wtdGraph.addEdge("B", "E", 2);
    wtdGraph.addEdge("C", "D", 4);
    wtdGraph.addEdge("C", "F", 5);
    wtdGraph.addEdge("D", "E", 3);
    wtdGraph.addEdge("D", "F", 1);
    wtdGraph.addEdge("E", "F", 2);

    // running the algorithm for the ghraph
    const output = wtdGraph.DijkstraFunction("A", "F");
    // OUTPUT OF wtdGraph
    console.log(output); //[ 'A', 'B', 'E', 'F']
}

main();
