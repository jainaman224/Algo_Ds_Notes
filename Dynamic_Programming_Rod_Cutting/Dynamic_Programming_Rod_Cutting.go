/*
    The Rod Cutting Problem is a problem in Dynamic Programming
    in which given a rod of certain length, we need to determine
    the maximum value obtainable if we cut the rod into smaller
    pieces and sell those pieces.
*/

package main

import "fmt"

// Function to compute maximum of two numbers
func max(i int, j int) int {
    if i > j {
        return i
    } else {
        return j
    }
}

// Returns the maximum obtainable cost
func Rod_Cutting(cost[] int, size int) int {
    val := make([]int, size + 1)
    val[0] = 0
    
    /*
        The outer loop runs over rod of length i. We then
        divide the rod of length i into two rods of length
        j and i - j each and take maximum.
    */
    for i := 1; i <= size; i++ {
        for j := 0; j < i; j++ {
            val[i] = max(val[i], cost[j] + val[i - j - 1])
        }
    }

    // Return the maximum value obtainable for given size
    return val[size]
}

// Driver function
func main() {
    // Array contaning profits of elements of length index
    var size int
    fmt.Scan(&size)
    arr := []int{}
    for i := 0; i < size; i++ {
        var x int
        fmt.Scan(&x)
        arr = append(arr, x)
    }
    fmt.Println("Maximum value obtained is:")
    fmt.Println(Rod_Cutting(arr, size))
}

/* 
INPUT: 
size = 8
arr = {3, 5, 8, 9, 10, 17, 17, 20}
OUTPUT:
Maximum value is 24
*/
