// Java Program to calculate number of sub - matrices (2D Array) having their sum divisible by a given number
import java.util.Scanner;

public class Matrix_divisible_by_num {

    public static int Submatrix(int[][] matrix, int order, int number) {

        int total = 0;
        int[] oned_temp = new int[order];

        int index1, index2;
        for ( index1 = 0; index1 < order; index1++) {
            for ( index2 = index1; index2 < order; index2++ ) {
                for (int row = 0; row < order; row++ ) {
                    oned_temp[row] += matrix[row][index2];
                }
                // Calculating total number of possible sub matrices
                total += count_sub_matrix(oned_temp, order, number);
            }
        }
        return total;
    }

    public static int count_sub_matrix(int[] temp_matrix, int order, int number){

        int[] temp_mat1 = new int[number];
        int sum = 0;
        int index1 = 0;
        for (index1 = 0; index1 < order; index1++) {
            sum += temp_matrix[index1];
            // To make sum positive in each case, taking modulo twice
            temp_mat1[((sum % number) + number) % number]++;
        }

        int answer = 0;
        for ( index1 = 0; index1 < number; index1++) {
            if (temp_mat1[index1] > 1) {
                answer += (temp_mat1[index1] * (temp_mat1[index1] - 1)) / 2;
            }
        }
        answer += temp_mat1[0];
        return answer;
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter equal number of rows and columns");
        System.out.println(" Enter number of rows ");
        int rows = s.nextInt();

        System.out.println(" Enter number of columns ");
        int columns = s.nextInt();

        if (rows != columns){
            System.out.println("Rows and columns aren't equal! So, we can't proceed.");
            return;
        }
        int[][] matrix = new int[rows][columns];

        System.out.println(" Enter elements of matrix ");
        for (int i = 0; i < rows; i++) {
            for (int j = 0 ; j < columns; j++) {
                matrix[i][j] = s.nextInt();
            }
        }
        System.out.println("Enter a number");
        int num = s.nextInt();
        int ans = Submatrix(matrix, rows, num);
        System.out.println("Ans is "+ ans);
    }
}
/*
TEST CASES
INPUT
 Enter equal number of rows and columns
 Enter number of rows
4
 Enter number of columns
4
 Enter elements of matrix
2 -1 5 0
4 6 7 2
0 0 0 1
3 6 -1 2
Enter a number
1
OUTPUT
Ans is 100
*/

