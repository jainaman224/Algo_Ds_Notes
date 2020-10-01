/*
    The sum of cubes of first N natural numbers is given
    by the equation (N * (N + 1) / 2) ^ 2 i.e.
    1^3 + 2^3 + 3^3 + 4^3 + 5^3.........N^3 sums upto
    (N * (N + 1) / 2) ^ 2
*/

package main
import (
    "fmt"
    "math"
)

func main(){
    var N int
    fmt.Printf("Enter the value of N: \n")
    fmt.Scanf("%d", &N)
    var ans float64
    ans = math.Pow(float64(N * (N + 1) / 2), float64(2))
    fmt.Println(ans)
}

/*
Input:
N = 5

Output:
ans = 225

Verification:
1^3 + 2^3 + 3^3 + 4^3 + 5^3
= 1 + 8 + 27 + 64 + 125
= 225
*/
