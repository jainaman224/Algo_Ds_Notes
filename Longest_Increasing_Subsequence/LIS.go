/* Problem Statement :
To find the length of the Longest Increasing 
Subsequence of a given sequence, that is all the 
elements of the subsequence are in increasing sorted order.
*/
package main

import "fmt"

func Max(lis []int) (max int) {
    max = lis[0]
    for i := 1; i < len(lis); i++ {
        if lis[i] > max {
            max = lis[i]
        }
    }
    return
}

func LIS(arr []int) {
    length := len(arr)

    if length == 0 {
        return
    }

    // Slice to store the length of the LIS til some index
    lis_arr := make([]int, length)
    lis_arr[0] = 1

    for i := 1; i < length; i++ {
        lis_arr[i] = 1
	
        // Computing LIS value in DP Bottom-up
        for j := 0; j < i; j++ {
            if ( arr[i] > arr[j] && lis_arr[i] < lis_arr[j] + 1) {
                lis_arr[i] = lis_arr[j] + 1
            }
        }
    }
	
    fmt.Printf("Length of the Longest Increasing Subsequence : %d\n", Max(lis_arr))
}

func main() {
    var n int
    fmt.Println("Enter the size of the array : ")
    fmt.Scan(&n)
    fmt.Println("Enter the array elements : ")
    arr := make([]int, n)

    for i := 0; i < n; i++ {
        fmt.Scan(&arr[i])
    }
	
    LIS(arr)
}

/* Sample Input :
Enter the size of the array :
8
Enter the array elements :
15 26 13 38 26 52 43 62

Sample Output :
Length of the Longest Increasing Subsequence : 5
*/
