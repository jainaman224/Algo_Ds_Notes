
/*	Heap Sort is a comparison-based sorting method performed on a Heap data structure.
    Here we build a max heap first to later sort the elements in the heap in ascending order.
*/
   

package main 
import "fmt" 


func max_heapify(arr []int, n int, i int) { 

    largest := i // Initialize largest as root 
    l := 2 * i + 1 // left child
    r := 2 * i + 2 // right child
  
    // If left child is larger than root 
	if l < n && arr[l] > arr[largest]{
        largest = l
		}
  
    // If right child is larger than largest so far 
    if r < n && arr[r] > arr[largest]{	
        largest = r
		}
  
    // If largest is not root 
    if largest != i{ 
        arr[i], arr[largest] = arr[largest], arr[i] //swapping
  
        // Recursively heapify the affected sub-tree 
        max_heapify(arr, n, largest) 
    } 
} 


func heapSort(arr []int, n int ) { 

    // Build heap (rearrange array) 
    for  i := n / 2 - 1; i >= 0; i-- { 
        max_heapify(arr, n, i)
    }
  
    // One by one extract an element from heap 
    for  i := n - 1; i >= 0; i-- { 
        // Move current root to end 
        arr[0], arr[i]=arr[i],arr[0];  //swapping
  
        // call heapify on the reduced heap 
        max_heapify(arr, i, 0); 
    } 
}
 

func printArray(arr []int, no int) {  
   
    //printing the sorted array
    for i := 0; i <= 10; i++ {
        fmt.Printf("\n%d",arr[i])
    }
    
}


func main() {
	var n int
	fmt.Println("Enter the number of elements :") 
	fmt.Scan(&n) //accepting the number of elements from the user
	arr := make([]int, n) //creating an array of n elements
	
	for i := 0; i < n; i++ {
      fmt.Scan(&arr[i])  //accepting input elements
    }
	fmt.Println(arr)
    
    fmt.Println("Sorted array is") 
	heapSort(arr, n)
    printArray(arr, n) 
}

/* OUTPUT:

Enter the number of elements : 7
Enter the elements :
0
12
11
13
5
6
7

Original Array: [0 12 11 13 5 6 7]

Sorted array is
0 5 6 7 11 12 13 

*/