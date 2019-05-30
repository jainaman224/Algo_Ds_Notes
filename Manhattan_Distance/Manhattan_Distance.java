/*
MANHATTAN DISTANCE

In a 2D plane, the manhattan distance is equal to the distance needed
to be covered using only vertical and horizontal steps.

M(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|

Given an array of co-ordinates. find the sum of manhattan distances 
of all the coordinates with each other.
*/

import java.util.Scanner;

class Manhattan_Distance {

    public static int Manhattan(int x[], int y[], int i, int j) {
        return (Math.abs(x[i] - x[j]) + Math.abs(y[i] - y[j]));  
    }

    public static int ManhattanSum(int x[], int y[], int n) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = ans + Manhattan(x, y, i, j);
            }
        }
        return ans;
    }

    public static void main(String args[]) {
        int n;
        Scanner scan = new Scanner(System.in);
        n = scan.nextInt();
        int x[] = new int[n];
        int y[] = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = scan.nextInt();
        }
        for (int i = 0; i < n; i++) {
            y[i] = scan.nextInt();
        }
        System.out.print(ManhattanSum(x, y, n));
    }
}

/*
INPUT
x = [3, 3, 2, -2]
y = [6, -5, 0, 2]
OUTPUT
51
*/
