package code

import "fmt"

// CheckFrequencyOfAnElement checks array for the frequency of the element
func CheckFrequencyOfAnElement(arr []int, num int) {
	count := 0
	for _, v := range arr {
		if v == num {
			count++
		}
	}

	fmt.Printf("Frequency of %d in array is: %d", num, count)
}
