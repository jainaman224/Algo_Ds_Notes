package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {

	arraySize := 10000

	arr := createArray(arraySize)

	rand.NewSource(time.Now().UnixNano())
	k := rand.Intn(arr[arraySize-1])

	fmt.Println("key:", k)

	fmt.Println(binarySearch(arr, k))

	fmt.Println(ternarySearch(arr, k))
}

func createArray(size int) []int {

	var retval = make([]int, size, size)

	var acc = 0

	r1 := rand.New(rand.NewSource(time.Now().UnixNano()))

	for i := 0; i < size; i++ {

		acc = acc + r1.Intn(11)

		retval[i] = acc
	}

	// UNCOMMENT FOR ARRAY OUTPUT
	//fmt.Println(retval)

	return retval
}

func ternarySearch(arr []int, k int) int {

	var l = 0
	var r = len(arr) - 1

	var slider1 int
	var slider2 int

	i := 0
	for {
		i++

		//FAIL EXIT CONDITION
		if l > r {
			return -1
		}

		slider1 = l + (r-l)/3
		slider2 = l + 2*((r-l)/3)

		fmt.Println("STEP:", i, " l:", l, " r:", r, " slider1:", slider1, " slider2:", slider2)

		if arr[slider1] == k {
			return slider1
		} else if arr[slider1] > k {
			r = slider1 - 1
		} else if arr[slider2] == k {
			return slider2
		} else if arr[slider2] > k {
			l = slider1 + 1
			r = slider2 - 1
		} else {
			l = slider2 + 1
		}
	}
}

func binarySearch(arr []int, k int) int {

	var l = 0
	var r = len(arr) - 1

	var m = -1

	var step = 0
	for {
		step++

		//FAIL EXIT CONDITION
		if l > r {
			return -1
		}

		fmt.Println("STEP:", step, " l:", l, " r", r)

		m = (l + r) / 2

		if arr[m] > k {
			r = m - 1
		} else if arr[m] < k {
			l = m + 1
		} else {
			return m
		}
	}

}
