/*
CYCLIC PERMUTATIONS

Cyclic permutations of a number are defined as a number that
can be obtained by rotating the concerned number any number 
of times between it's digits.
*/

import java.util.Scanner;

class Cyclic_Permutation {

    public static int getDigits(int n) {
        int ans = 0;
        while (n > 0) {
            ans ++;
            n /= 10;
        }
        return ans;
    }

    public static void cyclic(int n) {
        int length = getDigits(n);
        int res = n;
        while (true) {
            System.out.println(res);
            int remainder = res % 10;
            int quotient = res / 10;
            res = remainder * (int) Math.pow(10, length - 1) + quotient;
            if (res == n) {
                break;
            }
        }
    }
    
    public static void main(String args[]) {
        System.out.print("Enter N:");
        int n;
        Scanner s = new Scanner(System.in);
        n = s.nextInt();
        cyclic(n);
    }
}

/*
INPUT : n = 6
OUTPUT : 2 1 4 3 6 5
*/
