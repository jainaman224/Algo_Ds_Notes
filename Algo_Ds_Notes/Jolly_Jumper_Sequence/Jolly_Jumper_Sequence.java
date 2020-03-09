/*
JOLLY JUMPER SEQUENCE

If the set of differences of consecutive elements of the sequence
varies from 1 to n - 1, the sequence formed is said to be Jolly Jumper
Sequence.
*/

import java.util.Scanner;
import java.lang.Math;

class Solution {

    public static int Jolly(int a[], int n) {
        int check[] = new int[n];
        for (int i = 0; i < n; i++) {
            check[i] = 0;
        }
        for (int i = 1; i < n; i++) {
            int x = Math.abs(a[i] - a[i - 1]);
            if (x == 0 || x > n - 1 || check[x] == 1) {
                return 0;
            }
            check[x] = 1;
        }
        return 1;
    }

    public static void main(String args[]) {
        int n;
        Scanner s = new Scanner(System.in);
        n = s.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = s.nextInt();
        }
        if (Jolly(a, n) == 1) {
            System.out.print("It is a jolly jumper sequence");
        }
        else {
            System.out.print("It is not a jolly jumper sequence");
        }
    }
}

/*
INPUT :
n = 6
a = [14 9 13 12 10 7]
OUTPUT :
It is a jolly jumper sequence
*/
