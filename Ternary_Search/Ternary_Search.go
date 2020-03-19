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
/*
Output
key: 36955                                                                                                                
STEP: 1  l: 0  r 9999                                                                                                     
STEP: 2  l: 5000  r 9999                                                                                                  
STEP: 3  l: 5000  r 7498                                                                                                  
STEP: 4  l: 6250  r 7498                                                                                                  
STEP: 5  l: 6875  r 7498                                                                                                  
STEP: 6  l: 7187  r 7498                                                                                                  
STEP: 7  l: 7343  r 7498                                                                                                  
STEP: 8  l: 7343  r 7419                                                                                                  
STEP: 9  l: 7343  r 7380                                                                                                  
STEP: 10  l: 7362  r 7380                                                                                                 
STEP: 11  l: 7362  r 7370                                                                                                 
STEP: 12  l: 7362  r 7365                                                                                                 
STEP: 13  l: 7362  r 7362                                                                                                 
-1                                                                                                                        
STEP: 1  l: 0  r: 9999  slider1: 3333  slider2: 6666                                                                      
STEP: 2  l: 6667  r: 9999  slider1: 7777  slider2: 8887                                                                   
STEP: 3  l: 6667  r: 7776  slider1: 7036  slider2: 7405                                                                   
STEP: 4  l: 7037  r: 7404  slider1: 7159  slider2: 7281                                                                   
STEP: 5  l: 7282  r: 7404  slider1: 7322  slider2: 7362                                                                   
STEP: 6  l: 7363  r: 7404  slider1: 7376  slider2: 7389                                                                   
STEP: 7  l: 7363  r: 7375  slider1: 7367  slider2: 7371                                                                   
STEP: 8  l: 7363  r: 7366  slider1: 7364  slider2: 7365                                                                   
STEP: 9  l: 7363  r: 7363  slider1: 7363  slider2: 7363                                                                   
-1                                                                                                                        
                                                                                                                          
                                                                                                                          
...Program finished with exit code 0                                                                                      
Press ENTER to exit console.

*/

