package code

import "fmt"

// CheckEvenOrOdd checks slice elements for even and odd
func CheckEvenOrOdd() {

	var n int
	fmt.Scanf("%d", &n)

	arr := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &arr[i])
	}

	for i := 0; i < n; i++ {
		if arr[i]%2 == 0 {
			fmt.Printf("%d is an even number\n", arr[i])
		} else {
			fmt.Printf("%d is an odd number\n", arr[i])
		}
	}
}
