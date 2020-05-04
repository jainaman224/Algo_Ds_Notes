// Java Program to find the sum of middle row and middle column
import java.util.Scanner;

public class Middle_row_column_sum {

    public static void middle_row_column_sum(int[][] matrix){
        int index1, index2, middle_row_sum = 0, middle_column_sum = 0;

        //Finding sum of middle row
        for ( index1 = 0; index1 < matrix.length; index1++) {
            middle_row_sum += matrix[matrix.length / 2][index1];
        }

        //Finding sum of middle column
        for ( index2 = 0; index2 < matrix[0].length; index2++) {
            middle_column_sum += matrix[index2][ matrix[0].length / 2];
        }

        System.out.println("Middle row's sum is " + middle_row_sum);
        System.out.println("Middle column's sum is " + middle_column_sum);
    }

    public static void main(String args[]){
        Scanner s = new Scanner(System.in);

        System.out.println(" Enter number of rows ");
        int rows = s.nextInt();

        System.out.println(" Enter number of columns ");
        int columns = s.nextInt();
        int[][] matrix = new int[rows][columns];

        System.out.println(" Enter elements of matrix ");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matrix[i][j] = s.nextInt();
            }
        }
        middle_row_column_sum(matrix);
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
Middle row's sum is 3
Middle column's sum is 8
*/
