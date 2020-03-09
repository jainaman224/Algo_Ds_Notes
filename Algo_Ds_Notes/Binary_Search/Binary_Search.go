package main

import (
	"fmt"
	"strconv"
)

func binarySearch(array []int, desired int) (index int) {
    if len(array) <= 1 {
        index = -1
        return
    }

    left := 0
    right := len(array) - 1
    for left <= right {
        mid := left + (right-left)/2
        if array[mid] < desired {
            left = mid + 1
        } else if array[mid] > desired {
            right = mid - 1
        } else {
            index = mid
            return
        }
    }
    return
}

func main() {
    var num int
    fmt.Scan(&num)
    array := []int{}
    for i := 0; i < num; i++ {
        var x int
        fmt.Scan(&x)
        array = append(array, x)
    }
	
    // Element to search
    var desired int
    fmt.Scan(&desired)
    index := binarySearch(array, desired)
    if index != -1 {
        fmt.Println("Found at ", strconv.Itoa(index))
    } else {
        fmt.Println("Not Found")
    }
}

/* Output
Input:
num = 7
array = {1, 2, 3, 4, 5, 6, 7}
desired = 4

Output:
Found

Input:
num = 5
array = {1, 3, 5, 7, 9}
desired = 2

Output:
Not Found
*/
