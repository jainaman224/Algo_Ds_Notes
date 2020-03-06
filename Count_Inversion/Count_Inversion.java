/*
Counting inversion means finding how many elements are such that
a[i]>a[j] for i<j
brute force would be using O(n^2) approach.

we will try to implement it in O(nlogn) time using merge sort approach
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Count_Inversion {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("please enter length of array");
        int n = Integer.parseInt(br.readLine());
        System.out.println("Please enter the elements of array");
        int arr[] = new int[n];
        String input[] = br.readLine().split(" ");
        for(int i=0; i<n; i++){
            arr[i] = Integer.parseInt(input[i]);
        }


        System.out.println(countInversions(arr, 0, arr.length-1));
    }

    public static long countInversions(int[] arr, int low, int high){
        if(arr.length<2){
            return 0;
        }
        if(low<high){
            int mid = (low+high)/2;
            /*
            3 types of inversions:
            1. left inversion
            2. right inversion
            3. split inversions
             */
            return countInversions(arr,low,mid)+countInversions(arr,mid+1,high) +
                    merge(arr,low,mid,high);
        }
        return 0;
    }


    public static long merge(int[] arr, int low, int mid, int high){
        int count = 0;
        int n1 = mid-low+1;
        int n2 = high-mid;

        int i = 0;
        int j = 0;
        int k = low;

        int left[] = new int[n1];
        int right[] = new int[n2];

        for(int m=0; m<n1; m++){
            left[m] = arr[m+low];
        }

        for(int m=0; m<n2; m++){
            right[m] = arr[m+mid+1];
        }

        while (i<n1 && j<n2){
            if(left[i]<=right[j]){
                arr[k]=left[i];
                i++;
            }
            else{
                arr[k]=right[j];
                /*
                incrementing the count by all the elements in the left array because
                if current arr[i] is greater than arr[j], then all those that follow
                arr[i] in the left array will also be greater.
                 */
                count+=n1-i;
                j++;
            }
         k++;
        }

        while (i<n1){
            arr[k]=left[i];
            i++;
            k++;
        }

        while (j<n2){
            arr[k]=right[j];
            j++;
            k++;
        }
        return count;
    }
}
/*
input :
5
2 1 3 1 2

output :
4
 */