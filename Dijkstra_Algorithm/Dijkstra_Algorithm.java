package Greedy.Dijkstra;

import java.lang.*;
// A Java program for Dijkstra's single source shortest path algorithm.
// The program uses adjacency matrix
    class Dijkstra
    {

        static final int V=9; //number of vertices
        // A function to find the vertex with minimum distance value,
        // from the set of vertices that aren't yet included in shortest path tree
        void dj_algo(int graph[][], int source)
        {
            int distance[] = new int[V];
            
           
            Boolean sptIncluded[] = new Boolean[V];
            // Initializing all distances as INFINITE and stpIncluded[] as false
            for (int i = 0; i < V; i++)
            {
                distance[i] = Integer.MAX_VALUE;
                sptIncluded[i] = false;
            }
            distance[source] = 0;
            // Shortest path
            for (int count = 0; count < V-1; count++)
            {
                // Choose the vertex with smallest distance from unprocessed vertices
                int u = minDistance(distance, sptIncluded);
                // Mark the picked vertex as processed
                sptIncluded[u] = true;
                // Update distance value of the adjacent vertices of the picked vertex.
                for (int v = 0; v < V; v++)
                    // Update distance[v] only if it is not in sptIncluded,
                    // there is an edge from u to v, and total distance(weight) from source to
                    // v through u is smaller than current value of distance[v]
                    // code courtesy Geeksforgeeks.org
                    if (!sptIncluded[v] && graph[u][v]!=0 &&
                            distance[u] != Integer.MAX_VALUE &&
                            distance[u]+graph[u][v] < distance[v])
                        distance[v] = distance[u] + graph[u][v];
            }
            // Generate the output
            output(distance);
        }
        int minDistance(int distance[], Boolean sptIncluded[])
        {
            // Initialize minimum value
            //Take the reference from Negative Infinity
            //min_index corresponds to the index of
            //vertex whose distance is stored in min
            int min = Integer.MAX_VALUE, min_index=-1;
            for (int v = 0; v < V; v++) {
                if (sptIncluded[v] == false && distance[v] <= min) {
                    min = distance[v];
                    min_index = v;
                }
            }
            return min_index;
        }
        void output(int distance[]){
            System.out.println("Vertex\tDistance From Source");
            for (int i = 0; i < V; i++) {
                System.out.println(i + "\t\t\t" + distance[i]);
            }
        }
        // Driver method
        public static void main (String[] args)
        {
        /* Example graph (adjacency matrix)*/
        // courtesy Geeksforgeeks.org
            int adj_matrix[][] = new int[][]{
                    {0, 4, 0, 6, 0, 3, 0, 8, 0},
                    {4, 0, 8, 0, 0, 0, 0, 7, 0},
                    {0, 8, 0, 4, 0, 4, 0, 0, 2},
                    {6, 0, 4, 0, 9, 5, 0, 0, 0},
                    {0, 0, 0, 9, 0, 9, 0, 0, 0},
                    {3, 0, 4, 5, 9, 0, 2, 0, 0},
                    {0, 0, 0, 0, 0, 2, 0, 1, 6},
                    {8, 7, 0, 0, 0, 0, 1, 0, 7},
                    {0, 0, 2, 0, 0, 0, 6, 7, 0}
            };
            System.out.println("Output");
            Dijkstra d = new Dijkstra();
            d.dj_algo(adj_matrix, 0);
        }
    }
// Output
//        0		0
//        1		4
//        2		7
//        3		6
//        4		12
//        5		3
//        6		5
//        7		6
//        8		9

