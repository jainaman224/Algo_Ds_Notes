/*
TOTAL SET BITS FROM 1 to N

Total set bits in a number n is defined as number of 1s in 
binary representation of the number. The task is to calculate
total number of set bits in all numbers till N.
*/

package main

import (
    "fmt"
)

func setBits(n int) int {
    var bit = 0
    for i := 0; i < n; i++ {
        bit = bit + count(i)
    }
    return bit
}

func count(n int) int {
    var bit = 0
    for (n > 0) {
        bit += n & 1
        n >>= 1
    }
    return bit
}

func main() {
    var n int
    fmt.Scan(&n)
    fmt.Print("The total set bits are ", setBits(n))
}

/*
INPUT :
n = 12
OUTPUT :
The total set bits are 20
*/
