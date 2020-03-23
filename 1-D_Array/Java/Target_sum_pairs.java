
//Java program to implement a program which prints all pairs of numbers which sum to target in an array.
import java.util.*;

public class Main {

	public static void main(String args[]) {

		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = scn.nextInt();
		int target = scn.nextInt();
		// sort array to apply 2 pointer approach
		Arrays.sort(a);
		// declare 2 pointers at beginning and end of the array
		int end = n - 1, start = 0;
		while (end > start) {
			int sum = a[start] + a[end];
			// if the target pair is found
			if (sum == target) {
				System.out.println(a[start] + " and " + a[end]);
				end--;
				start++;
			}
			// if the sum is less than target ,increment to find sum with larger number
			else if (sum < target) {
				start++;
			}
			// if the sum is more than target ,decrement to find sum with smaller number
			else
				end--;
		}
	}
}

/*
 * Sample Input: 5 1 3 4 2 5 5
 * 
 * Sample output: 
 1 and 4 
 2 and 3
 */
