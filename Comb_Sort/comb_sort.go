// Go Code for Comb Sort
package main
import "fmt"

// function to update gap value
func updateGap(gap int) int {
    // Shrink gap by Shrink factor 
    gap = (gap * 10) / 13
    if gap < 1 {
        return 1
    }
    return gap
}

// Function to sort arr[] using Comb Sort 
func combSort(arr []int, n int) {
    // Initialize gap by array length
    gap := n
    swapped := false
    for gap > 1 || swapped {
        // call to function updateGap
        gap = updateGap(gap)
        swapped = false
        // Compare all elements with the obtained gap 
        for i := 0; i < (n - gap); i++ {
            // swap arr[i] and arr[i+gap]
            if arr[i] > arr[i+gap] {
                arr[i], arr[i+gap] = arr[i+gap], arr[i]
                swapped = true
            }
        }
    }
}

// Driver Function
func main() {
    arr:=[]int{3, -6, 20, 66, 25, -52, 0, 11, 42}
    n:=10
    // Call to Comb Sort function
    combSort(arr, n)
    // Printing sorted array
    fmt.Println("Sorted Array")
    for i := 0; i < n; i++ {
        fmt.Printf("%d ", arr[i])
    }
}
