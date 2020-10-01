/*
    Compound Interest = P(1 + R/100)^T
    
    P is principle amount
    R is the rate and
    T is the time span
*/

package main

import(
    "fmt"
    "math"
)    

func main() {
    var p, r, t float64
    fmt.Print("Enter Principal: ")
    fmt.Scan(&p)
    fmt.Print("Enter Rate: ")
    fmt.Scan(&r)
    fmt.Print("Enter Time: ")
    fmt.Scan(&t)
    fmt.Print(p * (math.Pow((1 + r / 100), t)))
}

/*
INPUT : p = 1000, r = 8, t = 2
OUTPUT : 1166.40
*/
