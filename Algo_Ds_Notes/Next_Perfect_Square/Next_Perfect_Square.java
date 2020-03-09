/*
NEXT PERFECT SQUARE

A perfect square is a number which can be expressed as a product of 
two equal numbers. The task is to find the first such number greater 
than the given number.
*/

import java.util.Scanner;
import java.lang.Math;

class Next_Perfect_Square {
    
    public static void main(String args[]) {
        System.out.print("Enter N: ");
        int n;
        Scanner s = new Scanner(System.in);
        n = s.nextInt();
        int x = (int)Math.floor(Math.sqrt(n)) + 1;
        System.out.print("The next perfect square is " + (x * x));
    }
}

/*
    INPUT : n = 1091
    OUTPUT: The next perfect square is 1156
    VERIFICATION : 1156 = 34 * 34
                   Hence it is a perfect square.
*/
