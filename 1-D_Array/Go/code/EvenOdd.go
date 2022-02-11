package code

import "fmt"

// CheckEvenOrOdd checks slice elements for even and odd
func CheckEvenOrOdd(arr []int) {
	for i := 0; i < len(arr); i++ {
		if arr[i]%2 == 0 {
			fmt.Printf("%d is an even number\n", arr[i])
		} else {
			fmt.Printf("%d is an odd number\n", arr[i])
		}
	}
}
