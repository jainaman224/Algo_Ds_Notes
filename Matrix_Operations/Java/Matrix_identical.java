// Java Program to check and find if two matrices are identical or not
import java.util.Scanner;

public class Matrix_identical {

    // This function return true if the matrices are identical otherwise false
    public static boolean check_identical(int[][] matrix1, int[][] matrix2){
        int index1, index2 = 0;
        for ( index1 = 0; index1 < matrix1.length; index1++ ){
            for ( index2 = 0; index2 < matrix1[0].length; index2++ ){
                if (matrix1[index1][index2] != matrix2[index1][index2]) {
                    return false;
                }
            }
        }
        return true;
    }

    public static void main(String args[]){
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
            System.out.println(" Matrices's order is not identical ");
        }
        else {

            System.out.println(" Enter elements of 1st matrix ");
            for (int i = 0; i < rows_first; i++) {
                for (int j = 0; j < columns_first; j++) {
                    matrix1[i][j] = s.nextInt();
                }
            }

            System.out.println(" Enter elements of 2nd matrix ");
            for (int i = 0; i < rows_first; i++) {
                for (int j = 0; j < columns_first; j++) {
                    matrix2[i][j] = s.nextInt();
                }
            }
            boolean b = check_identical(matrix1, matrix2);
            if (b) System.out.println("Matrices are identical");
            else System.out.println(" Matrices are not identical");
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
2
Of Second Matrix
 Enter number of rows 
2
 Enter number of columns 
2
 Enter elements of 1st matrix 
1 2
0 4
 Enter elements of 2nd matrix 
1 2
7 6
OUTPUT
 Matrices are not identical
 
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
1 2
0 4
 Enter elements of 2nd matrix 
1 2
0 4
OUTPUT
 Matrices are identical
*/

