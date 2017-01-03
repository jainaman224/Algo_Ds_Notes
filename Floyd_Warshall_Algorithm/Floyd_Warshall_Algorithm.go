package main

import (
    "fmt"
    "math"
)

func floyd_warshall(graph [][]float64) [][]float64 {
    dist := make([][]float64, len(graph))

    // Initialises a distance matrix
    for i := range graph {
        dist[i] = make([]float64, len(graph))
    }

    for i := range graph {
        for j := range graph[i] {
            dist[i][j] = graph[i][j]
        }
    }

    // Implements the Floyd Warshall Algorithm
    for k := range dist {
        for i := range dist {
            for j := range dist {
                if dij := dist[i][k] + dist[k][j]; dij < dist[i][j] {
                    dist[i][j] = dij
                }
            }
        }
    }
    return dist
}

func main() {
    graph := [][]float64{
        {0, 5, math.Inf(1), 10},
        {math.Inf(1), 0, 3, math.Inf(1)},
        {math.Inf(1), math.Inf(1), 0, 1},
        {math.Inf(1), math.Inf(1), math.Inf(1), 0},
    }

    dist := floyd_warshall(graph)
    for _, d := range dist {
        fmt.Printf("%4g\n", d)
    }
}

//OUTPUT
//[   0    5    8    9]
//[+Inf    0    3    4]
//[+Inf +Inf    0    1]
//[+Inf +Inf +Inf    0]
