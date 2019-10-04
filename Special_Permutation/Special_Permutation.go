/*
SPECIAL PERMUTATION

A Special Permutation is a permutation of n numbers such that there
are at-least (n - k) indices where the value is equal to the index
of that number.
*/

package main

import (
    "fmt"
)

func count(number int) int {
    var dearrangement []int
    dearrangement = append(dearrangement, 1)
    dearrangement = append(dearrangement, 0)
    dearrangement = append(dearrangement, 1)

    for i := 3; i <= number; i++ {
        temp := (i - 1) * 
        (dearrangement[i - 1] + dearrangement[i - 2])
        dearrangement = append(dearrangement, temp)
    }
    return dearrangement[number]
}

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

func special_permutation(n, k int) int {
    ans := 0
    for i := n - k; i <= n; i++ {
        ans = ans + (nCr(n, i, mod) * count(n - i))
    }
    return ans
}

func main() {
    var number int
    var k int
    fmt.Scan(&number)
    fmt.Scan(&k)
    special := special_permutation(number, k)
    fmt.Print("The number of special permutations is ", special)
}

/*
INPUT :
n = 7
k = 3
OUTPUT :
The number of special permutations is 92
*/
