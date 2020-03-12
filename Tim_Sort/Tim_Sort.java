// Tim sort implementation in java
import java.util.Scanner;
import static java.lang.Integer.min;

public class Main {

    // Merge Sort function
    public static void merge(int[] array, int left, int mid, int right) {
        int leftLength = mid - left + 1;
        int rightLength = right - mid;
        int[] Left = new int[leftLength];
        int[] Right = new int[rightLength];
        for (int i = 0; i < leftLength; i++)
            Left[i] = array[left + i];
        for (int i = 0; i < rightLength; i++)
            Right[i] = array[mid + 1 + i];
        int i = 0;
        int j = 0;
        int k = left;
        while (i < leftLength && j < rightLength) {
            if (Left[i] <= Right[j]) {
                array[k] = Left[i];
                i++;
            } else {
                array[k] = Right[j];
                j++;
            }
            k++;
        }
        while (i < leftLength) {
            array[k] = Left[i];
            k++;
            i++;
        }
        while (j < rightLength) {
            array[k] = Right[j];
            k++;
            j++;
        }

    }

    // Insertion Sort function
    public static void insertionSort(int[] array, int left, int right) {
        for (int i = left + 1; i <= right; i++) {
            int temp = array[i];
            int j = i - 1;
            while (j >= left && array[j] > temp) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = temp;
        }
    }

    public static void main(String[] args) {

        int n;
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter number of elements in your array: ");
        n = scanner.nextInt();
        int[] array = new int[n];
        System.out.println("Enter your array: ");
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        System.out.println("Unsorted Array :");
        for (int i = 0; i < n; i++)
            System.out.println(array[i]);
        int Limit = 32;
        for (int i = 0; i < n; i += Limit)
            insertionSort(array, i, min((i + 31), (n - 1)));

        for (int size = Limit; size < n; size = 2 * size) {
            for (int left = 0; left < n; left += 2 * size) {
                int mid = left + size - 1;
                int right = min((left + 2 * size - 1), (n - 1));
                merge(array, left, mid, right);
            }
        }
        System.out.println("Sorted Array :");

        for (int i = 0; i < n; i++)
            System.out.println(array[i]);
    }

  /*  Output -
        Enter number of elements in your array:
        6
        Enter your array:
        23
        5
        78
        46
        58
        14
        Unsorted Array :
        23
        5
        78
        46
        58
        14
        Sorted Array :
        5
        14
        23
        46
        58
        78
*/
