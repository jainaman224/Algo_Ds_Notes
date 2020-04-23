// Program in Go language to find the maximum and the next maximum number in an array

package main

import "fmt"

func main() {

	// Declare the array size
    var arraySize int

    fmt.Print("Enter number of elements in your array: ")
    fmt.Scan(&arraySize)

    fmt.Println("Enter your array: ")

    // Create the array
    array := make([]int, arraySize)

    for i := 0; i < arraySize; i++ {
        fmt.Scan(&array[i])
    }

    // max is for maximum number and
    // nextMax for next(second) maximum number
    var max, nextMax int

    // Assigning max and nextMax with array[0] and array[1] depending
    // on the condition max > nextMax
    if array[0] > array[1] {
        max = array[0]
        nextMax = array[1]
	} else {
        max = array[1]
        nextMax = array[0]
    }

    // Comparing rest of the element in the array
    for i := 2; i < arraySize; i++ {
        if array[i] > nextMax {
            if array[i] > max {
                nextMax = max
                max = array[i]
            } else {
                nextMax = array[i]
            }
        }
    }

    fmt.Printf("Max: %d", max)

    fmt.Printf("\nNext max: %d", nextMax)

}

/*
Output after Execution:

Enter number of elements in your array: 5
Enter your array:
1
2
3
4
5
Max: 5
Next max: 4  */
