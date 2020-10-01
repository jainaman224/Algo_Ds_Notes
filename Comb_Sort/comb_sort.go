// Go Code for Comb Sort
package main
import "fmt"

// Function to find max of two elements
func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}

// Function to sort arr[] using Comb Sort 
func combSort(arr []int, n int) {
    // Initialize gap by array length
    gap := n
    flag := 1
    for gap > 1 || flag == 1 {
        // Update gap value by using shrink factor 1.3
        gap = (gap*10) / 13
        gap = max(1, gap)
        flag = 0
        // Compare all elements with the obtained gap 
        for i := 0; i < (n - gap); i++ {
            // swap arr[i] and arr[i+gap] if arr[i] is greater
            if arr[i] > arr[i+gap] {
                arr[i], arr[i+gap] = arr[i+gap], arr[i]
                flag = 1
            }
        }
    }
}

// Driver Function
func main() {
    arr:=[]int{-10, 50, 20, 0, 15, -25, 30}
    n := len(arr)
    // Call to Comb Sort function
    combSort(arr, n)
    // Printing sorted array
    fmt.Println("Array after sorting:")
    for i := 0; i < n; i++ {
        fmt.Printf("%d ", arr[i])
    }
}

// Output
// Array after sorting:
// -25 -10 0 15 20 30 50
