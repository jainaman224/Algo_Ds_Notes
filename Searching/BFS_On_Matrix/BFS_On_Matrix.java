/*
Compute the shortest distance between two cells in a matrix namely the source and destination cells, where only certain moves like up, down, left and right are allowed. 
The cell marked as '2' is the source
The cell marked as '3' is the destination
The cells marked as '1', where a move is allowed.
The cells marked as '0' are forbidden, hence move is not allowed
*/

import java.util.*;

class Node
{
    int row_num;
    int col_num;
    Node(int i, int j)
    {
        row_num = i;
        col_num = j;
    }
};

class BFS_On_Matrix
{
    private static final int INF = 10000;
    // Function to compute minimum distance between source and destination using BFS
    public static int findDistance(int row, int col, int mat[][]) 
    {
        // Variable to store the information about source and destination
        int source_i = 0;
        int source_j = 0;
        int destination_i = 0;
        int destination_j = 0;
        // Loop to find out the source and destination
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                // Cell marked as 2 is the source
                if (mat[i][j] == 2)
                {
                    source_i = i;
                    source_j = j;
                }
                // cell marked as 3 is the destination
                if (mat[i][j] == 3) 
                {
                    destination_i = i;
                    destination_j = j;
                }
            }
        }

        // dist matrix will store information about the distance of a cell from source
        // initialising dist matrix as some large value
        int[][] dist = new int[row][col];
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
                dist[i][j] = INF;
        }

        // initialise queue to start BFS on matrix
        Queue<Node> q = new LinkedList<>();
        Node source = new Node(source_i, source_j);
        q.add(source);
        dist[source_i][source_j] = 0;
        int x, y;

        // modified BFS by add constraint checks
        while (!q.isEmpty())
        {
            Node temp = q.peek();
            x = temp.row_num;
            y = temp.col_num;

            // Remove the cell from queue
            q.poll();

            // If move towards left is allowed or it is the destnation cell
            if (y - 1 >= 0 && (mat[x][y - 1] == 1 || mat[x][y - 1] == 3)) 
            {
		// if distance to reach the cell to the left is less than the computed previous path distance, update it
                if (dist[x][y] + 1 < dist[x][y - 1])
                {
                    dist[x][y - 1] = dist[x][y] + 1;
                    Node next = new Node(x, y - 1);
                    q.add(next);
                }
            }

            // If move towards right is allowed or it is the destination cell
            if (y + 1 < col && (mat[x][y + 1] == 1 || mat[x][y + 1] == 3))
            {
                // if distance to reach the cell to the right is less than the computed previous path distance, update it
                if (dist[x][y] + 1 < dist[x][y + 1]) 
                {
                    dist[x][y + 1] = dist[x][y] + 1;
                    Node next = new Node(x, y + 1);
                    q.add(next);
                }
            }

            // If move towards up is allowed or it is the destination cell
            if (x - 1 >= 0 && (mat[x - 1][y] == 1 || mat[x-1][y] == 3)) 
            {
                // if distance to reach the cell to the up is less than the computed previous path distance, update it
                if (dist[x][y] + 1 < dist[x - 1][y]) 
                {
                    dist[x - 1][y] = dist[x][y] + 1;
                    Node next = new Node(x - 1, y);
                    q.add(next);
                }
            }

            // If move towards down is allowed or it is the destination cell
            if (x + 1 < row && (mat[x + 1][y] == 1 || mat[x+1][y] == 3))
            {
                // if distance to reach the cell to the down is less than the computed previous path distance, update it
                if (dist[x][y] + 1 < dist[x + 1][y])
                {
                    dist[x + 1][y] = dist[x][y] + 1;
                    Node next = new Node(x + 1, y);
                    q.add(next);
                }
            }
        }
        return dist[destination_i][destination_j];
    }

    public static void main(String args[])
    {
        // initialising number of rows and columns
        int row = 5;
        int col = 5;
        // initialising matrix 
        int[][] mat =  { {1, 0, 0, 2, 1},
                        {1, 0, 1, 1, 1},
                        {0, 1, 1, 1, 0},
                        {3, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1} };
    
        // Call to function to compute distance between source and destination
        BFS_On_Matrix obj = new BFS_On_Matrix();
        int answer = obj.findDistance(row, col, mat);
        // When source and destination are unreachable
        if (answer == INF)
            System.out.println("No Path present between source and destination");
        else
        {
            // When source and destination are reachable, print shortest distance between them
            System.out.println("The Shortest Distance between Source and Destination is:");
            System.out.println(answer);
        }
    }
}

/*
Input:
[1, 0, 0, 2, 1]
[1, 0, 1, 1, 1]
[0, 1, 1, 1, 0]
[3, 1, 0, 0, 1]
[1, 1, 0, 0, 1]

Output:
The Shortest Distance between Source and Destination is:
6
*/
