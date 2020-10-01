/*
NEXT PERFECT SQUARE

A perfect square is a number which can be expressed as a product of 
two equal numbers. The task is to find the first such number greater 
than the given number.
*/

package main

import (
    "fmt"
    "math"
)

func main() {
    var n float64
    fmt.Print("Enter N: ")
    fmt.Scan(&n)
    x := math.Floor(math.Sqrt(n)) + 1
    fmt.Print("The next perfect square is ", (x * x))
}

/*
    INPUT : n = 1091
    OUTPUT: The next perfect square is 1156
    VERIFICATION : 1156 = 34 * 34
                   Hence it is a perfect square.
*/
