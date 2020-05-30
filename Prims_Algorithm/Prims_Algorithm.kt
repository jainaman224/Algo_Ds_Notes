import java.util.*
internal class Edge(var from: Int, var to: Int, var weight: Int)

internal object Prims {
    /**
     * Function to compute MST
     *
     * @param graph
     * @return mst
     */
    private fun prims(graph: ArrayList<ArrayList<Edge?>>): ArrayList<Edge?> { // ArrayList to store obtained MST
        val mst = ArrayList<Edge?>()
        // Priority Queue which gives minimum weight edge
        val pq = PriorityQueue(Comparator { edge1: Edge?, edge2: Edge? ->
            if (edge1!!.weight < edge2!!.weight)
                return@Comparator -1
            else if (edge1.weight > edge2.weight)
                return@Comparator 1
            else return@Comparator 0 })
        
        // add the source vertex in Priority queue
        pq.addAll(graph[0])
        var cost = 0.0
        val size = graph.size
        val visited = BooleanArray(size)
        // mark source vertex as visited
        visited[0] = true

        // Keep extracting edges till priority is not empty
        while (!pq.isEmpty()) { // extract edge with minimum weight from priority queue
            val edge = pq.peek()
            // pop the edge from priority queue
            pq.poll()
            if (visited[edge!!.to] && visited[edge.from]) continue
            // mark the from vertex as visited
            visited[edge.from] = true
            // if the adjacent vertex to source is unvisited, add the edge to the priority queue
            for (edge1 in graph[edge.to]) {
                if (!visited[edge1!!.to]) pq.add(edge1)
            }
            // mark the adjacent vertex as visited
            visited[edge.to] = true
            // add the edge in minimum spanning tree
            cost += edge.weight
            mst.add(edge)
        }
        println("Total cost of MST: $cost")
        return mst
    }

    /**
     * Function to create adjacency list representation of graph
     * @param edges
     * @param nodes
     * @return graph
     */
    private fun createGraph(edges: Array<Edge?>, nodes: Int): ArrayList<ArrayList<Edge?>> { // initialise graph as Adjacency List
        val graph = ArrayList<ArrayList<Edge?>>()
        // for adding Arraylist to Arraylist
        for (i in 0 until nodes) graph.add(ArrayList())
        // Create adjacency list from the edge connectivity information
        for (source in edges) {
            val destination = Edge(source!!.from, source.to, source.weight)
            graph[source.from].add(source)
            graph[source.to].add(destination)
        }
        // Return constructed graph
        return graph
    }

    /**
     * Main Function
     * @param args
     */
    @JvmStatic
    fun main(args: Array<String>) { // initialise number of nodes and edges
        val nodes = 7
        val countEdges = 10
        /* Input Graph is:   
                0
              /  \
            /      \
           1 ------  2
          / \       /  \
         3 -- 4 -- 5 -- 6        
        */
        val edges = arrayOfNulls<Edge>(countEdges)
        // initialising edges with from, to and weight value
        edges[0] = Edge(0, 1, 10)
        edges[1] = Edge(0, 2, 15)
        edges[2] = Edge(1, 2, 7)
        edges[3] = Edge(2, 5, 6)
        edges[4] = Edge(1, 3, 12)
        edges[5] = Edge(1, 4, 9)
        edges[6] = Edge(4, 5, 14)
        edges[7] = Edge(3, 4, 13)
        edges[8] = Edge(5, 6, 8)
        edges[9] = Edge(2, 6, 12)
        // Adjacency List representation of graph
        val graph = createGraph(edges, nodes)
        // ArrayList to store final MST obtained
        val mst = prims(graph)
        println("Minimum Spanning Tree:")
        for (edge in mst) println(edge!!.from.toString() + " - " + edge.to + " : " + edge.weight)
    }
}

/**
 * Input Graph is:
 *      0
 *     / \
 *    /   \
 *   1-----2
 *  / \   / \
 * 3---4-5---6
 *
 * Output:
 * Total cost: 52.0
 * Minimum Spanning Tree:
 * 0 - 1 : 10.0
 * 1 - 2 : 7.0
 * 2 - 5 : 6.0
 * 5 - 6 : 8.0
 * 1 - 4 : 9.0
 * 1 - 3 : 12.0
 *
 */
