import java.util.Arrays;
import java.util.Scanner;

public class Aggressive_Cows {

    public static void main(String[] args) {

        /* in this problem we have to maximise the minimum distance between the
         * cows since minimum distance is being linearly checked we apply
         * binary search on minimum distance */

        Scanner scn = new Scanner(System.in);
        int nos = scn.nextInt(); // input for no. of stalls
        int noc = scn.nextInt(); // input for no. of cows

        int[] arr = new int[nos]; // storing the position of stalls in an array

        for (int i = 0; i < arr.length; i++) {
            arr[i] = scn.nextInt();
        }

        Arrays.sort(arr); // to sort the positions of stalls in ascending order

        int finalAns = 0;

        int lo = 0;
        int hi = arr[arr.length - 1] - arr[0];

        while (lo <= hi) {

            int mid = (lo + hi) / 2;

            if (isItPossible(nos, noc, arr, mid)) {

                finalAns = mid;
                lo = mid + 1;

            }else{
                hi = mid - 1;
            }
        }

        System.out.println(finalAns);

    }

    // function to check if a particular arrangement of cows is possible or not
    private static boolean isItPossible(int nos, int noc, int[] arr, int mid) {

        int cowsPlaced = 1;
        int lastCowPos = arr[0]; // position at which cow is placed

        for (int i = 1; i < arr.length; i++) {

            if (arr[i] - lastCowPos >= mid) {
                cowsPlaced++;
                lastCowPos = arr[i];

                if (cowsPlaced == noc) {
                    return true;
                }
            }
        }
        return false;
    }
}

// SAMPLE INPUT: 5 3
// 1
// 2
// 8
// 4
// 9
//
// Output:
// 3
