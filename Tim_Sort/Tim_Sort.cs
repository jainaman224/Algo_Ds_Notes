/*
Tim Sort is a sorting algorithm based on Insertion Sort and Merge Sort.It first sort small pieces using Insertion Sort and then merges
the pieces using merge of merge sort.
*/

using System;
using System.IO;

class TimSort 
{ 
	public const int RUN = 32; 

	// Insertion Sort Function
	public static void Insertion_Sort(int[] arr, int left, int right) 
	{ 
		for (int i = left + 1; i <= right; ++i) 
		{ 
			int temp = arr[i]; 
			int j = i - 1; 

			while (j >= left && arr[j] > temp) 
			{ 
				arr[j+1] = arr[j]; 
				j--; 
			} 

			arr[j+1] = temp; 
		} 
	} 

	// Merge sort function  
	public static void Merge(int[] arr, int l, int m, int r) 
	{ 

		int len1 = m - l + 1, len2 = r - m; 

		int[] left = new int[len1]; 
		int[] right = new int[len2]; 

		for (int i = 0; i < len1; ++i) 
			left[i] = arr[l + i]; 

		for (int i = 0; i < len2; ++i) 
			right[i] = arr[m + 1 + i]; 

		int x = 0; 
		int y = 0; 
		int k = l; 

		while (x < len1 && y < len2) 
		{ 
			if (left[x] <= right[y]) 
			{ 
				arr[k] = left[x]; 
				x++; 
			} 
			else
			{ 
				arr[k] = right[y]; 
				y++; 
			} 
			k++; 
		} 

		while (x < len1) 
		{ 
			arr[k] = left[x]; 
			k++; 
			x++; 
		} 

		while (y < len2) 
		{ 
			arr[k] = right[y]; 
			k++; 
			y++; 
		} 
	} 

	public static void Tim_Sort(int[] arr, int n) 
	{ 

		for (int i = 0; i < n; i+=RUN) 
			Insertion_Sort(arr, i, Math.Min((i+31), (n-1))); 

		for (int size = RUN; size < n; size = 2*size) 
		{ 
			for (int left = 0; left < n; left += 2*size) 
			{ 
				int mid = left + size - 1; 

				int right = Math.Min((left + 2*size - 1), (n-1)); 

				Merge(arr, left, mid, right); 
			} 
		} 
	} 

	// Function to print the Array 
	public static void printArray(int[] arr, int n) 
	{ 
		for (int i = 0; i < n; ++i) 
			Console.Write(arr[i] + " "); 

		Console.Write("\n"); 
	} 

	public static void Main(string[] args) 
	{ 
	    int n = Convert.ToInt32(Console.ReadLine());

        string[] TempArray = Console.ReadLine().Split(' ');

        int[] arr = Array.ConvertAll(TempArray, Int32.Parse);

		Tim_Sort(arr, n); 

		printArray(arr, n); 
	} 

} 

/*
INPUT
-----
n -> 8
arr -> 6 9 2 6 1 8 3 5
OUTPUT
------
1 2 3 5 6 6 8 9
*/
