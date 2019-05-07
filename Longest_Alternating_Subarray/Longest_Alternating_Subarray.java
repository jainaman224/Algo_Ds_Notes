/*
        LENGTH OF LONGEST ALTERNATING SUBARRAY

        Given an array of non-zero integers. We need to find the maximum 
        possible length of a subarray such that it has alternating positive
        and negative elements.
*/

import java.util.Scanner;

class Longest_Alternating_Subarray {

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
        int result = 1;
        int count = 1;
        System.out.print("The length of longest alternating subarray is : ");
        for (int i = 1; i < num; i++) {
            if (a[i] * a[i - 1] < 0) {
                count = count + 1;
                if (count > result) {
                    result = count;
                }
            }
            else {
                count = 1;
            }
        }
        System.out.print(result);
    }
}

/*
Input :
num = 4
Array = [-1, -4, -5, 20]

Output :

The length of longest alternating subarray is : 2
*/
