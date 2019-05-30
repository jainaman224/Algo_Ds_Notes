/* The sum of digits of a number is the mathematical addition
of the digits extracted from the number.
Example: number = 12345, sum = 1 + 2 + 3 + 4 + 5 = 15
number = 1005, sum = 1 + 0 + 0 + 5 = 6 */

package main
import "fmt"

func sumOfDigits(N int) int {
    var a int
    var sum int
    for (N > 0) {
        a = N % 10
        sum += a
        N /= 10
    }
    return sum
}

func main() {
    var N int
    fmt.Printf("Enter number:\n")
    fmt.Scanf("%d", &N)
    ans := sumOfDigits(N)
    fmt.Printf("The sum of digits of %d is %d", N, ans)
}

/*
Input:
12345

Output:
The sum of digits of 12345 is 15

Input:
1000

Output:
The sum of digits of 1000 is 1
*/

