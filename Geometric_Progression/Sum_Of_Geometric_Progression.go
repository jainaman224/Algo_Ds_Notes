/*
        SUM OF GEOMETRIC PROGRESSION

        Any sequence of elements where the quotient between any two
        consecutive elements is equal is termed to be in G.P.
        The nth term of an G.P. is defined as (a * r^(n-1))
        where a is the first element of the G.P.
        r is the common ratio of the G.P.
        n is the number of term.

        The Sum of G.P. is defined as a * (r^n - 1) / (r - 1)
*/

package main

import (
    "fmt"
    "math"
)

func main() {
    fmt.Print("Enter the First Term of G.P.")
    var a float64
    fmt.Scan(&a)
    fmt.Print("Enter the common ratio")
    var r float64
    fmt.Scan(&r)
    fmt.Print("Enter N (The total number of terms)")
    var n float64
    fmt.Scan(&n)
    fmt.Print("The sum of first ", n, " terms of G.P. is ", 
    (a * (math.Pow(r, n) - 1) / (r - 1)))
}

/*
    INPUT : a = 5
            r = 2
            n = 7
    OUTPUT : The sum of first 7 terms of G.P. is 635
    VERIFICATION : The 7 terms of G.P. would be 5,10,20,40,80,160,320
                   Sum = 635
*/
