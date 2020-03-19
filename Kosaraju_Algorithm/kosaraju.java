//Java implementation of Kosaraju's Algorithm
//Kosaraju's Algorithm is used to print all Strongly Connected Components (SCCs) in a directed graph
//A component is said to be strongly connected if there is a path between all pairs of vertices in it.
//Kosaraju’s Algorithm involves two passes of Depth First Search in order to find the number of SCCs

import java.util.*;

class Main {
    private int V;   // No. of vertices 
    private LinkedList[] adj; //Adjacency List

    //Constructor 
    Main(int v) {
        V = v;
        adj = new LinkedList[v];
        for (int i = 0; i < v; ++i)
            adj[i] = new LinkedList();
    }

    //Function to add an edge into the graph 
    void addEdge(int v, int w) {
        adj[v].add(w);
    }

    // A recursive function to print DFS starting from v 
    void DFS(int v, boolean visited[]) {
        // Mark the current node as visited and print it 
        visited[v] = true;
        System.out.print(v + " ");

        int n;

        // Recur for all the vertices adjacent to this vertex
        Iterator<Integer> i = adj[v].iterator();
        while (i.hasNext()) {
            n = i.next();
            if (!visited[n])
                DFS(n, visited);
        }
    }

    // Function that returns reverse (or transpose) of this graph 
    Main getTranspose() {
        Main g = new Main(V);
        for (int v = 0; v < V; v++) {
            // Recur for all the vertices adjacent to this vertex 
            ListIterator i = adj[v].listIterator();
            while (i.hasNext())
                g.adj[(int) i.next()].add(v);
        }
        return g;
    }

    void traverse(int v, boolean visited[], Stack stack) {
        // Mark the current node as visited and print it 
        visited[v] = true;

        // Recur for all the vertices adjacent to this vertex 
        Iterator<Integer> i = adj[v].iterator();
        while (i.hasNext()) {
            int n = i.next();
            if (!visited[n])
                traverse(n, visited, stack);
        }

        // All vertices reachable from v are processed by now, 
        // push v to Stack 
        stack.push(v);
    }

    // The main function that finds and prints all strongly 
    // connected components 
    void printSCCs() {
        Stack stack = new Stack();

        // Mark all the vertices as not visited (For first DFS) 
        boolean visited[] = new boolean[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        // Fill vertices in stack according to their finishing time
        for (int i = 0; i < V; i++)
            if (visited[i] == false)
                traverse(i, visited, stack);

        // Create a reversed graph 
        Main gr = getTranspose();

        // Mark all the vertices as not visited (For second DFS) 
        for (int i = 0; i < V; i++)
            visited[i] = false;

        // Now process all vertices in order defined by Stack 
        while (!stack.empty()) {
            int v = (int) stack.pop();
            // Print Strongly connected component of the popped vertex 
            if (!visited[v]) {
                gr.DFS(v, visited);
                System.out.println();
            }
        }
    }

    public static void main(String args[]) {
        int i, v, e, v1, v2;
        Scanner sn = new Scanner(System.in);
        System.out.println("Enter the number of vertices");
        v = sn.nextInt();
        Main g = new Main(v);
        System.out.println("Enter the number of edges");
        e = sn.nextInt();
        System.out.println("Enter each edge with end vertices");
        for (i = 1; i <= e; i++) {
            v1 = sn.nextInt();
            v2 = sn.nextInt();
            g.addEdge(v1, v2);
        }
        System.out.println("Strongly connected components in given graph:");
        g.printSCCs();
    }
}
/*
Sample Input:

Enter the number of vertices
5
Enter the number of edges
5

Enter each edge with end vertices
1 0
0 2
2 1
0 3
3 4

Strongly connected components in given graph:
0 1 2
3
4
 */