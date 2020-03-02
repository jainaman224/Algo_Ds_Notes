/*Suppose we know the number of inversions in the left half and right half of the array (let be inv1 and inv2),
what kinds of inversions are not accounted for in Inv1 + Inv2? The answer is – the inversions we have to count during the merge step.
Therefore, to get number of inversions, we need to add number of inversions in left subarray, right subarray and merge().
How to get number of inversions in merge()? In merge process, let i is used for indexing left sub-array and j for right sub-array.
At any step in merge(), if a[i] is greater than a[j], then there are (mid – i) inversions. because left and right subarrays are sorted,
so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j].*/


import java.util.*;
public class Solution {

    private static long countInversions(int[] arr) {
        int[] aux = arr.clone();
        return countInversions(arr, 0, arr.length - 1, aux);
    }

    private static long countInversions(int[] arr, int lo, int hi, int[] aux) {
        if (lo >= hi) return 0;

        int mid = lo + (hi - lo) / 2;

        long count = 0;
        count += countInversions(aux, lo, mid, arr);
        count += countInversions(aux, mid + 1, hi, arr);
        count += merge(arr, lo, mid, hi, aux);

        return count;
    }

    private static long merge(int[] arr, int lo, int mid, int hi, int[] aux) {
        long count = 0;
        int i = lo, j = mid + 1, k = lo;
        while (i <= mid || j <= hi) {
            if (i > mid) {
                arr[k++] = aux[j++];
            } else if (j > hi) {
                arr[k++] = aux[i++];
            } else if (aux[i] <= aux[j]) {
                arr[k++] = aux[i++];
            } else {
                arr[k++] = aux[j++];
                count += mid + 1 - i;
            }
        }

        return count;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            int n = in.nextInt();
            int arr[] = new int[n];
            for(int arr_i=0; arr_i < n; arr_i++){
                arr[arr_i] = in.nextInt();
            }
            System.out.println(countInversions(arr));
        }
    }
}



/*
Sample Input
2
4
1 2 4 3
3
3 2 1
Sample Output
1
3 */
