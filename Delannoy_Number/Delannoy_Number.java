/*
DELANNOY NUMBER

This number denotes the number of different paths available from
bottom-right corner of a grid i.e. (0,0) to top-left corner (m,n).
The constraint is that we can only use a step east, north or,
north-east(diagonal).
*/

import java.util.Scanner;

class Delannoy_Number {

    public static int check(int x, int y, int row, int col) {
        if (x == row - 1 && y == col - 1) {
            return 1;
        }
        if (x == row || y == col) {
            return 0;
        }
        return check(x + 1, y, row, col) +
        check(x, y + 1, row, col) + 
        check(x + 1, y + 1, row, col);
    }

    public static void main(String args[]) {
        int row, col;
        Scanner s = new Scanner(System.in);
        row = s.nextInt();
        col = s.nextInt();
        System.out.print("The number of paths is " + check(0, 0, row, col));
    }
}

/*
INPUT :
row = 3
col = 5
OUTPUT :
The number of paths is 41
*/
