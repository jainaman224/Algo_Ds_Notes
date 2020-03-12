#include<bits/stdc++.h>
using namespace std;
void PrintSolution(int** solution , int n)
{
	/*
		This Function is used to print all the
		Possible Path a rat can take to reach Final Destination.
	*/
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<solution[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
void mazeHelp(int maze[][20] ,int** solution , int n, int x ,int y )
{
	
	/*
		if the path has been completed then Rat position must be
		last column's last row.
	*/
	
    if(x==n-1 && y == n-1)
    {
        solution[x][y] = 1;				//This is Base Case of Recursive Approach we have used.
        PrintSolution(solution , n);
    }
    /*
    	Following Condition if Occur then path is wrong
    	1. If row value get more than n (maximum size of Maze) or less than 0 (Minimum Row of Maze).
    	2. If Column value get more than n (maximum column of Maze) or less than 0 (Minimum column of Maze).
    	3. If there is a blockage represented by 0.
    	4. If particular position has already been included in Solution.
    */
    if(x == n || x < 0 || y ==n || y < 0 || maze[x][y] == 0 || solution[x][y] == 1)
    {
        return;							
    }
    solution[x][y] = 1;
    //up
    mazeHelp(maze , solution, n ,x-1 ,y);
    //down
    mazeHelp(maze , solution , n,x+1 ,y);
    //left
    mazeHelp(maze , solution , n,x ,y-1);
    //right
    mazeHelp(maze , solution, n ,x ,y+1);
    solution[x][y] = 0;
}

void ratInMaze(int maze[][20] , int n)
{
    int** solution = new int*[n];
  	for(int i=0;i<n;i++)
	    {
  	        solution[i] = new int[n];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                solution[i][j]=0;
            }
        }
        
    mazeHelp(maze , solution , n , 0 , 0);
}
int main() {
	int n;
	cin>>n;
	int maze[20][20] = {0};
	for(int i = 0; i < n ;i++)
	{
	    for(int j = 0; j < n; j++)
		{
        	cin >> maze[i][j];
        }		
    }
	ratInMaze(maze , n);
	return 0;
}

    
/*
Sample Input

3
1 0 1 
1 1 1
1 1 1

Output
100
111
111

100
100
111

100
110
011

100
111
001
*/
