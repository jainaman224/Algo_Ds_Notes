/*
ROOT MEAN SQUARE

Root Mean Square or RMS is known as quadratic mean of a given array.
It holds a lot of importance in mathematical calculations in various 
domains like Physics and geometry.
*/

import java.util.Scanner;

class Root_Mean_Square {

    public static void RMS(int a[], int n, int index, int ans) {
        if (index == n) {
            ans = ans / n;
            System.out.print("RMS of array is : " + ans);
            return;
        }
        ans = ans + a[index] * a[index];
        RMS(a, n, index + 1, ans);
    }

    public static void main(String args[]) {
        int n;
        Scanner s = new Scanner(System.in);
        n = s.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = s.nextInt();
        }
        RMS(a, n, 0, 0);
    }
}

/*
INPUT : n = 3
        a = [3, 15, 32]
OUTPUT :
RMS of array is : 419
*/
