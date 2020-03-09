/*
PYTHAGOREAN TRIPLETS

Three numbers - a, b and c are said to be pythagorean triplets if following
formula holds :

a^2 + b^2 = c^2
*/

package main

import (
    "fmt"
)

func main() {
    var a int
    var b int
    var c int
    fmt.Print("Enter a: ")
    fmt.Scan("%d", &a)
    fmt.Print("Enter b: ")
    fmt.Scan("%d", &b)
    fmt.Print("Enter c: ")
    fmt.Scan("%d", &c)
    var sq_a int = a * a
    var sq_b int = b * b
    var sq_c int = c * c
    if sq_a + sq_b == sq_c || sq_a + sq_c == sq_b || sq_b + sq_c == sq_a {
        fmt.Print("It is a pythagorean triplet")
    } else {
        fmt.Print("It is not a pythagorean triplet")
    }
}

/*
    INPUT : a = 8 b = 6 c = 10
    OUTPUT: It is a pythagorean triplet
    VERIFICATION : 6^2 + 8^2 = 36 + 64 = 100
                   10^2 = 100
*/
