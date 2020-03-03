import java.util.Scanner;

public class Diagonal_Difference {
	
	public static int differenceOfMatrix(int matrix[][]) {
		int length = matrix.length;
		int sumLeftToRight = 0;
		int sumRightToLeft = 0;
		
		for(int i =0; i< matrix.length;i++) { 
			sumLeftToRight += matrix[i][i]; 
			sumRightToLeft += matrix[length-1-i][i];
		}
		
		return Math.abs(sumLeftToRight-sumRightToLeft);
	}

	public static void main(String args[]) {
		
		Scanner sc = new Scanner(System.in);
		int size = sc.nextInt(); //input size of matrix
		
		int number[][] = new int[size][size]; 
		
		 for(int a = 0; a < size; a++) //input matrix
	      {
	         for(int b = 0; b < size; b++)
	         {
	            number[a][b] = sc.nextInt();
	         }
	      }
		
		System.out.print(differenceOfMatrix(number)); //output: diagonal difference
		
	}
}


/** 
Input matrix: 
3

11 2 4
4 5 6
10 8 -12

Output: 15

**/
