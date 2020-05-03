// Java Program to calculate the sum of all elements in the matrix
import java.util.Scanner;

public class Sum_of_elements {

    //Calculating sum of all elements in matrix
    public static void sum_elements(int[][] matrix){
        int index1, index2, sum = 0;
        for ( index1 = 0; index1 < matrix.length; index1++) {
            for ( index2 = 0; index2 < matrix[0].length; index2++) {
                sum += matrix[index1][index2];
            }
        }
        System.out.println(sum);
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
        sum_elements(matrix);
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
1 2
1 1

OUTPUT
5

*/

