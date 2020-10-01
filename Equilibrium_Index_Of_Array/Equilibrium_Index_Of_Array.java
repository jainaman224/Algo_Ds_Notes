/*
    EQUILIBRIUM INDEX OF AN ARRAY

    An equilibrium index is an index of an array, where the commulative sum 
    of all elements below it is equal to the commulative sum of all elements
    above it in that array.

*/

import java.util.Scanner;

class Equilibrium_Index {
    
    public static int eq_index(int a[], int num) {
        int sum = 0;
        int sum_left = 0;
        for (int i = 0; i < num; i++) {
            sum = sum + a[i];
        }
        for (int i = 0; i < num; i++) {
            sum = sum - a[i];
            if (sum_left == sum) {
                return i;
            }
            sum_left = sum_left + a[i];
        }
        return -1;
    }

    public static void main(String args[]) {
        int num;
        System.out.print("Enter length of array");
        Scanner s = new Scanner(System.in);
        num = s.nextInt();
        System.out.print("Enter array elements :");
        int a[] = new int[num];
        for (int i = 0; i < num; i++) {
            a[i] = s.nextInt();
        }
        System.out.print("The equilibrium index is : " + eq_index(a, num));
    }
}

/*
    Input : num = 4
            Array : [12, 2, 6, 6]
    Output : The equilibrium index is : 1
*/
