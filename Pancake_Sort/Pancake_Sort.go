// Program in Go language that implements Pancake Sort

package main

import "fmt"

//Reverses array
func flip(array []int, index int) {
    var start int
    start = 0
    for start < index {
        array[start], array[index] = array[index], array[start]
        start++
        index--
    }
}

// Returns index of element with maximum value in the array
func maxIndex(array []int, n int) int {
    var index int
    index = 0
    for i := 0; i < n; i++ {
        if array[i] > array[index] {
            index = i
        }
    }
    return index
}

// Function to sort the array using pancake sort

func pancakeSort(array []int, n int) {
    // Reducing the size of the array one at a time
    for size := n; size > 1; size-- {
        max := maxIndex(array, size)
        // If the max element is not in the end of the array, move it there
        if max != size-1 {
            // We move the maximum element to the beginning and then flip the array to move the element to the end
            flip(array, max)
            flip(array, size-1)
        }
    }
}

func main() {

    // Declare the array size
    var arraySize int

    fmt.Print("Enter number of elements in your array: ")

    fmt.Scan(&arraySize)

    fmt.Print("Enter your array: ")

    // Creating the array
    array := make([]int, arraySize)

    for i := 0; i < arraySize; i++ {
        fmt.Scan(&array[i])
    }

    fmt.Printf("Unsorted Array: ")
    for i := 0; i < arraySize; i++ {
        fmt.Printf("%d ", array[i])
    }

    pancakeSort(array, arraySize)

    fmt.Printf("\nSorted Array: ")
    for i := 0; i < arraySize; i++ {
        fmt.Printf("%d ", array[i])
    }

}

/*
Output after Execution:

Enter number of elements in your array: 6
Enter your array: 2 1 5 4 9 8
Unsorted Array: 2 1 5 4 9 8
Sorted Array: 1 2 4 5 8 9

*/
