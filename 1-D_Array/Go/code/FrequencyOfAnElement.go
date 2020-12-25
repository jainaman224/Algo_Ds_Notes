package code

import "fmt"

// CheckFrequencyOfAnElement checks array for the frequency of the element
func CheckFrequencyOfAnElement() {

	var n int
	fmt.Scanf("%d", &n)

	arr := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &arr[i])
	}

	var num int
	fmt.Scanf("%d", &num)

	count := 0
	for _, v := range arr {
		if v == num {
			count++
		}
	}

	fmt.Printf("Frequency of %d in array is: %d", num, count)
}
