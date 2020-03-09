/*
PARTIAL DEARRANGEMENTS

A partial dearrangement is a dearrangement where some points are
fixed. That is, given a number n and a number k, we need to find
count of all such dearrangements of n numbers, where k numbers are
fixed in their position.
*/

import java.util.Scanner;

class Partial_Dearrangement {

    public static int mod = 1000000007;

    public static int nCr(int n, int r, int mod) {
        if (n < r) {
            return -1;
        }
        // We create a pascal triangle.
        int Pascal[] = new int[r + 1];
        Pascal[0] = 1;
        for (int i = 1; i <= r; i++) {
            Pascal[i] = 0;
        }
        
        // We use the known formula nCr = (n-1)C(r) + (n-1)C(r-1) 
        // for computing the values.
        for (int i = 1; i <= n; i++) {
            int k = (i < r) ? (i) : (r); 
            // we know, nCr = nC(n-r). Thus, at any point we only need min
            for (int j = k; j > 0; j--) { 
                // of the two, so as to improve our computation time.
                Pascal[j] = (Pascal[j] + Pascal[j - 1]) % mod;
            }
        }
        return Pascal[r];
    }

    public static int count(int n, int k) {
        if (k == 0) {
            if (n == 0) {
                return 1;
            }
            if (n == 1) {
                return 0;
            }
            return (n - 1) * (count(n - 1, 0) + count(n - 2, 0));
        }
        return nCr(n, k, mod) * count(n - k, 0);
    }

    public static void main(String args[]) {
        int number;
        Scanner s = new Scanner(System.in);
        number = s.nextInt();
        int k;
        k = s.nextInt();
        int dearrangements = count(number, k);
        System.out.print("The number of partial dearrangements is " + dearrangements);
    }
}

/*
INPUT : n = 6
        k = 3
OUTPUT: The number of partial dearrangements is 40
*/
