package main

import "fmt"

func main() {

	// Declare the array size
	var arraySize1, arraySize2 int

	fmt.Print("Enter number of elements in array 1: ")
	fmt.Scan(&arraySize1)

	fmt.Println("Enter your sorted array 1: ")

	// Creating the array1
	array1 := make([]int, arraySize1)

	for i := 0; i < arraySize1; i++ {
		fmt.Scan(&array1[i])
	}

	fmt.Print("Enter number of elements in array 2: ")
	fmt.Scan(&arraySize2)

	fmt.Println("Enter your sorted array 2: ")

	// Creating the array2
	array2 := make([]int, arraySize2)

	for i := 0; i < arraySize2; i++ {
		fmt.Scan(&array2[i])
	}

	var i, j, k int
	i = 0
	j = 0
	k = 0

	c := make([]int, arraySize1+arraySize2)

	for i < arraySize1 && j < arraySize2 {
		if array1[i] > array2[j] {
			c[k] = array2[j]
			j = j + 1
			k = k + 1
		} else {
			c[k] = array1[i]
			k = k + 1
			i = i + 1
		}
	}

	// copying remaining elements of array a
	for i < arraySize1 {
		c[k] = array1[i]
		k = k + 1
		i = i + 1
	}

	// copying remaining elements of array b
	for j < arraySize2 {
		c[k] = array2[j]
		k = k + 1
		j = j + 1
	}

	fmt.Println("New merged array: ")
	for i := 0; i < (arraySize1 + arraySize2); i++ {
		fmt.Printf("%d ", c[i])
	}
}

/*
Output after Execution:

Enter number of elements in array 1: 3
Enter your sorted array 1:
1
2
3
Enter number of elements in array 2: 3
Enter your sorted array 2:
4
5
6
New merged array:
1 2 3 4 5 6  */
