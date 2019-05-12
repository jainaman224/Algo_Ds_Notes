package main

import (
	"fmt"
	"strconv"
)

// LinearSearch searches the complete slice and
// returns the index of the desired element if found in the slice.
func linearSearch(a []int, d int) int {
	for i := range a {
		if a[i] == d {
			return i
		}
	}
	return -1
}

func main() {
	var num int
	fmt.Scan(&num)
	a := []int{}
	for i := 0; i < num; i++ {
		var x int
		fmt.Scan(&x)
		a = append(a, x)
	}
	var desired int
	fmt.Scan(&desired)
	var index = linearSearch(a, desired)
	if index != -1 {
		fmt.Println("found 7 at ", strconv.Itoa(index))
	} else {
		fmt.Println("Number not found")
	}
}

/*
Input :
num = 5
arr = [1,4,5,6,3]
desired = 3

Output :
Number not found
*/
