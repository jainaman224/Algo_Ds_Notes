//Recursive algorithm to find factorial of a number

import java.util.Scanner;

public class Factorial_recursive {

	public static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {
		int n = scn.nextInt();
		System.out.println(Fact(n));
	}

	public static int Fact(int n) {
		// base case
		if (n <= 1)
			return 1;

		int smallAns = Fact(n - 1);
		return smallAns * n;

	}
}

/*
 * Sample Input: 5 
 * Sample Output: 120
 */
