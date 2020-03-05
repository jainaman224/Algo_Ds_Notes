
/**
 * Binary Insertion Sort
 * Author: Raktim Midya 
 * Date: 05/03/2020
*/

import java.util.Arrays;
import java.util.Scanner;

class BinaryInsertionSort {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the Length of the array:    ");
        int length = s.nextInt();
        int[] arr = new int[length];
        System.out.println("Enter the Elements of the array:");

        for (int i = 0; i < length; i++) {
            arr[i] = s.nextInt();
        }

        s.close();

        new GFG().sort(arr);

        System.out.print("The Sorted Array is: ");
        for (int i = 0; i < arr.length; i++)
            System.out.print(arr[i] + " ");
    }

    public void sort(int array[]) {
        for (int i = 1; i < array.length; i++) {
            int x = array[i];

            // Find location to insert using binary search
            int j = Math.abs(Arrays.binarySearch(array, 0, i, x) + 1);

            // Shifting array to one location right
            System.arraycopy(array, j, array, j + 1, i - j);

            // Placing element at its correct location
            array[j] = x;
        }
    }
}
