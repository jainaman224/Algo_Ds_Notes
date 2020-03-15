// Java program to check if a number entered is a palindrome

import java.util.*;

public class palindrome_no {
	
    // Find reverse of a number
    public static int reverse(int number) {
        int reverseno = 0 ;
		
	while (number > 0) {
	    reverseno = (int) (reverseno * Math.pow(10, 1) + number % Math.pow(10, 1));
	    number = (int) (number / Math.pow(10, 1));
	}
	return reverseno;
    }

    public static void main(String[] args) {
	Scanner s = new Scanner(System.in);
	System.out.println(" Hey, Enter any number ");
	int enter_number  = s.nextInt();
	int reverseno = reverse(enter_number);
		
	// Check whether the number entered is equal to reversed number or not
	if (reverseno == enter_number) {
	    System.out.println("Number is a PALINDROME");
            return ;
	}
	System.out.println("Number is not a PALINDROME");
	return;
    }
}

/*
Test cases
INPUT
 Hey, Enter any number 
1223
OUTPUT
Number is not a PALINDROME

INPUT
 Hey, Enter any number 
1223221
OUTPUT
Number is a PALINDROME
*/
