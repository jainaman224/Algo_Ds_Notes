/**
 * Created by vampire-slayer on 29/10/16.
 * Java solution to the Knapsack problem using dynamic programming
 */

public class KnapsackProblem {

	public static int knapsack(int w, int[] weights, int[] values, int n) {

		int i, j;
		int[][] DP = new int[n + 1][w + 1];

		for (i = 0; i <= n; i++) {

			for (j = 0; j <= w; j++) {

				if (i == 0 || j == 0)
					DP[i][j] = 0;
				else if (weights[i - 1] <= j)
					DP[i][j] = Math.max(values[i - 1] + DP[i - 1][j - weights[i - 1]], DP[i - 1][j]);
				else
					DP[i][j] = DP[i - 1][j];
			}
		}

		return DP[n][w];
	}

	public static void main (String[] args) {

		int[] values = {11, 22, 33, 44, 55};
		int[] weights = {111, 121, 131, 141, 151};
		int w = 300;
		int n = weights.length;

		System.out.println(knapsack(w, weights, values, n));
	}
}

/* Output

99

*/
