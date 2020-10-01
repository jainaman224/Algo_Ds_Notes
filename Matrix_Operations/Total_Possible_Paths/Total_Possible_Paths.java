/*
TOTAL PATHS FROM (0, 0) to (m, n)

The task is to calculate total possible moves we can make to reach
(m, n) in a matrix, starting from origin, given that we can only take
1 step towards right or up in a single move.
*/

import java.util.Scanner;

public class Solution {

    public static int totalPaths(int m, int n) {
        int total[][] = new int[100][100];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total[i][j] = 0;
            }
        }
        int mx = (m > n) ? (m) : (n);
        for (int i = 0; i < mx; i++) {
            if (i < m) {
                total[i][0] = 1;
            }
            if (i < n) {
                total[0][i] = 1;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                total[i][j] = total[i - 1][j] + total[i][j - 1];
            }
        }
        return total[m-1][n-1];
    }

    public static void main(String args[]) {
        int m, n;
        Scanner s = new Scanner(System.in);
        m = s.nextInt();
        n = s.nextInt();
        System.out.print("The total paths are " + totalPaths(m, n));
    }
}

/*
INPUT :
n = 6
m = 5
OUTPUT :
The total paths are 126
*/
