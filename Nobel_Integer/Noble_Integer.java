/*An integer x is said to be Noble given an array if the 
number of integers greater than x are equal to x. 
If there are many Noble integers, any of them is returned. 
If there is no noble integer, then return -1.*/

import java.io.*;
import java.util.*;

class Noble_Integer
{
    static int Noble(ArrayList<Integer> A, int n) {
    if (n == 0) {
        return -1;
    }
    Collections.sort(A);
    for (int i = 0; i < n - 1; i++) {
        if (A.get(i) == A.get(i + 1)) {
            continue;
        }
        if (A.get(i) == n - (i + 1)) {
            return A.get(i);
        }
    }
    if (A.get(n - 1) == 0) {
        return A.get(n - 1);
    }
    return -1;
}
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of the array : ");
        int n = sc.nextInt();
        ArrayList<Integer> A = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            A.add(sc.nextInt());
        }
        System.out.println("Noble Integer = "+Noble(A, n));
    }
}

/*
Input :
Enter the size of array : 6
3 2 5 6 1 4
Output :
Noble Integer = 3

Input : 
Enter the size of array : 3
2 2 2
Output :
Noble Integer = -1
*/
