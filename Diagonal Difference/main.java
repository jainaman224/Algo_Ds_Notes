public class main {
	
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
		int matrix[][] = 
		{
				{1, 2, 3},
				{4, 5, 6},
				{9, 8, 9}
				
		};
		
		System.out.print(differenceOfMatrix(matrix));
	}
}
