/*
ROOT MEAN SQUARE

Root Mean Square or RMS is known as quadratic mean of a given array.
It holds a lot of importance in mathematical calculations in various
domains like Physics and geometry.
*/

package main

import (
    "fmt"
)

func RMS(a []int, n int, index int, ans int) {
    if (index == n) {
        ans = ans / n
        fmt.Print("RMS of array is : ", ans)
        return
    }
    ans = ans + a[index] * a[index]
    RMS(a, n, index + 1, ans)
}

func main() {
    var n int
    fmt.Scan(&n)
    var a []int
    for i := 0; i < n; i++ {
        var temp int
        fmt.Scan(&temp)
        a = append(a, temp)
    }
    RMS(a, n, 0, 0)
}

/*
INPUT : n = 3
        a = [3, 15, 32]
OUTPUT :
RMS of array is : 419
*/
