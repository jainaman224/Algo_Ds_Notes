/*
CELEBRITY PROBLEM

In a group of N people, there is 1 person, who is known to everyone, but
he knows noone.
We need to find such a person, if present.

There will be a matrix input, such that M[i][j] = 1, if ith person
knows jth person, else 0.
*/

import java.util.Scanner;

class Solution {

    public static int Celebrity(int Person[][], int n) {
        int start = 0;
        int end = n - 1;
        while(true) {
            if (start == end) {
                break;
            }
            if (Person[start][end] == 1) {
                start++;
            }
            else {
                end--;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i == start) {
                continue;
            }
            if (Person[start][i] == 1 || Person[i][start] == 0) {
                return -1;
            }
        }
        return start;
    }

    public static void main(String args[]) {
        int n;
        Scanner s = new Scanner(System.in);
        n = s.nextInt();
        int Person[][] = new int[n][100];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                Person[i][j] = s.nextInt();
            }
        }
        int celeb = Celebrity(Person, n);
        if (celeb >= 0) {
            System.out.print("Celebrity Present at index " + celeb);
        }
        else {
            System.out.print("Celebrity not present");
        }
    }
}

/*
INPUT : n = 5
Person = 0 1 0 0 1
         0 0 0 0 0
         1 1 1 0 0
         1 1 0 0 1
         0 1 1 1 0
OUTPUT :
Celebrity Present at index 1
*/
