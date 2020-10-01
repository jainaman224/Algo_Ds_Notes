/*
Compute the shortest distance between two cells in a matrix namely the source and destination cells, where only certain moves like up, down, left and right are allowed. 
The cell marked as '2' is the source
The cell marked as '3' is the destination
The cells marked as '1', where a move is allowed.
The cells marked as '0' are forbidden, hence move is not allowed
*/

#include<bits/stdc++.h>
using namespace std;
#define mkp make_pair

// Function to compute minimum distance between source and destination using BFS
int findDistance(int row, int col, int mat[][5]) 
{
    // Variable to store the information about source and destination
    int source_i, source_j, destination_i, destination_j;
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
    // initialising dist matrix as INT_MAX
    int dist[row][col];
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
            dist[i][j] = INT_MAX;
    }

    // initialise queue to start BFS on matrix
    queue<pair<int, int>> q;
    q.push(mkp(source_i, source_j));
    dist[source_i][source_j] = 0;

    // modified BFS by add constraint checks
    while (!q.empty())
    {
        // storing the x co-ordinate or row information of cell
        int x = q.front().first;
        // storing the y co-ordinate or column information of cell
        int y = q.front().second;
        // Remove the cell from queue
        q.pop();

        // If move towards left is allowed or it is the destnation cell
        if (y - 1 >= 0 && (mat[x][y - 1] == 1 || mat[x][y - 1] == 3)) 
        {
            // if distance to reach the cell to the left is less than the computed previous path distance, update it
            if (dist[x][y] + 1 < dist[x][y - 1])
            {
                dist[x][y - 1] = dist[x][y] + 1;
                q.push(mkp(x, y - 1));
            }
        }

        // If move towards right is allowed or it is the destination cell
        if (y + 1 < col && (mat[x][y + 1] == 1 || mat[x][y + 1] == 3))
        {
            // if distance to reach the cell to the right is less than the computed previous path distance, update it
            if (dist[x][y] + 1 < dist[x][y + 1]) 
            {
                dist[x][y + 1] = dist[x][y] + 1;
                q.push(mkp(x, y + 1));
            }
        }

        // If move towards up is allowed or it is the destination cell
        if (x - 1 >= 0 && (mat[x - 1][y] == 1 || mat[x-1][y] == 3)) 
        {
            // if distance to reach the cell to the up is less than the computed previous path distance, update it
            if (dist[x][y] + 1 < dist[x - 1][y]) 
            {
                dist[x - 1][y] = dist[x][y] + 1;
                q.push(mkp(x - 1, y));
            }
        }

        // If move towards down is allowed or it is the destination cell
        if (x + 1 < row && (mat[x + 1][y] == 1 || mat[x+1][y] == 3))
        {
            // if distance to reach the cell to the down is less than the computed previous path distance, update it
            if (dist[x][y] + 1 < dist[x + 1][y])
            {
                dist[x + 1][y] = dist[x][y] + 1;
                q.push(mkp(x + 1, y));
            }
        }
    }
    return dist[destination_i][destination_j];
}

int main()
{
    // initialising number of rows and columns
    int row = 5;
    int col = 5;
    // initialising matrix 
    int mat[][5] = {{1, 0, 0, 2, 1},
                    {1, 0, 1, 1, 1},
                    {0, 1, 1, 1, 0},
                    {3, 1, 0, 0, 1},
                    {1, 1, 0, 0, 1}};

    // Call to function to compute distance between source and destination
    int answer = findDistance(row, col, mat);
    // When source and destination are unreachable
    if (answer == INT_MAX)
        cout<<"No Path present between source and destination"<<endl;
    else
    {
        // When source and destination are reachable, print shortest distance between them
        cout<<"The Shortest Distance between Source and Destination is:"<<endl;
        cout<<answer<<endl;
    }
    return 0;
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
