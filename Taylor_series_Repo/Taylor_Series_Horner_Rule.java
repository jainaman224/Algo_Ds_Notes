// Taylor series using Horner Rule in Java

import java.util.Scanner;

public class Test {
    static double s; // Declare static variable
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int num = sc.nextInt();
        double result = exponential(x, num);
        System.out.println(result);
    }

    // Declare the function for finding exponential
    public static double exponential(int x, int num) {
        if (num == 0) { // Base case
            return s;
        }
        s = 1 + x * (s / num); // formula of Horner's Rule
        return exponential(x, num - 1); // recursive case
    }
}

/* Input:- 2 10
   Output:- 7.388712522045855
*/
