package main

import (
	"bufio"
	"flag"
	"log"
	"os"
	"strconv"
	"strings"
)

var (
	input = flag.String("i", "test_set.txt", "input filename")
)

const (
	maxint = 1<<63 - 1
)

func smallestPath(a [][]int, n int) (s int, cycle bool) {
	for k := 0; k < n; k++ {
		a = nextK(a, n, k)
	}
	cycle = detectCycle(a, n)
	s = minVal(a, n)
	return
}

func minInt(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func minVal(a [][]int, n int) int {
	r := maxint
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i != j && a[i][j] < r {
				r = a[i][j]
			}
		}
	}
	return r
}

func detectCycle(a [][]int, n int) bool {
	for i := 0; i < n; i++ {
		if a[i][i] < 0 {
			return true
		}
	}
	return false
}

func nextK(a [][]int, n, k int) [][]int {
	r := make([][]int, n)
	for i := 0; i < n; i++ {
		r[i] = make([]int, n)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			// case 1
			c1 := a[i][j]
			// case 2
			p := a[i][k]
			q := a[k][j]
			var c2 int
			if p == maxint || q == maxint {
				c2 = maxint
			} else {
				c2 = p + q
			}
			// set min of each case
			r[i][j] = minInt(c1, c2)
		}
	}
	return r
}

func main() {
	flag.Parse()
	f, err := os.Open(*input)
	if err != nil {
		panic(err)
	}
	scanner := bufio.NewScanner(f)
	scanner.Scan()
	params := scanner.Text()
	p := strings.Fields(params)
	n, _ := strconv.Atoi(p[0])
	// m, _ := strconv.Atoi(p[1])

	a := make([][]int, n)
	for x := range a {
		a[x] = make([]int, n)
		for y := range a[x] {
			if x == y {
				a[x][y] = 0
			} else {
				a[x][y] = maxint
			}
		}
	}

	for scanner.Scan() {
		line := scanner.Text()
		fields := strings.Fields(line)
		u, err := strconv.Atoi(fields[0])
		if err != nil {
			panic(err)
		}
		v, err := strconv.Atoi(fields[1])
		if err != nil {
			panic(err)
		}

		c, err := strconv.Atoi(fields[2])
		if err != nil {
			panic(err)
		}
		a[u-1][v-1] = c
	}
	minC, cycle := smallestPath(a, n)
	log.Printf("The Shortest distance from src %d\n", minC)
	if cycle {
		log.Println("There was a negative cost cycle detected.")
	}
}
