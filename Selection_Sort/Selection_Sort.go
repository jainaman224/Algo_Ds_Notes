/*
    Selection Sort is a sorting algorithm that is based
    on the idea of finding the minimum or maximum element
    in an unsorted array and then putting it in its correct
    position in a sorted array.
*/

package main

import "fmt"

// Function for selection sort
func Selection_Sort(array[] int, size int) []int {
    var min_index int
    var temp int

    // Iterate over unsorted array
    for i := 0; i < size - 1; i++ {
        min_index = i

        // Find index of minimum element
        for j := i + 1; j < size; j++ {
            if array[j] < array[min_index] {
                min_index = j
            }
        }

        temp = array[i]
        array[i] = array[min_index]
        array[min_index] = temp
    }
    return array
}

// Driver Function
func main() {
    var num int
    fmt.Scan(&num)
    array := []int{}
    for i := 0; i < num; i++ {
        var x int
        fmt.Scan(&x)
        array = append(array, x)
    }
    fmt.Println(Selection_Sort(array, num))
}

/* 
    Input:
    [ 2 4 3 1 6 8 4 ]

    Output:
    [ 1 2 3 4 4 6 8 ]
*/
