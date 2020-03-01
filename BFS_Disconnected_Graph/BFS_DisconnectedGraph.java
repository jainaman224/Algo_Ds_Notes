import java.util.*;

public class BFS_DisconnectedGraph {
    // Implemented graph using HashMap
    static HashMap<Integer, LinkedList<Integer>> graph = new HashMap<>();

    // function to add edge in an undirected graph
    public static void addEdge(int a, int b) {
        if (graph.containsKey(a)) {
            LinkedList<Integer> l = graph.get(a);
            l.add(b);
            graph.put(a, l);
        } else {
            LinkedList<Integer> l = new LinkedList<>();
            l.add(b);
            graph.put(a, l);
        }
    }

    //Helper function for BFS  
    public static void bfshelp(int s, ArrayList<Boolean> visited) {
        // Create a queue for BFS
        LinkedList<Integer> q = new LinkedList<>();

        // Marking the current node as visited and enqueue it
        q.add(s);
        visited.set(s, true);

        while (!q.isEmpty()) {
            // Dequeue a vertex from queue and print it
            int f = q.poll();
            System.out.print(f + " ");

            // Check whether the current node is
            // connected to any other node or not
            if (graph.containsKey(f)) {
                Iterator<Integer> i = graph.get(f).listIterator();

                // Get all adjacent vertices of the dequeued
                // vertex f. If an adjacent has not been visited,
                // then mark it visited and enqueue it

                while (i.hasNext()) {
                    int n = i.next();
                    if (!visited.get(n)) {
                        visited.set(n, true);
                        q.add(n);
                    }
                }
            }
        }

    }

    //BFS function to check each node 
    public static void bfs(int vertex) {
        ArrayList<Boolean> visited = new ArrayList<Boolean>();
        // to mark each node as unvisited
        for (int i = 0; i < vertex; i++) {
            visited.add(i, false);
        }
        for (int i = 0; i < vertex; i++) {
            // to check whether the node is visited or not
            if (!visited.get(i)) {
                bfshelp(i, visited);
            }
        }
    }

    //Driver Code-The main function 
    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);

        // for bfs
        int v = scn.nextInt();

        int numberOfEdges = scn.nextInt();

        // function call to make edges accordingly
        while (numberOfEdges-- > 0) {
            int a = scn.nextInt();
            int b = scn.nextInt();
            addEdge(a, b);
        }
        // bfs function call
        bfs(v);

    }

    /*
     * sample input case
     * 
     * int v = 5; addEdge(0, 4); addEdge(1, 2); addEdge(1, 3); addEdge(1, 4);
     * addEdge(2, 3); addEdge(3, 4); bfs(v);
     * 
     */

    /*
     * sample output
     * 
     * 0 4 1 2 3
     * 
     */

}