// Java Program to calculation sum of 2 matrices (2D Array)
import java.util.*;

public class Matrix_Addition {
    // Find sum of 2 Matrices and store it in matrix3 
    public static void add_matrices(int[][] matrix1, int[][] matrix2) {
        
        int index1, index2 = 0;
        int[][] matrix3 = new int[matrix1.length][matrix1[0].length];
        
        for ( index1 = 0; index1 < matrix1.length ; index1 ++) {
            for ( index2 = 0; index2 < matrix1[0].length; index2++ ) {
                matrix3[index1][index2] = matrix1[index1][index2] + matrix2[index1][index2];
            }
        }

        // Print the calculated matrix
        for ( index1 = 0; index1 < matrix3.length ; index1 ++) {
            for ( index2 = 0; index2 < matrix3[0].length; index2++ ) {
                System.out.print( matrix3[index1][index2] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);

        System.out.println("Of First Matrix");
        System.out.println(" Enter number of rows ");
        int rows_first = s.nextInt();

        System.out.println(" Enter number of columns ");
        int columns_first = s.nextInt();
        int[][] matrix1 = new int[rows_first][columns_first];

        System.out.println("Of Second Matrix");
        System.out.println(" Enter number of rows ");
        int rows_second = s.nextInt();

        System.out.println(" Enter number of columns ");
        int columns_second = s.nextInt();
        int[][] matrix2 = new int[rows_second][columns_second];

        if (columns_first != columns_second || rows_first != rows_second) {
            System.out.println(" Addition of matrix is not possible ");
        }
        else {

            System.out.println(" Enter elements of 1st matrix ");
            for (int i = 0 ; i < rows_first; i++) {
                for (int j = 0 ; j< columns_first; j++) {
                    matrix1[i][j] = s.nextInt();
                }
            }

            System.out.println(" Enter elements of 2nd matrix ");
            for (int i = 0 ; i < rows_first; i++) {
                for (int j = 0 ; j< columns_first; j++) {
                    matrix2[i][j] = s.nextInt();
                }
            }
            add_matrices(matrix1, matrix2);
        }
    }
}

/*
TEST CASES
INPUT
Of First Matrix
Enter number of rows 
2
Enter number of columns 
3
Of Second Matrix
Enter number of rows 
2
Enter number of columns 
4
OUTPUT
Addition of matrix is not possible 
INPUT
Of First Matrix
Enter number of rows 
2
Enter number of columns 
2
Of Second Matrix
Enter number of rows 
2
Enter number of columns 
2
Enter elements of 1st matrix 
1
2
3
4
Enter elements of 2nd matrix 
1
1
1
1
OUTPUT
2 3 
4 5 
*/

