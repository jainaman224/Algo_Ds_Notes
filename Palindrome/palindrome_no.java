// Program to find whether a number is a palindrome or not
import java.util.Scanner;
public class palindrome_no {
	
	// Find reverse of a number
	public static int reverse(int num) {
		int rev = 0;
		while (num >0) {
			rev = rev*10 + num%10;
			num = num/10;
		}
		return rev;
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		System.out.println("Enter a number");
		int num  = s.nextInt();
		int reverseno = reverse(num);
		
		// Check whether the number entered is equal to reversed number or not
		if (reverseno == num) {
			System.out.println("Number entered is a palindrome");
		}
		else {
			System.out.println("Number entered is not a palindrome");
		}
	}
}

/*
Test cases
 
Enter a number
1223
Number entered is not a palindrome

Enter a number
1223221
Number entered is a palindrome
*/
