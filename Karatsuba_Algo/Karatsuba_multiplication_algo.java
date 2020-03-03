/**
* The Karatsuba algorithm is a multiplication algorithm developed by Anatolii Alexeevitch 
  Karatsuba in 1960.
* It operates in O(n^log2(3)) time (~ O(n^1.585)), with n being the number of digits of the 
  numbers we are multiplying together.
* Standard grade-school multiplication operates in O(n^2) time. Karatsuba's method is 
  asymptotically much faster.
* Normally, you can choose any base you want, but we will be using base 10 in this algorithm 
  with m varying depending on the length of the inputs.
* Specific details are included with an example in the comments before the actual method.

**/
import java.util.*;

public class Karatsuba{
    /** Function to multiply two numbers **/
    public long multiply(long x, long y){
        int size1 = getSize(x);
        int size2 = getSize(y);

        /** Maximum of lengths of number **/
        int N = Math.max(size1, size2);

        /** for small values directly multiply **/        
        if (N < 10)
            return x * y;
        /** max length divided, rounded up **/    
        N = (N / 2) + (N % 2);    
        /** multiplier **/
        long m = (long)Math.pow(10, N);

        /** compute sub expressions **/        
        long b = x / m;
        long a = x - (b * m);
        long d = y / m;
        long c = y - (d * N);

        /** compute sub expressions **/
        long z0 = multiply(a, c);
        long z1 = multiply(a + b, c + d);
        long z2 = multiply(b, d);

        return z0 + ((z1 - z0 - z2) * m) + (z2 * (long)(Math.pow(10, 2 * N)));        

    }

    /** Function to calculate length or number of digits in a number **/
    public int getSize(long num){
        int ctr = 0;
        while (num != 0){
            ctr++;
            num /= 10;
        }
        return ctr;
    }

    /** Main function **/
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Karatsuba Multiplication Algorithm");

        /** Make an object of Karatsuba class **/
        Karatsuba kts = new Karatsuba();

        /** Accept two integers **/
        System.out.println("Enter two integer numbers");
        long n1 = scan.nextLong();
        long n2 = scan.nextLong();

        /** Call function multiply of class Karatsuba **/
        long product = kts.multiply(n1, n2);
        System.out.println("\nProduct of the two number is : "+ product);
    }
}


/**
 * INPUT
 * Enter two integer numbers
    24869
    24513

 * OUTPUT
    Product of the two number is : 609613797
 */