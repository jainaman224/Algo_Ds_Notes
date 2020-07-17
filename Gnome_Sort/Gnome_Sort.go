package main
 
import "fmt"

// A function which is used to sort the given list using Gnome sort 
func gnomeSort(arr []int, n int) {   

	// Implementation Logic Begins here
	index := 0; 
  
	for index < n { 
		// Intially Index is set to Zero then It will be incremented to 1
		if (index == 0){
			index++
		}
		// Checking the values between the array elements
		if (arr[index] >= arr[index - 1]) {
			index++ 
	   } else { 
		  arr[index], arr[index-1] = arr[index-1], arr[index] 
			index-- 
		} 
	   }   
	}
	
// Main function
func main() {
    size := 0
    fmt.Println("Enter the size of array")
    fmt.Scanln(&size)
    fmt.Println("Enter the numbers")
    arr := make([]int, size)
    for i := 0; i < size; i++ {
        fmt.Scan(&arr[i])
    }
   fmt.Println("before:", arr)
   gnomeSort(arr, size)
   fmt.Println("after: ", arr)
}

/*
    Sample Driver Code:
    INPUT: 
    Enter the size of an Array: 5
    3
    2
    1
    -5
    7

    OUTPUT:
    -5
    1
    2
    3
    7

*/