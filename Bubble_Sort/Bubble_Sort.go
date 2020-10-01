package main

import "fmt"

// function for Bubble Sort
func BubbleSort(array[] int)[]int {
	for i:=0; i< len(array)-1; i++ {
		for j:=0; j < len(array)-i-1; j++ {
			if (array[j] > array[j+1]) {
				array[j], array[j+1] = array[j+1], array[j]
			}
		}
	}
	return array
}

// Driver Function
func main() {
	array:= []int{2, 4, 3, 1, 6, 8, 4};
	fmt.Println(BubbleSort(array))
}
