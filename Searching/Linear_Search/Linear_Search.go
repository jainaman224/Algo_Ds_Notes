package main

import (
	"fmt"
	"strconv"
)

// LinearSearch searches the complete slice and
// returns the index of the desired element if found in the slice.
func LinearSearch(a []int, d int) int {
	for i := range a {
		if a[i] == d {
			return i
		}
	}
	return -1
}

func main() {
	a := []int{2, 4, 6, 7, 3, 1, 5}
	index := LinearSearch(a, 7)

	// Element 4 to be searched
	if index != -1 {
		fmt.Println("found 7 at ", strconv.Itoa(index))
	} else {
		fmt.Println("Not Found")

	}

}
