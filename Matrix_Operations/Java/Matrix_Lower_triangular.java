import java.util.Scanner;

public class Lower_triangular_matrix {

    //Finding lower triangular matrix
    public static void lower_triangular_matrix(int[][] matrix){
        int index1, index2 = 0;
        int[][] matrix_lower = new int[matrix.length][matrix[0].length];
        for ( index1 = 0; index1 < matrix.length; index1++) {
            for ( index2 = 0; index2 < matrix[0].length; index2++) {
                if (index1 < index2){
                    matrix_lower[index1][index2] = 0;
                }
                else {
                    matrix_lower[index1][index2] = matrix[index1][index2];
                }
            }
        }
        for ( index1 = 0; index1 < matrix.length; index1++) {
            for (index2 = 0; index2 < matrix[0].length; index2++) {
                System.out.print(matrix_lower[index1][index2] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String args[]){
        Scanner s = new Scanner(System.in);

        System.out.println(" Enter number of rows ");
        int rows = s.nextInt();

        System.out.println(" Enter number of columns ");
        int columns= s.nextInt();
        int[][] matrix = new int[rows][columns];

        System.out.println(" Enter elements of matrix ");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matrix[i][j] = s.nextInt();
            }
        }
        lower_triangular_matrix(matrix);
    }
}

/*
TEST CASES

INPUT
 Enter number of rows
3
 Enter number of columns
3
 Enter elements of matrix
1 2 3
1 1 1
4 5 2

OUTPUT
1 0 0
1 1 0
4 5 2
*/

