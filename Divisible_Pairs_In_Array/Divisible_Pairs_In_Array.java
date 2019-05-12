/*
        DIVISIBLE PAIRS IN AN ARRAY

        The problem is to find all pairs of numbers in an array, such that
        one of those numbers divides the other.
*/

import java.util.Scanner;

class Divisible_Pairs {

    public static void main(String args[]) {
        int num;
        System.out.println("Enter the size of array : ");
        Scanner s = new Scanner(System.in);
        num = s.nextInt();
        int a[] = new int[num];
        System.out.println("Enter array elements");
        for (int i = 0; i < num; i++) {
            a[i] = s.nextInt();
        }
        System.out.println("The following are the divisible pairs :\n");
        for (int i = 0; i < num; i++) {
            for (int j = i + 1; j < num; j++) {
                if (a[i] % a[j] == 0 || a[j] % a[i] == 0) {
                    System.out.println(a[i] + " " + a[j]);
                }
            }
        }
    }
}

/*
Input :
num = 4
Array = [1, 4, 5, 20]

Output : 

The following are the divisible pairs :
1 4
1 5
1 20
4 20
5 20
*/
