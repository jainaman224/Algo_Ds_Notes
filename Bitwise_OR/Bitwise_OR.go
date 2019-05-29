package main

import(
    "fmt"
)

// Function to find bitwise OR 
func OR(array[] int, num int) { 
    var ans int = array[0]
    for i := 0; i < num; i++ { 
        ans |= array[i]
    }
    fmt.Println(ans) 
} 

// Driver program 
func main() { 
    var num int
    fmt.Scan(&num)
    array := []int{}
    for i := 0; i < num; i++ {
        var x int
        fmt.Scan(&x)
        array = append(array, x)
    }       
    OR(array, num); 
}

/*
Input: 
num = 3
array[] = {4, 5, 6}
Output:
7
Because 4 = 100, 5 = 101, 6 = 110 in binary .
OR of 4 and 5 is 101(5) in binary and
OR of 5(resultant of 4 and 5) and 6 is 111(7).
so, answer is 7.
*/
