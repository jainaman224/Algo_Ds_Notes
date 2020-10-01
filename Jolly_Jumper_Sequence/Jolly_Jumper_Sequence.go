/*
JOLLY JUMPER SEQUENCE

If the set of differences of consecutive elements of the sequence
varies from 1 to n - 1, the sequence formed is said to be Jolly Jumper
Sequence.
*/

package main

import (
    "fmt"
    "math"
)

func Jolly(a []int, n int) int {
    var check []int
    for i := 0; i < n; i++ {
        check = append(check, 0)
    }
    for i := 1; i < n; i++ {
        x := int(math.Abs(float64(a[i] - a[i - 1])))
        if (x == 0 || x > n - 1 || check[x] == 1) {
            return 0
        }
        check[x] = 1
    }
    return 1
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
    if (Jolly(a, n) == 1) {
        fmt.Print("It is a jolly jumper sequence")
    } else {
        fmt.Print("It is not a jolly jumper sequence")
    }
}

/*
INPUT :
n = 6
a = [14 9 13 12 10 7]
OUTPUT :
It is a jolly jumper sequence
*/
