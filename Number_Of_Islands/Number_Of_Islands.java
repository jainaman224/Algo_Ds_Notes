/*
    Number of Islands Problem is a problem to compute the count
    of number of disconnected islands present in the sea i.e
    Given an adjacency matrix, it is count of number of connected
    components in that graph.
*/

import java.util.Scanner;

class Number_Of_Islands
{
    // Function to perform DFS from a cell
    public static void dfs(int i, int j, int adj[][], int N, int M, boolean visited[][]) 
    {
        // perform DFS when all the values of i and j
        // fall within the matrix
        if (i >= 0 && i < N && j >= 0 && j < M)
        {
            /*
                Check for an edge of the current cell with
                all the neighbouring 8 cells in the matrix 
                and it is not visited, perform DFS from that cell, 
                and mark the cell as visited.
            */
            if (adj[i][j] == 1 && visited[i][j] == false) 
            {
                visited[i][j] = true;

                // Cell to the upper left diagonal of current cell
                dfs(i - 1, j - 1, adj, N, M, visited);
                // Cell to the upper right diagonal of current cell
                dfs(i - 1, j + 1, adj, N, M, visited);
                // Cell to the up of current cell
                dfs(i - 1, j, adj, N, M, visited);
                // Cell to the down of current cell
                dfs(i + 1, j, adj, N, M, visited);
                // Cell to the left of current cell 
                dfs(i, j - 1, adj, N, M, visited);
                // Cell to the right of current cell
                dfs(i, j + 1, adj, N, M, visited);
                // Cell to the lower left diagonal of current cell
                dfs(i + 1, j - 1, adj, N, M, visited);
                // Cell to the lower right diagonal of current cell
                dfs(i + 1, j + 1, adj, N, M, visited);
            }
        }
    }

    // Function to compute number of connected components 
    // using Adjacency Matrix Representation of Graph
    public static int numberOfIslands(int adj[][], int N, int M) 
    {
        // A 2D Matrix to keep track of visited cells
        boolean[][] visited = new boolean[N][M];

        // Variable for storing count of components of Graphs
        int components = 0;
        for (int i = 0; i < N; i++) 
        {
            for (int j = 0; j < M; j++) 
            {
                /* 
                    if there is an edge between i - j and it is
                    not visited, perform DFS from that cell, then
                    increase the number of connected components by 1.
                */
                if (adj[i][j] == 1 && visited[i][j] == false) 
                {
                    dfs(i, j, adj, N, M, visited);
                    components++;
                }
            }
        }
        return components;
    }

    // Driver function
    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        // N is the number of rows
        // M is the numbers of columns
        int N = sc.nextInt();
        int M = sc.nextInt();

        // Adjacency Matrix representation of Graph in adj
        int adj[][] = new int[N][M];

        // Taking input of Graph
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                adj[i][j] = sc.nextInt();

        // Call to compute the number of Islands
        Number_Of_Islands obj = new Number_Of_Islands();
        int answer = obj.numberOfIslands(adj, N, M);
        System.out.println("Number of Islands: " + answer);
    }
}

/*
    Input:
    4 6
    1 1 0 0 0 0
    0 1 0 0 1 1
    0 0 0 0 1 1
    1 1 0 0 0 0

    Output:
    Number of Islands: 3
*/
