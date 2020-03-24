//Java program to check if a string is a Palindrome

import java.util.*;

public class reverse_string {
	
    // Reverse a given string
    public static String palindrome(String string_entered) {
        String str_reversed  = "";
	int length_of_String = string_entered.length()-1;
	int len = 0;

	for (len = length_of_String; len >= 0 ; len --)
	    str_reversed = str_reversed + string_entered.charAt(len);
	return str_reversed;
    }

    public static void main(String[] args) {
		
	Scanner s = new Scanner(System.in);
	System.out.println(" Hey,Enter any string ");
	String string_entered = s.nextLine();
	String str_reversed = palindrome(string_entered);
		
	// Comparing 2 strings to find if input string is palindrome or not
	if(string_entered.equals(str_reversed)) {
	    System.out.println(" String is a PALINDROME ");
	}
	else {
	    System.out.println(" String is not a PALINDROME ");
	}
    }
}

/*
Test cases
 
INPUT
 Hey,Enter any string 
hello
OUTPUT
 String is not a PALINDROME 

INPUT
 Hey,Enter any string 
metem
OUTPUT
 String is a PALINDROME 
*/

