/*
SUM OF INFINITE GEOMETRIC PROGRESSION

Any sequence of elements where the quotient between any two
consecutive elements is equal is termed to be in G.P.
The nth term of an G.P. is defined as (a * r^(n-1))
where a is the first element of the G.P.
r is the common ratio of the G.P.
n is the number of term.

The Sum of infinite series of a G.P. is defined as :
a / (1 - r), where -1 < r < 1
*/

import java.util.Scanner;

class Sum_Of_Infinite_GP {
    
    public static void main(String args[]) {
        System.out.print("Enter the First Term of G.P.");
        float a;
        Scanner s = new Scanner(System.in);
        a = s.nextFloat();
        System.out.print("Enter the common ratio");
        float r;
        r = s.nextFloat();
        System.out.print("The sum of infinite G.P. is " + (a * 1.0 / (1 - r)));
    }
}

/*
INPUT : a = 5
        r = 0.5
OUTPUT : The sum of infinite G.P. is 10.0
*/
