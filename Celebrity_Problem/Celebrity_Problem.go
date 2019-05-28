/*
CELEBRITY PROBLEM

In a group of N people, there is 1 person, who is known to everyone, but
he knows noone.
We need to find such a person, if present.

There will be a matrix input, such that M[i][j] = 1, if ith person
knows jth person, else 0.
*/

package main

import (
    "fmt"
)

func Celebrity(Person [][]int, n int) int {
    start := 0
    end := n - 1
    for (true) {
        if (start == end) {
            break
        }
        if (Person[start][end] == 1) {
            start++
        } else {
            end--
        }
    }
    for i := 0; i < n; i++ {
        if (i == start) {
            continue
        }
        if (Person[start][i] == 1 || Person[i][start] == 0) {
            return -1
        }
    }
    return start
}

func main() {
    var n int
    fmt.Scan(&n)
    Person := make([][]int, n)
    for i := 0; i < n; i++ {
        Person[i] = make([]int, n)
    }
    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            fmt.Scan(&Person[i][j])
        }
    }
    celeb := Celebrity(Person, n)
    if (celeb >= 0) {
        fmt.Print("Celebrity Present at index ", celeb)
    } else {
        fmt.Print("Celebrity not present")
    }
}

/*
INPUT : n = 5
Person = 0 1 0 0 1
         0 0 0 0 0
         1 1 1 0 0
         1 1 0 0 1
         0 1 1 1 0
OUTPUT :
Celebrity Present at index 1
*/
