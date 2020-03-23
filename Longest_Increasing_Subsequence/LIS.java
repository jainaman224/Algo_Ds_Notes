/*
Problem Statement :
To find the length of the Longest Increasing
Subsequence of a given sequence, that is all the
elements of the subsequence are in increasing sorted order.
*/

import java.util.*;

class LIS
{
	static int lis(int arr[], int n)
	{
		int lis[] = new int[n];
		int result = Integer.MIN_VALUE;

		for (int i = 0; i < n; ++i)
			lis[i] = 1;

		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
					lis[i] = lis[j] + 1;
			}
			result = Math.max(result, lis[i]);
		}

		return result;
	}

	public static void main(String args[])
	{
	    Scanner sc = new Scanner(System.in);

	    System.out.println("Enter the size of array : ");
		int n = sc.nextInt();

		int[] arr = new int[n];
		System.out.println("Enter the array elements : ");
		for (int i = 0; i < n; ++i)
		    arr[i] = sc.nextInt();

		System.out.println("\nLength of the Longest Increasing Subsequence : " + lis(arr, n));
	}
}

/*
Enter the size of the array : 8
Enter the array elements : 15 26 13 38 26 52 43 62

Length of the Longest Increasing Subsequence : 5
*/
