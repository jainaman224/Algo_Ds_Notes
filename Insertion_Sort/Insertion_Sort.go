/*
    Insertion sort is a sorting algorithm where in each
    iteration one element takes its correct place in the
    sorted array. It is an inplace sorting algorithm. 
    It iterates the input elements by growing the sorted
    array at each iteration. The time complexity of this
    algorithm is O(n^2).
*/

package main

import "fmt"

// Function for insertion sort
func Insertion_Sort(array[] int, size int) []int {
    var j int
    var temp int

    // Iterate over all elements in the array
    for i := 1; i < size; i++ {
        temp = array[i]
        j = i - 1

        /* Pick an element temp and insert it in its correct
        position in sorted array by comparing it with all 
        elements coming before it. Once we find an element
        which is greater than temp, we shift all the greater
        elements to right by one place and temp takes its 
        correct place in the array. */
        for j >= 0 && array[j] > temp {
            array[j + 1] = array[j]
            j--
        }
        
        // Placing temp at its correct position
        array[j + 1] = temp
    }
    return array
}

// Driver Function
func main() {
    // Input array
    array := []int{2, 4, 3, 1, 6, 8, 4}
    fmt.Println(Insertion_Sort(array, 7))
}

/* 
    Input
    [ 2 4 3 1 6 8 4 ]

    Output
    [ 1 2 3 4 4 6 8 ]
*/
