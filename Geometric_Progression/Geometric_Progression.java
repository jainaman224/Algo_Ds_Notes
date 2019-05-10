/*
        GEOMETRIC PROGRESSION

        Any sequence of elements where the quotient between any two 
        consecutive elements is equal is termed to be in G.P.
        The nth term of an G.P. is defined as (a * r^(n-1))
        where a is the first element of the G.P.
        r is the common ratio of the G.P.
*/

import java.util.Scanner;
import java.lang.Math;

class Geometric_Progression {
    
    public static void main(String args[]) {
        System.out.print("Enter the First Term of G.P.");
        int a;
        Scanner s = new Scanner(System.in);
        a = s.nextInt();
        System.out.print("Enter the common ratio");
        int r;
        r = s.nextInt();
        System.out.print("Enter N (The index of term to find)");
        int n;
        n = s.nextInt();
        System.out.print("The term at index " + n + " is " + (a * Math.pow(r, n - 1)));
    }
}

/*
    INPUT : a = 5
            r = 2
            n = 7
    OUTPUT : The term at index 7 is 320
    VERIFICATION : The G.P. would be 5,10,20,40,80,160,320...
*/
