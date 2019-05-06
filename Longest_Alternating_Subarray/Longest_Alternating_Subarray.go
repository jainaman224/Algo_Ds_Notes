/*
        LENGTH OF LONGEST ALTERNATING SUBARRAY

        Given an array of non-zero integers. We need to find the maximum 
        possible length of a subarray such that it has alternating positive
        and negative elements.
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
    var result = 1
    var count = 1
    fmt.Print("The length of longest alternating subarray is : ")
    for i := 1; i < num; i++ {
        if (a[i] * a[i - 1] < 0) {
            count = count + 1
            if (count > result) {
                result = count
            }
        } else {
            count = 1
        }
    }
    fmt.Print(result)
}

/*
Input :
num = 4
Array = [-1, -4, -5, 20]

Output :

The length of longest alternating subarray is : 2
*/
