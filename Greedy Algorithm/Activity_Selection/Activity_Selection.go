/*
The problem statement for Activity Selection is that "Given a set of n activities with their start and finish times, we need to select maximum number of non-conflicting activities that can be performed by a single person, given that the person can handle only one activity
at a time." The Activity Selection problem follows a Greedy approach.
*/

package main

import (
    "fmt"
)

// Function to compute the activities to be chosen
func activitySelection(start []int, finish []int, size int) {
    // second step is to print first activity from sorted activity
    i := 0
    fmt.Println("Following activities are selected: ")
    fmt.Printf("%d ", i)
    // do following in sorted activities:
    // If the start time of this activity is greater than the finish time of previously
    // selected activity then select this activity and print it
    for j := 1; j < size; j++ {
        if start[j] >= finish[i] {
            fmt.Printf("%d ", j)
            i = j
        }
    }
}

// Driver function
func main() {
    // The array of n elements where start[i] denotes starting time of ith activity    
    start := []int{1, 3, 1, 5, 6, 8}
    // The array of n elements where finish[i] denotes finish time of ith activity    
    finish := []int{2, 6, 6, 7, 8, 10}
    size := len(finish)
    activitySelection(start, finish, size)
}

/*
Input:
Start
1 3 1 5 6 8
Finish
2 6 6 7 8 10

Output:
Following activities are selected
 0 1 4 5
*/
