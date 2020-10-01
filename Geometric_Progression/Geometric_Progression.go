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

func sumOfGP(a float64, r float64, n float64) float64 {
    var sum float64 = 0
    var i float64 = 0 
    for i < n { 
        sum = sum + a
        a = a * r
    } 
    return sum
}

func main() {
    fmt.Print("Enter the First Term of G.P.")
    var a float64
    fmt.Scan(&a)
    fmt.Print("Enter the common ratio")
    var r float64
    fmt.Scan(&r)
    fmt.Print("Enter N (The index of term to find)")
    var n float64
    fmt.Scan(&n)
    fmt.Print("The term at index ", n , " is ", (a * float64(math.Pow(r, n - 1))))
    fmt.Print("Sum is: ", sumOfGP(a, r, n))
}

/*
    INPUT : a = 5
            r = 2
            n = 7
    OUTPUT : The term at index 7 is 320
             Sum is: 635
    VERIFICATION : The G.P. would be 5,10,20,40,80,160,320...
*/
