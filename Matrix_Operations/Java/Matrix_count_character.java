// Java Program to calculate the count of a character in the matrix
import java.util.Scanner;

public class Count_Character {

    //Calculating count of the required character
    public static void count_character(int[][] matrix, int character){
        int index1, index2, count = 0;
        for ( index1 = 0; index1 < matrix.length; index1++){
            for ( index2 = 0; index2 < matrix[0].length; index2++) {
                if (matrix[index1][index2] == character) {
                    count++;
                }
            }
        }
        System.out.println(count);
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
            for (int j = 0; j< columns; j++) {
                matrix[i][j] = s.nextInt();
            }
        }
        System.out.println("Enter character whose count is to be calculated");
        int character = s.nextInt();
        count_character(matrix,character);
    }
}
/*
TEST CASES

INPUT
 Enter number of rows
2
 Enter number of columns
4
 Enter elements of matrix
1 2 3 1
3 4 2 1
Enter character whose count is to be calculated
1

OUTPUT
3

INPUT
 Enter number of rows
2
 Enter number of columns
3
 Enter elements of matrix
2 3 2
1 2 3
Enter character whose count is to be calculated
8

OUTPUT
0
*/

