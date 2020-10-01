/* Reverse of a number is the number obtained when we read 
the original number backwards. 
Example: number = 12345, reverse = 54321
number = 1005, reverse = 5001 */

package main
import "fmt"

// function to reverse a number
func reverse(N int) int {
    var a int
    var rev int
    for (N > 0) {
        a = N % 10
        rev = rev * 10 + a
        N /= 10
    }
    return rev
}

func main() {
    var N int
    fmt.Printf("Enter number to reverse:\n")
    fmt.Scanf("%d", &N)
    ans := reverse(N)
    fmt.Printf("The reverse of %d is %d", N, ans)
}

/*
Input:
12345

Output:
The reverse of 12345 is 54321

Input:
1000

Output:
The reverse of 1000 is 1
*/
