package main

import (
	"fmt"
	"sort"
)

// Function to sort the array elements using Bucket sort
func bucket_sort(arr []float64, size int)
{
	var max_ele, min_ele float64
    min_ele = arr[0]

    //Find the minimum and maximum element in the array
	for i:= 0; i < size; i++ { 

		if arr[i] < min_ele {
			min_ele = arr[i]
		}

		if arr[i] > max_ele {
			max_ele = arr[i] 
		}
	}
	
	// Calculate the Number of buckets to be used
	no_of_buckets := int(max_ele - min_ele) / size + 1

	// Initialise a 2D array for creating buckets
	buckets := make([][]float64, no_of_buckets)

	// Now put the array elements into their corresponding buckets
	for i:= 0; i < size; i++ {
		
		index := int(arr[i] - min_ele) / size             // Index of the element in the buckets
		buckets[index] = append(buckets[index], arr[i])
	}

	// One by one sort each bucket
	for i:= 0; i < no_of_buckets; i++ {

		if len(buckets[i]) > 0 {
			sort.Float64s(buckets[i])
		}
	}

	// Now one by one add those bucket elements back into array
	index := 0
	for i:= 0; i < no_of_buckets; i++ {

		for j:= 0; j < len(buckets[i]); j++ {

			arr[index] = buckets[i][j]
			index++
		}
	}

}

func main() {
	
	var size int
	fmt.Print("Enter the size of the array:")
	fmt.Scanf("%d", &size) 

	array := make([]float64, size)

	for i:= 0; i < size; i++{
		fmt.Scanf("%f", &array[i])
	}

	fmt.Println("Array before sorting:", array)
	
	bucket_sort(array, size)
	
	fmt.Println("Array after sorting:", array)

}

/*
Sample Input
	
	Enter the size of the array:10                                                                                                         
	3 9 11 7 2 8 13 5 12 4
	Array before sorting: [3 9 11 7 2 8 13 5 12 4]

Sample Output

	Array after sorting: [2 3 4 5 7 8 9 11 12 13] 
*/


