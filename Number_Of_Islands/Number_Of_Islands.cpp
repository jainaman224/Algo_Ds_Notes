/*
    Number of Islands Problem is a problem to compute the count
    of number of disconnected islands present in the sea i.e
    Given an adjacency matrix, it is count of number of connected
    components in that graph.
*/

#include <bits/stdc++.h>
using namespace std;
#define C 1000

// Function to perform DFS from a cell
void dfs(int i, int j, int adj[][C], int N, int M, bool visited[][C]) 
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
        if (adj[i][j] == 1 && !visited[i][j]) 
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
int numberOfIslands(int adj[][C], int N, int M) 
{
    // A 2D Matrix to keep track of visited cells
    // Initialising all cells with false initially
    bool visited[N][C];
    memset(visited, false, N * C * sizeof(visited[0][0]));

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
            if (adj[i][j] == 1 && !visited[i][j]) 
            {
                dfs(i, j, adj, N, M, visited);
                components++;
            }
        }
    }
    return components;
}

// Driver function
int main() 
{
    // N is the number of rows
    // M is the numbers of columns
    int N, M;
    cin >> N >> M;

    // Adjacency Matrix representation of Graph in adj
    int adj[N][C];

    // Taking input of Graph
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> adj[i][j];

    // Call to compute the number of Islands
    cout << "Number of Islands: ";
    cout << numberOfIslands(adj, N, M) << endl;
    return 0;
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
