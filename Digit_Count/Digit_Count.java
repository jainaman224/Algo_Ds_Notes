/*
DIGIT COUNT OF A NUMBER

The task is to count the number of digits present in the given
number.
*/

import java.util.Scanner;

class Solution {

    public static int getDigits(int n) {
        int ans = 0;
        while (n > 0) {
            ans ++;
            n /= 10;
        }
        return ans;
    }

    public static void main(String args[]) {
        System.out.print("Enter N: ");
        int n;
        Scanner s = new Scanner(System.in);
        n = s.nextInt();
        System.out.print("Number of digits is : " + getDigits(n));
    }
}

/*
INPUT : n = 6534
OUTPUT: Number of digits is : 4
*/
