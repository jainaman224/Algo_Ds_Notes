/*
DEARRANGEMENTS

It is a permutation of N elements such that no element appears in 
its original position.
We have to find the number of such permutations possible.

If count(n) = no of dearrangements for n numbers,
we use the generic formula 
count(n) = (n - 1) * [count(n - 1) + count(n - 2)]
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

func main() {
    var number int
    fmt.Scan(&number)
    dearrangements := count(number)
    fmt.Print("The number of dearrangements is ", dearrangements)
}

/*
INPUT : n = 6
OUTPUT: The number of dearrangements is 265
*/
