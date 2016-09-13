package main

import (
	"fmt"
	"strconv"
)

func BinarySearch(array []int, desired int) (index int) {
	if len(array) <= 1 {
		index = -1
		return
	}

	left := 0
	right := len(array) - 1
	for left <= right {
		mid := left + (right-left)/2
		if array[mid] < desired {
			left = mid + 1
		} else if array[mid] > desired {
			right = mid - 1
		} else {
			index = mid
			return
		}
	}
	return
}
func main() {
	array := []int{1, 2, 3, 4, 5, 6, 7}
	index := BinarySearch(array, 4)
	if index != -1 {
		fmt.Println("Found 4 at ", strconv.Itoa(index))
	} else {
		fmt.Println("Not Found")
	}
}
