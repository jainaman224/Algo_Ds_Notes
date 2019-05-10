/*
        GEOMETRIC PROGRESSION

        Any sequence of elements where the quotient between any two 
        consecutive elements is equal is termed to be in G.P.
        The nth term of an G.P. is defined as (a * r^(n-1))
        where a is the first element of the G.P.
        r is the common ratio of the G.P.
*/

package main

import (
    "fmt"
    "math"
)

func main() {
    fmt.Print("Enter the First Term of G.P.")
    var a int
    fmt.Scan(&a)
    fmt.Print("Enter the common ratio")
    var r float64
    fmt.Scan(&r)
    fmt.Print("Enter N (The index of term to find)")
    var n float64
    fmt.Scan(&n)
    fmt.Print("The term at index ", n , " is ", (a * int(math.Pow(r, n - 1))))
}

/*
    INPUT : a = 5
            r = 2
            n = 7
    OUTPUT : The term at index 7 is 320
    VERIFICATION : The G.P. would be 5,10,20,40,80,160,320...
*/
