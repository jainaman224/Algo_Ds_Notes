/*
DISTANCE BETWEEN COORDINATES

Suppose you are given n co-ordinate points in a 2D plane. The task
is to find the total sum of distance between all those points.
Basically it is computing the perimeter of the complete polygon 
formed by those n co-ordinate points. 

For calculating the distance between two points (x1, y1) & (x2, y2),
we calculate -> sqrt((x1 - x2)^2 + (y1 - y2)^2)
*/

import java.util.Scanner;
import java.lang.Math;

class Distance_Between_Points {

    public static void main(String args[]) {
        int n;
        Scanner s = new Scanner(System.in);
        n = s.nextInt();
        int x[] = new int[n];
        int y[] = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = s.nextInt();
        }
        for (int i = 0; i < n; i++) {
            y[i] = s.nextInt();
        }
        double distance = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                float sq_x = Math.abs(x[i] - x[j]);
                float sq_y = Math.abs(y[i] - y[j]);
                distance = distance + Math.sqrt(sq_x * sq_x + sq_y * sq_y);
            }
        }
        System.out.print(distance);
    }
}

/*
INPUT :
n = 4
x = [1, 4, 3, 2]
y = [2, 5, 4, 1]
OUTPUT :
17.5339
*/
