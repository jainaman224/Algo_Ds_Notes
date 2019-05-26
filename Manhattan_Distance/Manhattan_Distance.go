/*
MANHATTAN DISTANCE

In a 2D plane, the manhattan distance is equal to the distance needed
to be covered using only vertical and horizontal steps.

M(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|

Given an array of co-ordinates. find the sum of manhattan distances 
of all the coordinates with each other.
*/

package main

import (
    "fmt"
    "math"
)

func Manhattan(x []int, y []int, i int, j int) int {
    return int((math.Abs(float64(x[i] - x[j])) + math.Abs(float64(y[i] - y[j]))))
}

func ManhattanSum(x []int, y []int, n int) int {
    var ans int = 0
    for i := 0; i < n; i++ {
        for j := i + 1; j < n; j++ {
            ans = ans + Manhattan(x, y, i, j)
        }
    }
    return ans
}

func main() {
    var n int
    fmt.Scan(&n)
    var x []int
    var y []int
    for i := 0; i < n; i++ {
        var temp int
        fmt.Scan(&temp)
        x = append(x, temp)
    }
    for i := 0; i < n; i++ {
        var temp int
        fmt.Scan(&temp)
        y = append(y, temp)
    }
    fmt.Print(ManhattanSum(x, y, n))
}

/*
INPUT
x = [3, 3, 2, -2]
y = [6, -5, 0, 2]
OUTPUT
51
*/
