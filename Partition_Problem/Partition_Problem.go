/*
PARTITION PROBLEM

The problem is to identify if a given set of n elements can be divided
into two separate subsets such that sum of elements of both the subsets
is equal.
*/

package main

import (
    "fmt"
)

func check(a []int, sum int, ind int) bool {
    if (sum == 0) {
        return true
    }
    if (ind == -1 || sum < 0) {
        return false
    }
    if (a[ind] > sum) {
        return check(a, sum, ind - 1)
    }
    return check(a, sum - a[ind], ind - 1) ||
    check(a, sum, ind - 1)
}

func main() {
    var n int
    fmt.Scan(&n)
    var a []int
    var sum int = 0
    for i := 0; i < n; i++ {
        var temp int
        fmt.Scan(&temp)
        a = append(a, temp)
        sum = sum + a[i]
    }
    if (sum % 2 == 1) {
        fmt.Print("Not Possible")
    } else {
        if (check(a, sum / 2, n - 1)) {
            fmt.Print("Possible")
        } else {
            fmt.Print("Not Possible")
        }
    }
}

/*
INPUT :
n = 4
a = [1, 4, 3, 2]
OUTPUT :
Possible
VERIFICATION :
Set can be divided into two sets :
[1, 4] and [3, 2], both of whose sum is 5.
*/
