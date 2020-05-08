// Java Program to check where the elements of matrix are different and replacing them with a character
import java.util.Scanner;

public class Matrix_intersection {

    //Finding the elements which are different in both the matrices and replacing it with a char
    public static void check_intersection(int[][] matrix1, int[][] matrix2, String character){
        int index1, index2 = 0;
        for ( index1 = 0; index1 < matrix1.length; index1++) {
            for ( index2 = 0; index2 < matrix1[0].length; index2++) {
                if (matrix1[index1][index2] != matrix2[index1][index2]) {
                    System.out.print(character + " ");
                }
                else{
                    System.out.print(matrix1[index1][index2] + " ");
                }
            }
            System.out.println();
        }
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
            System.out.println(" Matrices's order is not same ");
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
            System.out.println("Enter character to replace");
            String character = s.next();
            check_intersection(matrix1, matrix2, character);
        }
    }
}
/*
TEST CASES
INPUT
OOf First Matrix
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
4 0
1 2
 Enter elements of 2nd matrix 
4 9
3 2
Enter character to replace
%
OUTPUT
4 % 
% 2 
*/

