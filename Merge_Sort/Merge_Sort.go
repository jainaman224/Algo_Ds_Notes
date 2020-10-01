package main

import "fmt"

func merge(left, right []int) []int {
	result := make([]int, len(right)+len(left))
	i, j := 0, 0
	for i < len(right) && j < len(left) {
		if right[i] <= left[j] {
			result[i+j] = right[i]
			i += 1
		} else {
			result[i+j] = left[j]
			j += 1
		}
	}
	for i < len(right) {
		result[i+j] = right[i]
		i += 1
	}
	for j < len(left) {
		result[i+j] = left[j]
		j += 1
	}
	return result
}

func MergeSort(array []int) []int {
	if len(array) <= 1 {
		return array
	}
	mid := len(array) / 2
	right := MergeSort(array[:mid])
	left := MergeSort(array[mid:])
	return merge(right, left)
}

func main() {
	array := []int{2, 4, 3, 1, 6, 8, 4}
	result := MergeSort(array)
	fmt.Println(result)
}
