/*
    LEADERS OF AN ARRAY

    The task is to find all leaders in an array, where
    a leader is an array element which is greater than all the elements
    on its right side
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
    var maximum = a[num - 1]
    fmt.Println("The following are the leaders of array : ")
    fmt.Print(a[num - 1], " ")
    for i := num - 2; i >= 0; i-- {
        if (a[i] > maximum) {
            fmt.Print(a[i], " ")
        }
    }
}

/*
Input : num = 5
        Array = [13, 4, 12, 1, 5]
Output :
        The following are the leaders of array : 
        5 12 13
*/
