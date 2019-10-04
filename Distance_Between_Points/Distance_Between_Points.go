/*
DISTANCE BETWEEN COORDINATES

Suppose you are given n co-ordinate points in a 2D plane. The task
is to find the total sum of distance between all those points.
Basically it is computing the perimeter of the complete polygon 
formed by those n co-ordinate points. 

For calculating the distance between two points (x1, y1) & (x2, y2),
we calculate -> sqrt((x1 - x2)^2 + (y1 - y2)^2)
*/

package main

import (
    "fmt"
    "math"
)

func main() {
    var n int
    fmt.Scan(&n);
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
    var distance float64 = 0
    for i := 0; i < n; i++ {
        for j := i + 1; j < n; j++ {
            var sq_x float64 = math.Abs(float64(x[i] - x[j]))
            var sq_y float64 = math.Abs(float64(y[i] - y[j]))
            distance = distance + math.Sqrt(sq_x * sq_x + sq_y * sq_y)
        }
    }
    fmt.Print(distance)
}

/*
INPUT :
n = 4
x = [1, 4, 3, 2]
y = [2, 5, 4, 1]
OUTPUT :
17.5339
*/
