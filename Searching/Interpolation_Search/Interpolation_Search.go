package main

import (
	"fmt"
	"strconv"
)

func Interpolation(array []int, search_item int) (index int) {
	high := len(array) - 1
	low := 0

	for (low <= high) && (array[low] <= search_item) && (search_item <= array[high]) {
		mid := low + ((search_item-array[low])*(array[high]-array[low]))/(high-low)
		if array[mid] < search_item {
			low = mid + 1
		} else if array[mid] > search_item {
			high = mid - 1
		} else {
			index = mid
			return
		}
	}

	if search_item == array[low] {
		index = low
	} else {
		index = -1
	}
	return
}
func main() {
	array := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	search_item := 8
	index := Interpolation(array, search_item)
	if index == -1 {
		fmt.Println("Element not found")
	} else {
		fmt.Println("Found at postion " + strconv.Itoa(index))
	}
}
