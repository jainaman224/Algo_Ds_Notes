package main

import (
	"fmt"
)

// Conquer
func Partition(array []int, left int, right int) int {
    pivot := array[left]
    index := right

    for j := right; j > left; j-- {
        if array[j] > pivot {
            array[j], array[index]= array[index], array[j]
            index--
        }
    }

    array[left] = array[index]
    array[index] = pivot
    return index
}

// Divide
func quickSort(array []int, left int, right int) {
	if left < right {
	pivot := Partition(array, left, right)
	quickSort(array, left, pivot-1)
	quickSort(array, pivot+1, right)
	}
}

// Calling function
func Quick_Sort(array []int, size int) {
    quickSort(array, 0, size-1)
}

// Driver Function
func main() {
    array:= []int{2, 4, 3, 1, 6, 8, 4}
    Quick_Sort(array, len(array))
    fmt.Println(array)
}

// Output
// [1 2 3 4 4 6 8]
