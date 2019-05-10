/*
    EQUILIBRIUM INDEX OF AN ARRAY

    An equilibrium index is an index of an array, where the commulative sum 
    of all elements below it is equal to the commulative sum of all elements
    above it in that array.

*/

package main

import (
    "fmt"
)

func eq_index(a []int, num int) int{
    var sum = 0
    var sum_left = 0
    for i := 0; i < num; i++ {
        sum = sum + a[i]
    }
    for i := 0; i < num; i++ {
        sum = sum - a[i]
        if sum_left == sum {
            return i
        }
        sum_left = sum_left + a[i]
    }
    return -1
}

func main() {
    var num int
    fmt.Print("Enter length of array")
    fmt.Scan(&num)
    fmt.Print("Enter array elements :")
    var a = []int{}
    for i := 0; i < num; i++ {
        var x int
        fmt.Scan(&x)
        a = append(a, x)
    }
    fmt.Print("The equilibrium index is : ", eq_index(a, num))
}

/*
    Input : num = 4
            Array : [12, 2, 6, 6]
    Output : The equilibrium index is : 1
*/
