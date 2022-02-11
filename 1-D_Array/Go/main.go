package main

import (
	"Algo_Ds_Notes/1-D_Array/Go/code"
	"fmt"
)

func main() {

	var n int
	fmt.Print("Enter the number of elements in array: ")
	fmt.Scanf("%d", &n)

	arr := make([]int, n)
	fmt.Printf("Enter the %d elements of array:\n", n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &arr[i])
	}

	// invoke CheckEvenOrOdd
	code.CheckEvenOrOdd(arr)

	var num int
	fmt.Print("Enter the number whose frequency is required: ")
	fmt.Scanf("%d", &num)

	// call CheckFrequencyOfAnElement
	code.CheckFrequencyOfAnElement(arr, num)
}

/*
	Sample Input/Output:
	Entre the number of elements in array: 6
	Entre the 6 elements of array:
	1 1 2 3 5 6
	1 is an odd number
	1 is an odd number
	2 is an even number
	3 is an odd number
	5 is an odd number
	6 is an even number
	Entre the number whose frequency is required: 1
	Frequency of 1 in array is: 2
*/
