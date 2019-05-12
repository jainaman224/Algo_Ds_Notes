/*
    PERFECT ARRAY

    An array which is strictly increasing and then constant, and then strictly 
    decreasing is called a perfect array.
    There should be no variations in between.

*/

package main

import (
    "fmt"
)

func perfect(a []int, num int) int{
    var count = 1
    for (count < num && a[count] > a[count - 1]) {
        count++
    }
    for (count < num && a[count] == a[count - 1]) {
        count++
    }
    for (count < num && a[count] < a[count - 1]) {
        count++
    }
    if (count == num) {
        return 1
    }
    return 0
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
    if (perfect(a, num) == 1) {
        fmt.Print("It is a perfect array");
    } else {
        fmt.Print("It is not a perfect array");
    }
}

/*
    Input : num = 5
            Array : [1, 2, 3, 3, 6]
    Output : It is not a perfect array
*/
