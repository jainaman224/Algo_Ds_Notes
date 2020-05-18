/* A Java program to implement Intro Sort.
 * 
 * - Intro Sort combines Insertion, Quick and Heap sorts
 * - If the dataset is small (<= 16 elements), then perform Insertion Sort 
 * - If the dataset is large, perform Quick Sort
 * 		- when the recursion depth gets higher, perform Heap Sort
 * 
 * - This strategy ensures that the worst case complexity doesn't exceed O(N log N)
*/


import java.util.Scanner;
import java.io.IOException; 

public class IntroSort 
{ 	
	static int n; // stores the number of data elements
	static int ar[]; // stores the inputted data elements
	
	
	// main driver function
	public static void main(String args[]) throws IOException 
	{ 
		IntroSort obj = new IntroSort(); 
		obj.getInput();
		obj.sortData(); 
		obj.displayData(); 
	} 

	
	// function to get the user's input
	void getInput() 
	{ 
		Scanner sc = new Scanner (System.in);
		System.out.println("Enter the number of data elements");
		n = sc.nextInt();		
		ar = new int[n];
		System.out.println("Enter the data elements");
		for (int i=0; i<n; i++) 
		{ 
			ar[i]=sc.nextInt(); 
		}  
		System.out.println();
	} 
	
	void sortData() 
	{ 
		int depthLimit = (int)(2 * Math.floor(Math.log(n) / Math.log(2))); 

		this.sortDataUtil(0, n - 1, depthLimit); 		
	} 
	
	/* function implementing Intro sort 
	low: starting index, 
	high: ending index, 
	depthLimit: maximum depth for recursion, typically = 2 * log (length(input array))  */
	void sortDataUtil(int begin, int end, int depthLimit) 
	{ 
		if (end-begin>16) 
		{ 
			if (depthLimit == 0) 
			{ 
				// if recursion limit is reached, perform Heap Sort
				this.heapSort(begin, end); 
				return; 
			} 
			
			// implementing Quick Sort
			depthLimit = depthLimit - 1; 
			int pivot = findPivot(begin, 
				begin + ((end - begin) / 2) + 1, end); 
			swap(pivot, end); 

			// p: partitioning index 
			int p = partition(begin, end); 

			// sort the elements before & after partition separately
			sortDataUtil(begin, p - 1, depthLimit); 
			sortDataUtil(p + 1, end, depthLimit); 
		} 

		else 
		{ 
			// performing Insertion Sort if dataset is small (upto 16 elements)
			insertionSort(begin, end); 
		} 
	}
	
	// Heap Sort: main function
	void heapSort(int begin, int end) 
	{ 
		int heapN = end - begin; 
		// Build heap (rearrange array) 
		this.heapify(begin, end, heapN); 
		
		// One by one extract an element from heap 
		for (int i = heapN; i >= 1; i--) 
		{ 
			// Move current root to end 
			swap(begin, begin + i); 

			// call maxHeap() on the reduced heap 
			maxHeap(1, i, begin); 
		} 
	} 

	// Heap Sort: swapping function
	void swap(int i, int j) 
	{ 
		int temp = ar[i]; 
		ar[i] = ar[j]; 
		ar[j] = temp; 
	} 
	

	// Heap Sort: sorting function, heapN: size of heap
	void maxHeap(int i, int heapN, int begin) 
	{ 
		int temp = ar[begin + i - 1]; 
		int child; 

		while (i <= heapN / 2) 
		{ 
			child = 2 * i; 

			if (child < heapN 
				&& ar[begin + child - 1] < ar[begin + child]) 
				child++; 

			if (temp >= ar[begin + child - 1]) 
				break; 

			ar[begin + i - 1] = ar[begin + child - 1]; 
			i = child; 
		} 
		ar[begin + i - 1] = temp; 
	} 

	// Heap Sort: function to build the heap (rearrange the array)
	void heapify(int begin, int end, int heapN) 
	{ 
		for (int i = (heapN) / 2; i >= 1; i--) 
			maxHeap(i, heapN, begin); 
	} 
	

	/* Quick Sort function:
	 * - takes last element as pivot and places it in the correct position in sorted array
	 * - elements < pivot are placed to its left
	 * - elements > pivot are placed to its right
	*/ 	 
	int partition(int low, int high) 
	{ 
		int pivot = ar[high]; 
		int i = (low - 1); 
		for (int j = low; j <= high - 1; j++) 
		{
			// If current element<=pivot, increment index of smaller element 
			if (ar[j] <= pivot)
			{ 
				i++; 
				swap(i, j); 
			} 
		} 
		swap(i + 1, high); 
		return (i + 1); 
	}
	
	// QuickSort: function to find the median of the three elements 
	int findPivot(int a1, int b1, int c1) 
	{ 
		int max = Math.max(Math.max(ar[a1], ar[b1]), ar[c1]); 
		int min = Math.min(Math.min(ar[a1], ar[b1]), ar[c1]); 
		int median = max ^ min ^ ar[a1] ^ ar[b1] ^ ar[c1]; 
		if (median == ar[a1]) 
			return a1; 
		if (median == ar[b1]) 
			return b1; 
		return c1; 
	} 

	
	// Insertion Sort function
	private void insertionSort(int left, int right) 
	{ 
		for (int i = left; i <= right; i++) 
		{ 
			int key = ar[i]; 
			int j = i; 
			// if ar[i]>key, move ahead by 1 position
			while (j>left && ar[j-1]>key) 
			{ 
				ar[j] = ar[j-1]; 
				j--; 
			} 
			ar[j] = key; 
		} 
	} 


	// function to display the sorted data 
	void displayData() 
	{ 
		
		for (int i = 0; i < n; i++) 
			System.out.print(ar[i] + " "); 
	} 
} 



/*

INPUT 

Enter the number of data elements
12
Enter the data elements
56
43
89
76
123
35
7
83
24
55
90
3

OUTPUT
3 7 24 35 43 55 56 76 83 89 90 123

*/
