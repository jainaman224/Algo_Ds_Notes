/*
POWER SET

A power set of a set is the set of all possible subsets of 
a given set S. 
example - {a, b, c} :
Power Set = {}, {a}, {b}, {c}, {a, b}, {a, c},  {a, b}, {b, c}, 
            {a, b, c}

Total elements in a power set of a set with n elements = 2^n
*/

package main

import (
    "fmt"
)

func PowerSet(a []int, b []int, n int, index int) {
    if (index == n) {
        fmt.Print("{")
        for i := 0; i < n; i++ {
            if (b[i] == 1) {
                fmt.Print(a[i], " ")
            }
        }
        fmt.Print("}\n")
        return
    }
    PowerSet(a, b, n, index + 1)
    b[index] = 1
    PowerSet(a, b, n, index + 1)
    b[index] = 0
}

func main() {
    var n int
    fmt.Scan(&n)
    var a []int
    var b []int
    for i := 0; i < n; i++ {
        var temp int
        fmt.Scan(&temp)
        a = append(a, temp)
        b = append(b, 0)
    }
    PowerSet(a, b, n, 0)
}

/*
INPUT : n = 3
        a = [3, 15, 32]
OUTPUT :
{}
{32 }
{15 }
{15 32 }
{3 }
{3 32 }
{3 15 }
{3 15 32 }
*/
