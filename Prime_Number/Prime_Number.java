import java.util.Scanner; 
import java.lang.Math; 

public class Prime_Number {
    static boolean Prime(int num, int i) { 
        if (num == 1)
            return false;

        // Base case
        if (i <= 1) 
            return true;

        // Checking if i is a divisor of num or not
        if (num % i == 0) 
            return false; 

        // Calling recursive function
        return Prime(num, i - 2); 
    } 

    // Driver program 
    public static void main(String[] args) { 
        Scanner input = new Scanner(System.in);    	
        int num = input.nextInt();

        if (num == 2)
            System.out.println("It is a prime number");
        else if (num % 2 == 0)
            System.out.println("It is not a prime number");
               
        if (Prime(num, Math.sqrt(num))) 
            System.out.println("It is a prime number"); 
        else
            System.out.println("It is not a prime number"); 
    } 
} 

// Input: 29
// Output: It is a prime number
