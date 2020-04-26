// Program in Go language to find mean , variance and standard deviation

package main

import (
	"fmt"
	"math"
)

func main() {

	// Declare the array size
	var arraySize int

	fmt.Print("Enter number of elements in your array: ")

	fmt.Scan(&arraySize)

	fmt.Println("Enter your array: ")

	// Create the array
	array := make([]int, arraySize)
	var mean, variance, sd, sum float64

	mean = 0
	for i := 0; i < arraySize; i++ {
		fmt.Scan(&array[i])

		// Calculating sum of the array
		mean = mean + float64(array[i])
	}

	//  mean is the average of the numbers
	mean = mean / float64(arraySize)

	// We are typecasting to float64 because, thats the type of argument given in math package
	sum = 0
	for i := 0; i < arraySize; i++ {
		sum = sum + math.Pow(float64(array[i])-mean, float64(2))
	}

	// Variance is the average of the squared differences from the Mean
	variance = float64(float64(sum) / float64(arraySize))

	// Standard Deviation is a measure of how spread out numbers are, it is the square root of the Variance.
	sd = math.Sqrt(variance)

	fmt.Println("\nMean = ", mean)
	fmt.Println("\nVariance = ", variance)
	fmt.Println("\nStandard Deviation = ", sd)

}

/*
Output after Execution:

Enter number of elements in your array: 6
Enter your array:
10
12
14
16
18
20

Mean =  15

Variance =  11.666666666666666

Standard Deviation =  3.415650255319866 */
