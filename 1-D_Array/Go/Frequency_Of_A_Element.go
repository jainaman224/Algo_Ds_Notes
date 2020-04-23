package main

import "fmt"

func main() {

	// Declare the array size
	var arraySize, number int

	fmt.Print("Enter number of elements in your array: ")

	fmt.Scan(&arraySize)

	fmt.Println("Enter your array: ")

	// Creating the array
	array := make([]int, arraySize)

	for i := 0; i < arraySize; i++ {
		fmt.Scan(&array[i])
	}

	fmt.Print("\nEnter the number whose occurence is to be found: ")
	fmt.Scan(&number)

	frequency := 0

	for i := 0; i < arraySize; i++ {
		if array[i] == number {
			frequency = frequency + 1
		}
	}

	fmt.Printf("\nFrequency is : %d", frequency)
}

/*
Output after Execution:

Enter number of elements in your array: 6
Enter your array:
1
2
3
3
4
3
Enter the number whose occurence is to be found: 3

Frequency is : 3 */
