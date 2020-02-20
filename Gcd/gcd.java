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
		
		//variable to store gcd of given numbers
		int result;
		
		//calling gcd function
		if(num1 >= num2) {
			result = gcd_func(num1, num2);
		}else {
			result = gcd_func(num2, num1);
		}
		
		System.out.println("The GCD of given two numbers is " + result);
	}

}
