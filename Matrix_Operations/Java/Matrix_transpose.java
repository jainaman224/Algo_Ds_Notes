// Java Program to calculation transpose of a matrix (2D Array)
import java.util.Scanner;

public class Matrix_transpose {

    // Find transpose of matrix
    public static void transpose_matrices(int[][] matrix) {

        int index1, index2;
        int[][] matrix_ans = new int[matrix.length][matrix[0].length];
        for ( index1 = 0; index1 < matrix.length; index1 ++) {
            for ( index2 = 0; index2 < matrix[0].length; index2++ ) {
                matrix_ans[index2][index1] = matrix[index1][index2];
            }
        }

        // Print the calculated matrix
        for ( index1 = 0; index1 < matrix_ans.length; index1 ++) {
            for ( index2 = 0; index2 < matrix_ans[0].length; index2++ ) {
                System.out.print( matrix_ans[index1][index2] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);

        System.out.println(" Enter number of rows ");
        int rows = s.nextInt();

        System.out.println(" Enter number of columns ");
        int columns = s.nextInt();
        int[][] matrix = new int[rows][columns];


        System.out.println(" Enter elements of matrix ");
        for (int i = 0; i < rows; i++) {
            for (int j = 0 ; j < columns; j++) {
                matrix[i][j] = s.nextInt();
            }
        }
        transpose_matrices(matrix);
    }
}
/*
TEST CASES

INPUT
 Enter number of rows 
2
 Enter number of columns 
2
 Enter elements of matrix 
2 3
4 5

OUTPUT
2 4 
3 5 

*/

