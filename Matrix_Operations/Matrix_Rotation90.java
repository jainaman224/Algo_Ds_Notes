
import java.io.*; 

class MatrixRotation
{ 
    static void rotateMatrix(int N, int mat[][]) 
    { 
	for (int x = 0; x < N / 2; x++) 
	{ 
	    // Consider elements in group of 4 in current square 
	    for (int y = x; y < N-x-1; y++) 
	    { 
		// store current cell in temp variable 
		int temp = mat[x][y]; 
	
		// move values from right to top 
		mat[x][y] = mat[y][N-1-x]; 
	
		// move values from bottom to right 
		mat[y][N-1-x] = mat[N-1-x][N-1-y]; 
	
		// move values from left to bottom 
		mat[N-1-x][N-1-y] = mat[N-1-y][x]; 
	
		// assign temp to left 
	        mat[N-1-y][x] = temp; 
	    } 
        } 
    } 

    // Function to print the matrix 
    static void displayMatrix(int N, int mat[][]) 
    { 
	for (int i = 0; i < N; i++) 
	{ 
	    for (int j = 0; j < N; j++) 
	        System.out.print(" " + mat[i][j]); 
	
	    System.out.print("\n"); 
	} 
	System.out.print("\n"); 
    } 
	
    /* Driver program*/
    public static void main (String[] args) 
    { 
	int N = 4; 
		
	// Sample Input
	int mat[][] = 
	{ 
	    {1, 2, 3, 4}, 
	    {5, 6, 7, 8}, 
	    {9, 10, 11, 12}, 
	    {13, 14, 15, 16} 
	}; 
	
	rotateMatrix(N,mat); 
	
	// Print rotated matrix 
	displayMatrix(N,mat); 
    } 
} 

/* Sample Output:

    4  8 12 16 
    3  7 11 15 
    2  6 10 14 
    1  5  9 13 

*/


