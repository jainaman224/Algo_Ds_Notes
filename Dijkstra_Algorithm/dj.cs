using System;

class DA
{
    static int v = 9
    int minDistance(int[] dist,bool[] sptSet)
    {
        int min = int.MaxValue, min_index = -1;
        for (int i = 0; i < v; i++)
	        if (sptSet[i] == false && dist[i] <= min) 
		    {
		        min = dist[i];
			    min_index = i;
		    }

	return min_index;
    }
    
    
    void printSolution(int[] dist, int n)
    {
        Console.Write("Vertex Distance "+ "from Source\n");
        for (int i = 0; i < v; i++)
            Console.Write(i + " \t\t " + dist[i] + "\n");
    }

    void dijkstra(int[, ] graph, int src)
    {
        int[] dist = new int[v];
        bool[] sptSet = new bool[v];
        for (int i = 0; i < v; i++) 
        {
	        dist[i] = int.MaxValue;
	        sptSet[i] = false;
	    }
        dist[src] = 0;
        for (int count = 0; count < v - 1; count++) 
        {
	        int u = minDistance(dist, sptSet);
	        for (int v = 0; v < V; v++)
	            if (!sptSet[v] && graph[u, v] != 0 && dist[u] != int.MaxValue && dist[u] + graph[u, v] < dist[v])
		            dist[v] = dist[u] + graph[u, v];
	    }
}

// Driver Code
    public static void Main()
    {
        int[, ] graph = new int[, ] { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
				                      { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
				                      { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
				                      { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
				                      { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
				                      { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
				                      { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
				                      { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
				                      { 0, 0, 2, 0, 0, 0, 6, 7, 0 } 
                                    };
         DA t = new DA();
         t.dijkstra(graph, 0);
    } 
}


// Output
// Vertex     Distance from Source
// 0          0
// 1          4
// 2          12
// 3          19
// 4          21
// 5          11
// 6          9
// 7          8
// 8          14

