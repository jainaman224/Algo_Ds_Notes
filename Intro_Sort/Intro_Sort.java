// Java implementation of IntroSort  

import java.util.*;
import java.io.*; 

public class Intro_Sort { 

    // The array to be sorted
    private int arr[];
    // To know number of elements in array
    private int n; 

    // Constructor to set size of array
    Intro_Sort(int n) 
    { 
        arr = new int[n]; 
        this.n = 0; 
    } 
    
    // This will insert values into array 
    private void insertData(int data) 
    { 
        arr[n] = data; 
        n++; 
    } 

    // Swapping function
    private void swap(int i, int j) 
    { 
	    int temp = arr[i]; 
	    arr[i] = arr[j]; 
	    arr[j] = temp; 
    } 

    // This will MaxHeap the tree with node i in array
    private void maxHeap(int i, int heapN, int start) 
    { 
        int temp = arr[start + i - 1]; 
        int child; 

            while (i <= heapN / 2) 
            { 
                child = 2 * i; 

		        if (child < heapN && arr[start + child - 1] < arr[start + child]) 
			        child++; 

		        if (temp >= arr[start + child - 1]) 
			        break; 

		        arr[start + i - 1] = arr[start + child - 1]; 
		        i = child; 
		    } 
		arr[start + i - 1] = temp; 
	} 

    // This will Heapify the heap 
    private void heapify(int start, int end, int heapN) 
    { 
	    for (int i = (heapN) / 2; i >= 1; i--) 
		    maxHeap(i, heapN, start); 
    } 

    // HeapSort algorithm is implemented here 
    private void heapSort(int start, int end) 
    { 
	    int heapN = end - start; 
	    // This will Heapify the heap 
	    this.heapify(start, end, heapN); 

	    // Extraction of elements from heap that has been created from above
	    for (int i = heapN; i >= 1; i--) 
        {     
            swap(start, start + i); 
            // Reducing heap size after extraction of the element
		    maxHeap(1, i, start); 
	    } 
	} 

	// Implementing Insertion_Sort on the array
	private void insertion_Sort(int left, int right) 
	{ 
        for (int i = left; i <= right; i++) 
        {
			int key = arr[i]; 
			int j = i; 

			// Comparing the elements from current position to left 
			while (j > left && arr[j - 1] > key) { 
				arr[j] = arr[j - 1]; 
				j--; 
            } 
            // Placing the key element in it's right position
			arr[j] = key; 
		} 
	} 

	// Median will be found and will be returned
	private int medianPivot(int a, int b, int c) 
	{ 
        // Maximum and minimum element will be found and xor with all of them results in median
		int max = Math.max(Math.max(arr[a], arr[b]), arr[c]); 
		int min = Math.min(Math.min(arr[a], arr[b]), arr[c]); 
        int median = max ^ min ^ arr[a] ^ arr[b] ^ arr[c]; 
        
        // Returning the median which will act as pivot
		if (median == arr[a]) 
			return a; 
		if (median == arr[b]) 
			return b; 
		return c; 
	} 

	// Partition function will seperate all the less than or equal to pivot to left and rest to right
	private int partition(int low, int high) 
	{ 
        // The last element will act as a pivot
		int pivot = arr[high];  
        int i = (low - 1);
         
        for (int j = low; j <= high - 1; j++) 
        {
            // If the element is less equal to then swap
            if (arr[j] <= pivot)
            { 
				i++; 
				swap(i, j); 
			} 
		} 
		swap(i + 1, high); 
		return (i + 1); 
	} 

	// This function implements IntroSort 
	private void introSort(int start, int end, int depth) 
	{ 
        // start is the starting index
        // end is the last index
        // depth is the level of the heap
        if (end - start > 16) 
        { 
            if (depth == 0) 
            { 
                // Heapsort will be called when it reaches the limit in recursion
				this.heapSort(start, end); 
				return; 
			} 

			depth = depth - 1; 
			int pivot = medianPivot(start, start + ((end - start) / 2) + 1, end); 
			swap(pivot, end); 

            // The correct index of pivot element in array will be returned by partition
			int p = partition(start, end); 

			// Calling introSort on left and right parts of the array
			introSort(start, p - 1, depth); 
			introSort(p + 1, end, depth); 
		} 
        else 
        { 
			// If the size of subarray is small then applying insertion_Sort on them
			insertion_Sort(start, end); 
		} 
	} 

	// This function will call introSort
	private void sortArray() 
	{ 
		// depth will be intialized to 2 times of the height of the heap  
		int depth = (int)(2 * Math.floor(Math.log(n) / Math.log(2))); 
		this.introSort(0, n - 1, depth); 
	} 

	// Function to display the contents of array
	private void print() 
	{ 
        System.out.println("After IntroSort the array is :");
		for (int i = 0; i < n; i++) 
			System.out.print(arr[i] + " "); 
	} 

	// Driver code
	public static void main(String args[]) throws IOException 
	{   
        Scanner s = new Scanner(System.in);
        int n = s.nextInt(); 
        Intro_Sort IntroSort = new Intro_Sort(n); 
        
		for (int i = 0; i < n; i++) { 
			IntroSort.insertData(s.nextInt()); 
		} 
		IntroSort.sortArray(); 
		IntroSort.print(); 
	} 
} 

/* Sample input :
    n = 5
    arr = [4, 1, 3, 6, 5]
   Output :
    After IntroSort the array is :
    1 3 4 5 6
*/

