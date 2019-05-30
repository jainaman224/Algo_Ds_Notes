/*
PYTHAGOREAN QUADRUPLES

Four numbers - a, b , c and d are said to be pythagorean quadruples if following
formula holds :

a^2 + b^2 + c^2 = d^2
*/

package main

import (
    "fmt"
)

func main() {
    var a int
    var b int
    var c int
    var d int
    fmt.Print("Enter a: ")
    fmt.Scan("%d", &a)
    fmt.Print("Enter b: ")
    fmt.Scan("%d", &b)
    fmt.Print("Enter c: ")
    fmt.Scan("%d", &c)
    fmt.Print("Enter d: ")
    fmt.Scan("%d", &d)
    var sq_a int = a * a
    var sq_b int = b * b
    var sq_c int = c * c
    var sq_d int = d * d
    if sq_a + sq_b + sq_d == sq_c || sq_a + sq_c + sq_d == sq_b || 
    sq_b + sq_c + sq_d == sq_a || sq_a + sq_b + sq_c == sq_d {
        fmt.Print("It is a pythagorean quadruple");
    } else {
        fmt.Print("It is not a pythagorean quadruple");
    }
}

/*
    INPUT : a = 3 b = 6 c = 2 d = 7
    OUTPUT: It is a pythagorean quadruple
    VERIFICATION : 3^2 + 6^2 + 2^2 = 9 + 36 + 4 = 49
                   7^2 = 49
*/
