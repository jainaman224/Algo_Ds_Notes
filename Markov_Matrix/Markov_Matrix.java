/*
Markov Matrix is a matrix in which the sum of each row is equal to 1.
*/

import java.util.*;

class MarkovMatrix
{ 
    static void markovMatrix(double matrix[][], int row, int col) 
    { 
        int count = 0;
        for (int i = 0; i < row; i++)
        { 
            double sum = 0;

            // Calculating sum of each row
            for (int j = 0; j < col; j++) 
                sum = sum + matrix[i][j]; 
            if (sum != 1) 
                count++; 
        } 
        if (count == 0)
            System.out.print("YES");
        else 
            System.out.print("NO");
    } 

    public static void main(String args[]) 
    { 
        Scanner sc = new Scanner(System.in); 
        int row = sc.nextInt();
        int col = sc.nextInt();
        double[][] matrix = new double[row][col];
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) 
                matrix[i][j] = sc.nextDouble();
        markovMatrix(matrix, row, col); 
    } 
} 

/*
Input:
row = 2
col = 2
Matrix = {{1, 0},
          {0.5, 0.5}}
Output:
YES
*/
