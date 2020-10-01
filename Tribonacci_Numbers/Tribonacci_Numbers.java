/*
TRIBONACCI NUMBERS

It is a series of numbers where each term is the sum of preceeding 3
numbers of the sequence.

T(n) = T(n-1) + T(n-2) + T(n-3)
*/

import java.util.Scanner;

class Tribonacci_Numbers {

    public static int tribonacci(int n) {
        int x = n - 3;
        if (x < 0) {
            return 0;
        }
        else if (x == 0) {
            return 1;
        }
        return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        System.out.print("The tribonacci number at position "
         + n + " is: " + tribonacci(n));
    }
}

/*
INPUT : n = 6
OUTPUT: The tribonacci number at position 6 is: 4
VERIFICATION: The tribonacci series : 0 0 1 1 2 4
*/
