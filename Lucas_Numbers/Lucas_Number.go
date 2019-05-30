/*
LUCAS NUMBERS

These numbers are similar to Fibonacci Numbers. The only difference
is that the first two terms are 2 and 1.
*/

package main

import (
    "fmt"
)

func lucas(n int) int {
    var a []int
    a = append(a, 2)
    a = append(a, 1)
    for i := 2; i < n; i++ {
        a = append(a, a[i - 1] + a[i - 2])
    }
    return a[n - 1]
}

func lucas_recursive(n int) int {
    if (n == 1) {
        return 2
    }
    if (n == 2) {
        return 1
    }
    return lucas_recursive(n - 1) + lucas_recursive(n - 2)
}

func main() {
    var number int
    fmt.Scan(&number)
    fmt.Print("The Lucas number at position ", number, " is ", lucas(number))
}

/*
INPUT :
n = 8
OUTPUT :
The Lucas number at position 8 is 29
*/
