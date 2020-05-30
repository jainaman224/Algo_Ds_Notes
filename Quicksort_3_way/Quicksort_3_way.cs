using System; 
	
class quick
{ 
	// A function which is used to swap values 
	static void swap<T>(ref T lhs, ref T rhs) 
	{ 
		T temp; 
		temp = lhs; 
		lhs = rhs; 
		rhs = temp; 
	} 
	/* This function partitions a[] in three parts 
	a) a[l..i] contains all elements smaller than pivot 
	b) a[i+1..j-1] contains all occurrences of pivot 
	c) a[j..r] contains all elements greater than pivot */
	public static void partition(int[] a, int l, int r, ref int i, ref int j) 
	{ 
		i = l-1; j = r; 
		int p = l-1, q = r; 
		int v = a[r]; 
		
		while (true) 
		{ 
			// From left, find the first element greater than 
			// or equal to v. This loop will definitely terminate 
			// as v is last element 
			while (a[++i] < v); 
		
			// From right, find the first element smaller than or 
			// equal to v 
			while (v < a[--j]) 
				if (j == l) 
					break; 
		
			// If i and j cross, then we are done 
			if (i >= j) break; 
		
			// Swap, so that smaller goes on left greater goes on right 
			swap(ref a[i], ref a[j]); 
		
			// Move all same left occurrence of pivot to beginning of 
			// array and keep count using p 
			if (a[i] == v) 
			{ 
				p++; 
				swap(ref a[p], ref a[i]); 
			} 
		
			// Move all same right occurrence of pivot to end of array 
			// and keep count using q 
			if (a[j] == v) 
			{ 
				q--; 
				swap(ref a[j], ref a[q]); 
			} 
		} 
		
		// Move pivot element to its correct index 
		swap(ref a[i], ref a[r]); 
		
		// Move all left same occurrences from beginning 
		// to adjacent to arr[i] 
		j = i-1; 
		for (int k = l; k < p; k++, j--) 
			swap(ref a[k], ref a[j]); 
		
		// Move all right same occurrences from end 
		// to adjacent to arr[i] 
		i = i+1; 
		for (int k = r-1; k > q; k--, i++) 
			swap(ref a[i], ref a[k]); 
	} 
		
	// 3-way partition based quick sort 
	public static void quicksort(int[] a, int l, int r) 
	{ 
		if (r <= l) return; 
		
		int i = 0, j = 0; 
		
		// Note that i and j are passed as reference 
		partition(a, l, r, ref i, ref j); 
		
		// Recur 
		quicksort(a, l, j); 
		quicksort(a, i, r); 
	} 
		
	// A utility function to print an array 
	public static void printarr(int[] a, int n) 
	{ 
		for (int i = 0; i < n; ++i) 
			Console.Write(a[i] + " "); 
		Console.Write("\n"); 
	} 
		
	// Driver program 
	static void Main() 
	{ 
		int[] a = {4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4}; 
		int size = a.Length; 
		printarr(a, size); 
		quicksort(a, 0, size - 1); 
		printarr(a, size); 
	} 
	
} 
// INPUT 4 9 4 4 1 9 4 4 9 4 4 1 4 
// OUTPUT 1 1 4 4 4 4 4 4 4 4 9 9 9 
