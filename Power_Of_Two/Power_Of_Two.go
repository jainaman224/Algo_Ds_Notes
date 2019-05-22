/*
To check whether a number is a power of two or not,
we do bitwise "and" of number and number - 1, if the
result is zero the number is a power of two.
Example: number = 4, then 4 & 3 i.e 100 && 011 is 0
16 & 15 i.e 10000 & 01111 = 0
This is true for all powers of two.
*/

package main
import "fmt"

func isPowerOfTwo(x int) bool {
    return (x > 0) && ((x & (x - 1)) == 0)
}

func main() {
    var num int
    fmt.Printf("Enter a number to check:\n")
    fmt.Scanf("%d", &num)
    if (isPowerOfTwo(num)) {
        fmt.Printf("The number is a power of two")
    } else {
        fmt.Printf("The number is not a power of two")
    }
}

/*
Input:
64

Output:
The number is a power of two

Input:
5

Output:
The number is not a power of two
*/
