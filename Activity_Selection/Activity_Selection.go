package main

import (
	"fmt"
	"strconv"
)

// this algorithm is from wikipage(https://en.wikipedia.org/wiki/Activity_selection_problem)
func activitySelection(startTime []int, finishTime []int) {
	// second step is to print first activity from sorted activity
	fmt.Println("activity 1")
	// do following in sorted activities:
	// If the start time of this activity is greater than the finish time of previously selected activity then select this activity and print it
	preSelected := 0
	for i := 1; i < len(finishTime); i++ {
		if startTime[i] > finishTime[preSelected] {
			fmt.Println("activity", strconv.Itoa(i + 1))
			preSelected = i
		}
	}
}
func main() {
	// first step is to sort activities by finish time, in order to save time, we use an sorted finishTime  array
	startTime := []int{1, 3, 1, 5, 8, 6}
	finishTime := []int{2, 6, 6, 7, 10, 8}
	activitySelection(startTime, finishTime)
}

// Output
// activity 1
// activity 2
// activity 5
