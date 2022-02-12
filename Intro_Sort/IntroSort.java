/* A Java program to implement Intro Sort (or Introspective Sort)
 * 
 * - Intro Sort combines Insertion, Quick and Heap sorts
 * - If the dataset is small (<= 16 elements), then perform Insertion Sort 
 * - If the dataset is large, perform Quick Sort
 *        - when the recursion depth gets higher, perform Heap Sort
 * 
 * - This strategy ensures that the worst case complexity doesn't exceed O(N log N)
*/


import java.util.Scanner;
import java.io.IOException; 

public class IntroSort 
{ 	
    static int n; // stores the number of data elements
    static int ar[]; // stores the inputed data elements
	
    // main driver function
    public static void main(String args[]) throws IOException 
    { 
    	//depthLimit: maximum depth for recursion, typically = 2 * log (length(input array))
        int depthLimit = (int)(2 * Math.floor(Math.log(n) / Math.log(2)));
        IntroSort obj = new IntroSort(); 
        obj.getInput();
        obj.introSort(0, n - 1, depthLimit); 
        obj.displayData(); 
    } 

	
    // Function to get the user's input in an array
    void getInput() 
    {
        Scanner sc = new Scanner (System.in);
        System.out.println("Enter the number of data elements");
        n = sc.nextInt();
        ar = new int[n];
        System.out.println("Enter the data elements");
        for (int i = 0; i < n; i++)
        {
            ar[i] = sc.nextInt();
        }
        System.out.println();
        sc.close();
    } 
    
    // Function implementing Intro Sort
    void introSort(int start, int end, int depthLimit)
    {
    	//checking if the dataset is large enough (i.e. >16 elements)
        if (end - start > 16)
        {
            // if recursion limit (i.e. depth limit) is reached, perform Heap Sort
            if (depthLimit == 0)
            {
	        this.heapSort();
                return;
            } 
            depthLimit = depthLimit - 1;
            
            // implementing Quick Sort (whilst depth limit is not reached)
            quickSort(0, n - 1);
        } 

        else
        { 
            // performing Insertion Sort if dataset is small (upto 16 elements)
            insertionSort(start, end); 
        }
    }

    // Heap Sort: main function
    void heapSort() 
    {  	  
         // builds the heap (rearranges the array) 
         for (int i = n / 2 - 1; i >= 0; i--) 
             heapify(i); 
   
         // extracts the array elements one at a time 
         for (int i = n - 1; i >= 0; i--) 
         { 
             // swaps the current root with the element at the end 
             int temp = ar[0]; 
             ar[0] = ar[i]; 
             ar[i] = temp; 
   
             // builds the reduced heap 
             heapify(0); 
         }  
    }
	
    // Heap Sort: function to build the heap (rearrange the array)
    void heapify(int i) 
    { 
        int largest = i;  // initialize the largest element as root 
        int left_child = 2 * i + 1;  
        int right_child = 2 * i + 2; 
  
        // If left child is larger than root 
        if (left_child < n && ar[left_child] > ar[largest]) 
            largest = left_child; 
  
        // If right child is larger than largest so far 
        if (right_child < n && ar[right_child] > ar[largest]) 
            largest = right_child; 
  
        // if the largest element is not root, swap the root with the largest 
        if (largest != i) 
        { 
            int swap = ar[i]; 
            ar[i] = ar[largest]; 
            ar[largest] = swap; 
  
            // recursively heapify 
            heapify(largest); 
        } 
    }
 
    
    // Quick Sort: driver function
    void quickSort(int low, int high) 
    { 
        if (low < high) 
        { 
            //p: partitioning index
            int p = partition(low, high); 
  
            // recursively sorts elements before and after partition 
            quickSort(low, p-1); 
            quickSort(p+1, high); 
        } 
    } 

    /* Quick Sort: partitioning function
     * - takes last element as pivot and places it in the correct position in sorted array
     * - elements < pivot are placed to its left
     * - elements > pivot are placed to its right
    */ 	 
    int partition(int low, int high) 
    { 
    	// taking the element at the end as pivot
        int pivot = ar[high]; 
        int i = (low - 1); 
        for (int j = low; j <= high - 1; j++) 
        {
            // if current element<=pivot, increment index of smaller element 
            if (ar[j] <= pivot)
            { 
                i++; 
                // swapping ar[i] and ar[j] 
                int temp = ar[i]; 
                ar[i] = ar[j]; 
                ar[j] = temp;  
            } 
        } 
        // swapping ar[i+1] and ar[high] 
        int temp = ar[i + 1]; 
        ar[i+1] = ar[high]; 
        ar[high] = temp;  
        return (i+1); 
    }
	
    // Insertion Sort function
    private void insertionSort(int left, int right) 
    { 
        // all elements to the left of the current element are sorted, to the right are unsorted
        for (int i = left; i <= right; i++)
        { 
            int key = ar[i]; 
            int j = i; 
            // if ar[i] > key, move ahead by 1 position
            while (j > left && ar[j - 1] > key) 
            { 
                ar[j] = ar[j - 1];
                j--;
            }
            ar[j] = key;
        }
    } 

    // function to display the sorted data
    void displayData()
    {
        System.out.println("The sorted data is given below");
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
The sorted data is given below
3 7 24 35 43 55 56 76 83 89 90 123

*/
