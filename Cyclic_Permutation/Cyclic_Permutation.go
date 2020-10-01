/*
CYCLIC PERMUTATIONS

Cyclic permutations of a number are defined as a number that
can be obtained by rotating the concerned number any number 
of times between it's digits.
*/

package main

import (
    "fmt"
    "math"
)

func getDigits(n int) int{
    var ans int = 0
    for n > 0 {
        ans = ans + 1
        n /= 10
    }
    return ans
}

func cyclic(n int) {
    var length int = getDigits(n)
    var res int = n
    for ;; {
        fmt.Println(res)
        remainder := res % 10
        quotient := res / 10
        res = remainder * int(math.Pow(10, float64(length - 1))) + quotient
        if res == n {
            break
        }
    }
}

func main() {
    fmt.Print("Enter N:")
    var n int
    fmt.Scan(&n)
    cyclic(n)
}

/*
INPUT : n = 6534
OUTPUT: 6534
        4653
        3465
        5346
*/
