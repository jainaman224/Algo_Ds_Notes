/*
DIGIT COUNT OF A NUMBER

The task is to count the number of digits present in the given
number.
*/

package main

import (
    "fmt"
)

func getDigits(n int) int{
    var ans int = 0
    for n > 0 {
        ans = ans + 1
        n /= 10
    }
    return ans
}

func main() {
    fmt.Print("Enter N: ")
    var n int
    fmt.Scan(&n)
    fmt.Print("Number of digits is : ", getDigits(n))
}

/*
INPUT : n = 6534
OUTPUT: Number of digits is : 4
*/
