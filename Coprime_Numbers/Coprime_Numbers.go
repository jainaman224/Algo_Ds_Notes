/*
Two integers a and b are said to be coprime if the only positive
integer that divides both of them is 1 i.e their greatest common
divisor or GCD is 1.
Example: 5 and 7, as gcd(5, 7) = 1
9 and 11, as gcd(9, 11) = 1
*/

package main
import "fmt"

func gcd(x int, y int) int {
    if x == 0 {
        return y
    }
    return gcd(y % x, x)
}

func isCoprime(a int, b int) int {
    if gcd(a, b) == 1 {
        return 1
    }
    return 0
}

func main() {
    var a int
    var b int
    fmt.Println("Enter two numbers")
    fmt.Scanf("%d%d", &a, &b)
    ans := isCoprime(a, b)
    if ans == 1 {
        fmt.Printf("The numbers are coprime")
    } else {
        fmt.Printf("The numbers are not coprime")
    }
}

/*
Input:
9
11

Output:
The numbers are coprime

Input:
4
12

Output:
The numbers are not coprime
*/
