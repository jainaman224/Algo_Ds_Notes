/* Chinese Remainder Theorem :
* Given two arrays number[0..n-1] and remainder[0..n-1]
* Find the minimum possible value of x 
* that produces given remainders, i.e 
* x % number[0] = remainder[0]
* x % number[1] = remainder[1] and so on.
*/

package main

import "fmt"

func inverse(a int, m int) (x1 int) {
    var m0 int = m
    x0 := 0
    x1 = 1
    var quotient int
    var next int

    if m == 1 {
        return 0
    }

    for a > 1 {
        quotient = a / m; next = m
        m = a % m
        a = next; next = x0
        x0 = x1 - quotient * x0
        x1 = next
    }

    if x1 < 0 {
        x1 = x1 + m0
    }

    return x1
}

func CRT(number []int, rem []int, k int) int {
    var prod int = 1
    var prod_exp int

    for i := 0; i < k; i++ {
        prod = prod * number[i]
    }

    var result int = 0

    for i := 0; i < k; i++ {
        prod_exp = prod / number[i]
        result = result + rem[i] * inverse(prod_exp, number[i]) * prod_exp
    }

    return result % prod
}

func main() {
    var n int
    fmt.Println("Enter the size of the array : ")
    fmt.Scan(&n)
    fmt.Println("Enter the number array : ")
    num := make([]int, n)

    for i := 0; i < n; i++ {
        fmt.Scan(&num[i])
    }

    fmt.Println("Enter the remainder array : ")
    rem := make([]int, n)

    for i := 0; i < n; i++ {
        fmt.Scan(&rem[i])
    }

    fmt.Printf("Minimum positive number x is : %d\n", CRT(num, rem, n))
}

/* Input :
Enter the size of the array :
3
Enter the number array :
4 11 9
Enter the remainder array :
1 2 4
Output :
Minimum positive number x is : 13
*/
