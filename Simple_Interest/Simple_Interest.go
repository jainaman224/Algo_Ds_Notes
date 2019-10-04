/*
SIMPLE INTEREST

Simple Interest in Accounting is calculated as :

S.I. = (p * r * t) / 100
where p = principal amount
      r = rate of interest
      t = time
*/

package main

import "fmt"

func main() {
    var p, r, t float64
    fmt.Print("Enter Principal: ")
    fmt.Scan(&p)
    fmt.Print("Enter Rate: ")
    fmt.Scan(&r)
    fmt.Print("Enter Time: ")
    fmt.Scan(&t)
    fmt.Print("Simple Interest is: ", ((p * r * t) / 100))
}

/*
INPUT : p = 1000, r = 8, t = 2
OUTPUT : Simple Interest is: 160.00
*/
