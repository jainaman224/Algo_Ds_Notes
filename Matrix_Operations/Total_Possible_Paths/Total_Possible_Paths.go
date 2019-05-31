/*
TOTAL PATHS FROM (0, 0) to (m, n)

The task is to calculate total possible moves we can make to reach
(m, n) in a matrix, starting from origin, given that we can only take
1 step towards right or up in a single move.
*/

package main 

import (
    "fmt"
    "math"
)

func totalPaths(m, n int) int{
    var total [][]int
    for i := 0; i < m; i++ {
        var temp []int
        for j := 0; j < n; j++ {
            temp = append(temp, 0)
        }
        total = append(total, temp)
    }
    for i := 0; i < int(math.Max(float64(m), float64(n))); i++ {
        if (i < m) {
            total[i][0] = 1
        }
        if (i < n) {
            total[0][i] = 1
        }
    }
    for i := 1; i < m; i++ {
        for j := 1; j < n; j++ {
            total[i][j] = total[i - 1][j] + total[i][j - 1]
        }
    }
    return total[m-1][n-1]
}

func main() {
    var m int
    var n int
    fmt.Scan(&m)
    fmt.Scan(&n)
    fmt.Print("The total paths are ", totalPaths(m, n))
}

/*
INPUT :
n = 6
m = 5
OUTPUT :
The total paths are 126
*/
