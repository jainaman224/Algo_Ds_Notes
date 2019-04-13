import java.io.*; 

class matrixRotation
{ 
    static void Rotate(int matrix[][], int N) 
    { 
        for (int i = 0; i < N / 2; i++) 
        { 
            for (int j = i; j < N-i-1; j++) 
            { 
                int t = matrix[i][j]; 
                matrix[i][j] = matrix[j][N-1-i]; 
                matrix[j][N-1-i] = matrix[N-1-i][N-1-j]; 
                matrix[N-1-i][N-1-j] = matrix[N-1-j][i]; 
                matrix[N-1-j][i] = t; 
            } 
        } 
    } 

    public static void main (String[] args) 
    { 
        int N = 3; 
    
        // Sample Input
        int matrix[][] = 
        { 
            {1, 2, 3}, 
            {5, 6, 7}, 
            {9, 10, 11} 
        }; 
        Rotate(matrix, N); 
  
        // Print rotated matrix 
        for (int i = 0; i < N; i++) 
        { 
            for (int j = 0; j < N; j++) 
                System.out.print(" " + matrix[i][j]); 
  
            System.out.print("\n"); 
        } 
        System.out.print("\n"); 
    } 
} 

/* Sample Output:

    3 7 11
    2 6 10
    1 5 9
*/
