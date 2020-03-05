import java.util.*;

public class BFS_DisconnectedGraph {

    static class Graph {
        int vertices;
        LinkedList<Integer>[] neighbourList;

        // parameterized constructor for graph (where v is number of vertices)
        public Graph(int v) {
            vertices = v;
            neighbourList = new LinkedList[v];

            // initialize the neighbor list for each vertex
            for (int i = 0; i < vertices; i++) {
                neighbourList[i] = new LinkedList<>();
            }
        }

        public void insertEdge(int a, int b) {
            // add forward edge
            neighbourList[a].addFirst(b);

            // add backward edge
            neighbourList[b].addFirst(a);

        }

        public void BFS() {

            /*
             * to keep a track of visited vertices and to avoid going into loops
             */
            boolean[] visited = new boolean[vertices];

            Queue<Integer> q = new LinkedList<>();

            for (int i = 0; i < vertices; i++) {

                // for each unvisited vertex - add in queue and call helpBFS(q,visited)
                if (!visited[i]) {
                    q.add(i);
                    helpBFS(q, visited);
                }
            }
        }

        /*
         * Pseudo Code for helpBFS(q,visited): While the queue is not empty. Remove a
         * vertex v from the queue. Print the vertex v. Mark the vertex v true in the
         * boolean array. Add all the unvisited neighbor vertices of v to the queue.
         */

        public void helpBFS(Queue<Integer> q, boolean[] visited) {

            while (!q.isEmpty()) {

                // remove vertex from beginning of queue
                int vertex = q.remove();

                // mark that vertex visited
                visited[vertex] = true;

                // print that vertex
                System.out.print(vertex + " ");

                // add unvisited neighbor vertices
                for (int idx = 0; idx < neighbourList[vertex].size(); idx++) {

                    int adjacentVertex = neighbourList[vertex].get(idx);

                    if (!visited[adjacentVertex]) {

                        visited[adjacentVertex] = true;
                        q.add(adjacentVertex);
                    }
                }
            }
        }
    }

    // driver code
    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);

        int noOfVertices = scn.nextInt();

        Graph g = new Graph(noOfVertices);

        int noOfEdges = scn.nextInt();

        while (noOfEdges-- > 0) {
            int a = scn.nextInt();
            int b = scn.nextInt();
            g.insertEdge(a, b);
        }

        g.BFS();
    }
    

    /*
     * sample input 1: 
     * noOfVertices = 7
     * noOfEdges = 7
     * Graph g = new Graph(7); 
     * g.addEdge(0, 1); 
     * g.addEdge(0, 2);
     * g.addEdge(1, 2); 
     * g.addEdge(1, 3); 
     * g.addEdge(4, 5); 
     * g.addEdge(4, 6);
     * g.addEdge(5, 6); 
     * g.BFS();
     */

    /*
     * sample output 1:
     * 0 2 1 3 4 6 5
     */

    /*
     * sample input 2: 
     * noOfVertices = 5
     * noOfEdges = 6
     * Graph g = new Graph(5); 
     * g.addEdge(0, 4); 
     * g.addEdge(1, 2);
     * g.addEdge(1, 3); 
     * g.addEdge(1, 4); 
     * g.addEdge(2, 3); 
     * g.addEdge(3, 4); 
     * g.BFS();
     */

    /*
     * sample output 2:
     * 0 4 3 1 2
     */

}
