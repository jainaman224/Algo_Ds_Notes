#include<bits/stdc++.h> 
using namespace std; 

const int MAX = 100; 

int getMaxGold(int gold[][MAX], int m, int n) 
{ 
	int goldTable[m][n]; 
	memset(goldTable, 0, sizeof(goldTable)); // Initialize all cells to 0

	for (int col=n-1; col>=0; col--)
	{ 
		for (int row=0; row<m; row++) 
		{ 
			// Gold collected while going to right
			int right = (col==n-1)? 0: goldTable[row][col+1]; 

			// Gold collected while going to right up
			int right_up = (row==0 || col==n-1)? 0: 
							goldTable[row-1][col+1]; 

			// Gold collected while going to right down
			int right_down = (row==m-1 || col==n-1)? 0: 
							goldTable[row+1][col+1]; 

			// Max gold collected from above 3 paths
			goldTable[row][col] = gold[row][col] + 
							max(right, max(right_up, right_down)); 
													
		} 
	} 

	int res = goldTable[0][0]; 
	for (int i=1; i<m; i++) 
		res = max(res, goldTable[i][0]);//max gold collected is max val in first column of all rows
	return res; 
} 

int main() 
{ 
    int m,n;
    cin>>m>>n;
    int gold[MAX][MAX];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>gold[i][j];
        }
    }
    
    /* Sample Input
        4 4                                                                                                                                                                 
        1 3 1 5                                                                                                                                                             
        2 2 4 1                                                                                                                                                             
        5 0 2 3                                                                                                                                                             
        0 6 1 2 
        
       Sample Output
       16
    */
	cout << getMaxGold(gold, m, n); 
	return 0; 
} 
