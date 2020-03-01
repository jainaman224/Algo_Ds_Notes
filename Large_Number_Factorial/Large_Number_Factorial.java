// Calculating Lanrge Number factorial in Java Language

import java.math.BigInteger;
import java.util.Scanner;
public class fact{
   public static void main(String[] args) {
       Scanner s = new Scanner(System.in);
       System.out.print("Enter a number: ");
       int n = s.nextInt();
       String fact = factorial(n);
       System.out.println("Factorial is " + fact);
   }
   public static String factorial(int n) {
       BigInteger fact = new BigInteger("1");
       for (int i = 1; i <= n; i++) {
           fact = fact.multiply(new BigInteger(i + ""));
       }
       return fact.toString();
   }
}

/* 
Input :

Enter a number: 25

Output:

Factorial is 15511210043330985984000000

*/