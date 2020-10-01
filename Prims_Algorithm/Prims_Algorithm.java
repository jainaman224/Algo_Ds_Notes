/* Prim's algorithm is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph. This means it finds a subset of the edges that forms a tree that includes every vertex, where the total weight of all the edges in the tree is minimized.*/
import java.util.*;

// Class Edge to hold properties of edge
class Edge
{
    int from;
    int to;
    double weight;
    Edge(int u, int v, double w)
    {
        this.from = u;
        this.to = v;
        this.weight = w;
    }
}

class Prims
{
    // Function to compute MST
    public static ArrayList<Edge> prims(ArrayList<ArrayList<Edge>> graph)
    {
        // ArrayList to store obtained MST
        ArrayList<Edge> MST = new ArrayList<>();

        // Priority Queue which gives minimum weight edge
        PriorityQueue<Edge> pq = new PriorityQueue<>((Edge edge1, Edge edge2) -> 
        {
            if (edge1.weight < edge2.weight)
                return -1;
            else if(edge1.weight > edge2.weight)
                return 1;
            else
                return 0;
        });

        // add the source vertex in Priority queue
        for(Edge vertex:graph.get(0))
            pq.add(vertex);

        double cost = 0;
        int size = graph.size();
        boolean[] visited = new boolean[size];
        // mark source vertex as visited
        visited[0] = true;
        // Keep extracting edges till priority is not empty
        while(!pq.isEmpty())
        {
            // extract edge with minimum weight from priority queue
            Edge edge = pq.peek();
            // pop the edge from priority queue
            pq.poll();
            if (visited[edge.to] && visited[edge.from])
                continue;
            // mark the from vertex as visited
            visited[edge.from] = true;  
            for(Edge edge1:graph.get(edge.to))
            {
            // if the adjacent vertex to source is unvisited, add the edge to the priority queue
                if(!visited[edge1.to])
                    pq.add(edge1);
            }
            // mark the adjacent vertex as visited
            visited[edge.to] = true; 
            // add the edge in minimum spanning tree
            cost = cost + edge.weight;
            MST.add(edge);
        }
        System.out.println("Total cost of MST: "+cost);
        return MST;
    }
    
    // Function to create adjacency list representation of graph
    public static ArrayList<ArrayList<Edge>> createGraph(Edge[] edges, int nodes)
    {
        // initialise graph as Adjacency List
        ArrayList<ArrayList<Edge>> graph = new ArrayList<>();
        // for adding Arraylist to Arraylist
        for(int i=0; i<nodes; i++)
            graph.add(new ArrayList<>());
           
        // Create adjacency list from the edge connectivity information
        for(Edge source:edges) {
            Edge destination = new Edge(source.from, source.to, source.weight);
            graph.get(source.from).add(source);
            graph.get(source.to).add(destination);
        }
        // Return constructed graph
        return graph; 
    }

    // Driver Function
    public static void main(String[] args)
    {
        // initialise number of nodes and edges
        int nodes = 7;
        int count_edges = 10;
        /* Input Graph is:   
                0
              /  \
            /      \
           1 ------  2
          / \       /  \
         3 -- 4 -- 5 -- 6        
        */
        Edge[] edges = new Edge[count_edges];
        // initialising edges with from, to and weight value
        edges[0] = new Edge(0, 1, 10);
        edges[1] = new Edge(0, 2, 15);
        edges[2] = new Edge(1, 2, 7);
        edges[3] = new Edge(2, 5, 6);
        edges[4] = new Edge(1, 3, 12);
        edges[5] = new Edge(1, 4, 9);
        edges[6] = new Edge(4, 5, 14);
        edges[7] = new Edge(3, 4, 13);
        edges[8] = new Edge(5, 6, 8);
        edges[9] = new Edge(2, 6, 12);

        // Adjacency List representation of graph
        ArrayList<ArrayList<Edge>> graph = createGraph(edges, nodes);
        // ArrayList to store final MST obtained
        ArrayList<Edge> MST = prims(graph);
        System.out.println("Minimum Spanning Tree:");
        for(Edge edge:MST)
            System.out.println(edge.from+" - "+edge.to+" : "+edge.weight);
    }
}

/*
Output:
Total cost: 52.0
Minimum Spanning Tree:
0 - 1 : 10.0
1 - 2 : 7.0
2 - 5 : 6.0
5 - 6 : 8.0
1 - 4 : 9.0
1 - 3 : 12.0
*/
