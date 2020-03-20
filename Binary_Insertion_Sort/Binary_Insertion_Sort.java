




import java.util.Arrays;
import java.util.Scanner;

class BinaryInsertionSort {
    public static void main(String[] args) {

        //Taking Input from User for Array Length
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the Length of the array:    ");
        int length = s.nextInt();

        //Initialized new array
        int[] arr = new int[length];

        System.out.println("Enter the Elements of the array:");

        //Taking Input from User for Array Elements
        for (int i = 0; i < length; i++) {
            arr[i] = s.nextInt();
        }

        s.close();

        new BinaryInsertionSort().binary_insertion_sort(arr);

        System.out.print("The Sorted Array is: ");
        for (int i = 0; i < arr.length; i++)
            System.out.print(arr[i] + " ");
    }

    public void binary_insertion_sort(int array[]) {
        for (int i = 1; i < array.length; i++) {
            int x = array[i];

            int j = Math.abs(Arrays.binarySearch(array, 0, i, x) + 1);

            System.arraycopy(array, j, array, j + 1, i - j);

            array[j] = x;
        }
    }
}

/*
 * Sample Input:
 * 
 * Enter the Length of the array:    5
 * Enter the Elements of the array:
 * 24
 * 63
 * 25
 * 82
 * 63
 * 
 * Sample Output:
 * 
 * The Sorted Array is: 24 25 63 63 82
*/
