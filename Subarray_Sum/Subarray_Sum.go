/*
    SUBARRAY SUM 

    The task is to find sum of all possible subarrays of an array.
    This can be done by finding all subarray by a brute force solution
    and then finding combined sum of them.
    An efficient solution gets us to the theory that every element 
    contributes (i+1)*(n-1) times in the required sum. We use this
    formula for the computation of sum.
*/

package main

import (
    "fmt"
)

func main() {
    var num int
    fmt.Print("Enter the size of array : ")
    fmt.Scan(&num)
    var a = []int{}
    fmt.Print("Enter array elements")
    for i := 0; i < num; i++ {
        var x int
        fmt.Scan(&x)
        a = append(a, x)
    }
    var ans = 0
    for i := 0; i < num; i++ {
        ans = ans + (a[i] * (i + 1) * (num - i))
    }
    fmt.Print("The sum of all subarrays is : ",ans)
}

/*
Input : num = 4
        Array = [-1, -4, -5, 20]
Output :
        The sum of all subarrays is : 22
*/
