/* Extended Euclidean Algorithm
==============================
GCD of two numbers is the largest number that divides both of them.
A simple way to find GCD is to factorize both numbers and multiply
common factors.

GCD(a,b) = ax + by

If we can find the value of  x and y then we can easily find the
value of GCD(a,b) by replacing (x,y) with their respective values.
*/

package main

import (
    "fmt"
    "log"
)

// Function for Extended Euclidean algorithm
func ext_gcd(a int, b int) (int, int, int) {
    if a == 0 {
        return b, 0, 1
    }

    var gcd, x, y = ext_gcd(b % a, a)

    return gcd, (y - (b/a) * x), x
}

func main() {
    var a, b int
    fmt.Println("Input numbers : ")
    _, err := fmt.Scanf("%d %d", &a, &b)
    if err != nil {
        log.Fatal(err)
    } else {
        var gcd, x, y = ext_gcd(a, b)
        fmt.Printf("GCD = %d\n", gcd)
        fmt.Printf("x = %d, y = %d\n", x, y)
        fmt.Printf("%d * %d + %d * %d = %d\n", a, x, b, y, gcd)
    }
}
/*
Example :
Input numbers :
30 50
GCD = 10
x = 2, y = -1
30 * 2 + 50 * -1 = 10
*/
