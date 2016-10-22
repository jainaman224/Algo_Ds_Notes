/**
 * Created by jude on 21/10/16.
 */
public class Floyd_Warshall_Algorithm {
    public static int Infinity = Integer.MAX_VALUE;
    static int[][] graph =  {     {0,        8,        Infinity, 15},
            {Infinity, 0,        7,        Infinity},
            {Infinity, Infinity, 0,        7},
            {Infinity, Infinity, Infinity, 0}
    };

    public static void main(String[] args)
    {
        FloydWarshall(graph);
    }
    public static void FloydWarshall(int[][] graph)
    {



        for(int k=0;k<4;k++)
        {
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    if(graph[i][k] != Infinity && graph[k][j] != Infinity && graph[i][k]+graph[k][j] < graph[i][j])
                    {
                        graph[i][j] = graph[i][k]+graph[k][j];
                    }
                }
            }
        }

        printSolution(graph);
    }

    private static void printSolution(int[][] graph) {
        System.out.println("Shortest distances between each pair of vertices");
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(graph[i][j] == Infinity)
                {
                    System.out.println("INFINITY \t");
                }
                else
                {
                    System.out.println(graph[i][j]);
                }
            }
            System.out.println("\n");
        }
    }


}

/* OUTPUT

The matrix below shows the shortest distances between each pair of vertices
           0           8          15          15
    INFINITY           0           7          14
    INFINITY    INFINITY           0           7
    INFINITY    INFINITY    INFINITY           0

*/
