/*
DEARRANGEMENTS

It is a permutation of N elements such that no element appears in 
its original position.
We have to find the number of such permutations possible.

If count(n) = no of dearrangements for n numbers,
we use the generic formula 
count(n) = (n - 1) * [count(n - 1) + count(n - 2)]
*/

import java.util.Scanner;

class Dearrangements {

    public static int count(int number) {
        if (number <= 2) {
            return (number + 1) % 2;
        }
        int last = count(number - 1);
        int secondLast = count(number - 2);
        return (number - 1) * (last + secondLast);
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int number = s.nextInt();
        int dearrangements = count(number);
        System.out.print("The number of dearrangements is " + 
        dearrangements);
    }
}

/*
INPUT : n = 6
OUTPUT: The number of dearrangements is 265
*/
