// Program in Go language to count even and odd numbers in an array

package main

import "fmt"

func main() {

	// Declare the array size
    var arraySize int

    fmt.Print("Enter number of elements in your array: ")

    fmt.Scan(&arraySize)

    fmt.Println("Enter your array: ")

	// Creating the array
    array := make([]int, arraySize)

    for i := 0; i < arraySize; i++ {
        fmt.Scan(&array[i])
    }

    evenCount := 0

    for i := 0; i < arraySize; i++ {
        if array[i]%2 == 0 {
            evenCount = evenCount + 1
        }
    }

    fmt.Printf("\nNumber of odd elements in array : %d", (arraySize - evenCount))
    fmt.Printf("\nNumber of even elements in array : %d", evenCount)
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

Number of odd elements in array : 3
Number of even elements in array : 2
*/
