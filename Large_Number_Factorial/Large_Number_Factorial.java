// Calculating Lanrge Number factorial in Java Language

/*
Here i am using BigInteger class to store the big value of factorial.
*/
 
import java.math.BigInteger;
import java.util.Scanner;
public class fact{
   public static void main(String[] args) {
// Dynamic input using Scanner 
       Scanner x = new Scanner(System.in);
       System.out.print("Enter Number: ");
       int n=x.nextInt();
// Initialise BigInteger  -> fact with 1
       BigInteger fact = new BigInteger("1");
// multiplying every i with fact and store in fact upto n
       for(int i=2;i<=n;i++)
       {
           fact = fact.multiply(new BigInteger(i + ""));
       }
// print the fatorial value  
       System.out.println("Factorial is " + fact);
       }
}


/* 
Input :

Enter Number: 25

Output:

Factorial is 15511210043330985984000000

*/