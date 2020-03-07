/*
 * A Dynamic Programming approach to find the minimum(optimal) number of operations required to multiply a chain of matrices
 * Time complexity = O(n^3)
 * Space complexity = O(n^2)
 */

import java.util.Scanner;

public class matrixChainMultiplication { 
	
	//function to find the optimized number of operations required for multiplication using DP
	static int orderOfMultiplication(int arr[]) { 
		int size = arr.length;
		
		//2D array to store optimal solution for all i
		int dp[][] = new int[size][size]; 
		
		// cost will be zero for multiplying one matrix
		for (int i=1; i<size; i++) { 
			dp[i][i] = 0; 
		}
		
		// l is the chain length
		for (int l=2; l<size; l++) { 
			for (int i=1; i<size-l+1; i++){ 
				int j = i+l-1; 
				if(j == size) {
					continue; 
				}
				dp[i][j] = Integer.MAX_VALUE; 
				for (int k=i; k<=j-1; k++) { 
					// temp is cost/scalar multiplications 
					int temp = dp[i][k] + dp[k+1][j] + (arr[i-1] * arr[k] * arr[j]); 
					
					//if this order gives better solution
					if (temp < dp[i][j]) {
						//update dp[i][j]
						dp[i][j] = temp; 
					}
				} 
			} 
		} 
		//optimal solution for the chain multiplication will be at the dp[1][size-1]
		return dp[1][size-1]; 
	} 

	//Main function
	public static void main(String args[]) { 
		Scanner s = new Scanner(System.in);
		System.out.print("Enter size of array - ");
		int size = s.nextInt();
		
		//storing matrices sizes given by user
		int arr[] = new int[size];
		System.out.print("Enter values of array - ");
		for(int i=0; i<size; i++) {
			arr[i] = s.nextInt();
		}
		
		//function calling
		int ans = orderOfMultiplication(arr); 
		System.out.println("Minimum number of operations required - " + ans);
		s.close();
	} 
} 

/*
 * =========================================================
 * Sample Input-Output
 * =========================================================
 * Input :  Enter size of array - 4
 * 			Enter values of array - 2 4 6 8
 * Output : Minimum number of operations required - 144
 * =========================================================
 */
