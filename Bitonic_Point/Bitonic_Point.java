/*
BITONIC POINT

Given an array. The task is to find the bitonic point of the array.
The bitonic point in an array is the index before which all the numbers
are in increasing order and after which, all are in decreasing order.
*/

import java.util.Scanner;
import java.lang.Math;

class Bitonic_Point {

    public static int bitonic(int a[], int n) {
        int l = 1;
        int r = n - 2;
        while(l <= r) {
            int m = (l + r) / 2;
            if (a[m] > a[m - 1] && a[m + 1] < a[m]) {
                return m;
            }
            if (a[m] < a[m + 1]) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return -1;
    }

    public static void main(String args[]) {
        int n;
        Scanner s = new Scanner(System.in);
        n = s.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = s.nextInt();
        }
        int point = bitonic(a, n);
        if (point == -1) {
            System.out.print("There is no bitonic point");
        }
        else {
            System.out.print("The bitonic point is " + point);
        }
    }
}

/*
INPUT :
n = 6
a = [1 4 8 4 2 1]
OUTPUT :
The bitonic point is 2
*/
