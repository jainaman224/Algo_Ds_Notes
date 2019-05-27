/*
PARTIAL DEARRANGEMENTS

A partial dearrangement is a dearrangement where some points are
fixed. That is, given a number n and a number k, we need to find
count of all such dearrangements of n numbers, where k numbers are
fixed in their position.
*/

package main

import (
    "fmt"
)

var mod int = 1000000007

func nCr(n int, r int, mod int) int {
    if (n < r) {
        return -1
    }
    // We create a pascal triangle.
    var Pascal []int
    Pascal = append(Pascal, 1)
    for i := 1; i <= r; i++ {
        Pascal = append(Pascal, 0)
    }
    
    // We use the known formula nCr = (n-1)C(r) + (n-1)C(r-1) for computing the values.
    for i := 1; i <= n; i++ {
        var k int
        if i < r {
            k = i
        } else {
            k = r
        }
        
        // we know, nCr = nC(n-r). Thus, at any point we only need min
        for j := k; j > 0; j-- { 
            // of the two, so as to improve our computation time.
            Pascal[j] = (Pascal[j] + Pascal[j - 1]) % mod
        }
    }
    return Pascal[r]
}

func count(n int, k int) int {
    if (k == 0) {
        if (n == 0) {
            return 1
        }
        if (n == 1) {
            return 0
        }
        return (n - 1) * (count(n - 1, 0) + count(n - 2, 0))
    }
    return nCr(n, k, mod) * count(n - k, 0)
}

func main() {
    var number int
    fmt.Scan(&number)
    var k int
    fmt.Scan(&k);
    dearrangements := count(number, k)
    fmt.Print("The number of partial dearrangements is ", dearrangements)
}

/*
INPUT : n = 6
        k = 3
OUTPUT: The number of partial dearrangements is 40
*/
