/*
    LEADERS OF AN ARRAY

    The task is to find all leaders in an array, where
    a leader is an array element which is greater than all the elements
    on its right side
*/

import java.util.Scanner;

class Leaders_Of_Array {

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
        int maximum = a[num - 1];
        System.out.println("The following are the leaders of array : ");
        System.out.print(a[num - 1] + " ");
        for (int i = num - 2; i >= 0; i--) {
            if (a[i] > maximum) {
                System.out.print(a[i] + " ");
            }
        }
    }
}

/*
Input : num = 5
        Array = [13, 4, 12, 1, 5]
Output :
        The following are the leaders of array : 
        5 12 13
*/
