/*
                Bucket Sort Implementation in GO
        ---------------------------------------------------
                     Bucket Sort
        ---------------------------------------------------
Bucket Sort is a sorting technique that sorts the elements by first dividing the elements into several groups called buckets.
The elements inside each bucket are sorted using any of the suitable sorting algorithms or recursively calling the same algorithm.
Several buckets are created. Each bucket is filled with a specific range of elements.
The elements inside the bucket are sorted using any other algorithm. Finally, the elements of the bucket are gathered to get the sorted array.
The process of bucket sort can be understood as a scatter-gather approach. The elements are first scattered into buckets then 
the elements of buckets are sorted.

Bucket sort is used when:
-> input is uniformly distributed over a range.
-> there are floating point values
*/


package main

import (
    "fmt"
    "os"
    "strconv"
)

func insertionSort(array []float64) {
    for i := 0; i < len(array); i++ {
        temp := array[i]
        j := i - 1
        for ; j >= 0 && array[j] > temp; j-- {
            array[j + 1] = array[j]
        }
        array[j + 1] = temp
    }
}

func bucketSort(array []float64, bucketSize int) []float64 {
    var max, min float64
    for _, n := range array {
        if n < min {
            min = n
        }
        if n > max {
            max = n
        }
    }
	
    nBuckets := int(max-min) / bucketSize + 1
    buckets := make([][]float64, nBuckets)
    for i := 0; i < nBuckets; i++ {
        buckets[i] = make([]float64, 0)
    }

    for _, n := range array {
        idx := int(n-min) / bucketSize
        buckets[idx] = append(buckets[idx], n)
    }

    sorted := make([]float64, 0)
    for _, bucket := range buckets {
        if len(bucket) > 0 {
            insertionSort(bucket)
            sorted = append(sorted, bucket...)
        }
    }
    return sorted
}

func main() {
    var x int
    fmt.Printf("Enter the size of the array : ")
    fmt.Scan(&x)
    fmt.Printf("Enter the elements of the array : ")
    a := make([]float64, x)
    for i := 0; i < x; i++ {
        fmt.Scan(&a[i])
    }
 
    array := a    // A copy of the array 'a' is assigned to 'array' 
    for _, arg := range os.Args[1:] {
        if n, err := strconv.ParseFloat(arg, 64); err == nil {
            array = append(array, n)
        }
    }
	
    fmt.Printf("The array before sorting is %v\n", array)
    array = bucketSort(array, 5)
    fmt.Printf("The array after sorting is %v\n", array)
}


/*

    Sample Input :
    Enter the size of the array : 3                                                                                               
    Enter the elements of the array : 2 8 5 
	
    Sample Output :
    The array before sorting is [2 8 5]                                                                                           
    The array after sorting is [2 5 8] 
	
*/

