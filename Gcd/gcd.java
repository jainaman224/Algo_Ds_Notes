/*
 * This program is based on Euclid's method to find the GCD of two numbers
 * 
 */

//importing files
import java.util.Scanner;

public class gcd {
	
	public static int gcd_func(int a, int b) {
		//base case
		if(b == 0) {
			return a;
		}
		return gcd_func(b, a%b);
	}

	public static void main(String[] args) {
		//taking input
		Scanner s = new Scanner(System.in);
		int num1 = s.nextInt();
		int num2 = s.nextInt();
		
		//function calling and storing gcd of given numbers to variable result
		int result = gcd_func(Math.max(num1, num2), Math.min(num1, num2));
		System.out.println("The GCD of given two numbers is " + result);
	}

}

/*
 * =============================================
 * Sample Input-Output
 * =============================================
 * Input : 2 6
 * Output : The GCD of given two numbers is 2
 * =============================================
 */
