/*
    PERFECT ARRAY

    An array which is strictly increasing and then constant, and then strictly 
    decreasing is called a perfect array.
    There should be no variations in between.

*/

import java.util.Scanner;

class PerfectArray {
    
    public static int perfect(int a[], int num) {
        int count = 1;
        while (count < num && a[count] > a[count - 1]) {
            count++;
        }
        while (count < num && a[count] == a[count - 1]) {
            count++;
        }
        while (count < num && a[count] < a[count - 1]) {
            count++;
        }
        if (count == num) {
            return 1;
        }
        return 0;
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
        if (perfect(a, num) == 1) {
            System.out.print("It is a perfect array");
        }
        else {
            System.out.print("It is not a perfect array");
        }
    }
}

/*
    Input : num = 5
            Array : [1, 2, 3, 3, 6]
    Output : It is not a perfect array
*/
