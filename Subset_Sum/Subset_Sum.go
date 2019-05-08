/* 
    Subset Sum Problem: Given an array of elements and a sum,
    is it possible to form the given sum using some or all of the
    elements of array i.e using any subset of given array.
    Example: 1, 7, 3, 5, 6 and sum = 14, it is possible to
    obtain the sum 14 by taking the elements 1, 7 and 6 
*/

package main

import "fmt"

// Function to compute whether a subset of array exists
// having the given sum
func subsetSum(arr[] int, size int, sum int) bool {
  
    // A 2D Matrix containing boolean values, true and false
    dp := make([][]bool, size + 1)

    for i := 0; i <= size; i++ {
        dp[i] = make([]bool, sum + 1)
    }
    
    // We cannot form a sum i by taking no elements
    for i := 0; i <= sum; i++ {
        dp[0][i] = false
    }

    // We can always form the sum 0
    // by taking 0 instance of the element        
    for i := 0; i <= size; i++ {
        dp[0][i] = true
    }

    /* 
        Any entry of dp matrix dp[i][j] tells us that taking 
        the elements 1....i can we make the sum j, this is the 
        optimal substructure of this Dynamic Programming Problem.
        At every step, we have the option of either including the
        element in the subset to form the given sum, or we exclude
        it and keep the previous set chosen in our answer
    */
    for i := 1; i <= size; i++ {
        for j := 1; j <= sum; j++ {
            /* 
                when the value of current element is less than the 
                sum j, we have two options, either take it and include
                the element in answer or leave it and take the previous
                best given by dp[i-1][j]
            */
            if arr[i - 1] <= j {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]]
            } else {
                /* when the value of sum j is less than the element i, 
                we cannot include this element and hence take the
                previous best*/
                dp[i][j] = dp[i - 1][j]
            }
        }
    }

    /* 
        The last entry in table gives the answer
        by evaluating all the elements of array to 
        compute the required sum
    */
    return dp[size][sum]
}

// Driver function
func main() {
    arr := []int{ 2, 3, 5, 1, 6, 8, 7 }
    size := len(arr)
    sum := 12

    // Call to SubsetSum function
    ans := subsetSum(arr, size, sum)

    // if ans evaluates to false, no such subset present
    // if ans evaluates to true , subset with given sum present
    if (ans == false) {
        fmt.Println("No subset adds upto the given sum")
    } else {
        fmt.Println("Subset with given sum present")
    }
}

/*
    Input:
    arr = {2, 3, 5, 1, 6, 8, 7}
    sum = 12

    Output:
    Subset with given sum present
*/
