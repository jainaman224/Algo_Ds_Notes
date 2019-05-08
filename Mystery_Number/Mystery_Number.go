/*
    MYSTERY NUMBER

    A Mystery Number is a number that can be expressed as a sum of two numbers,
    where those two numbers are reverse of each other.
*/

package main

import (
    "fmt"
)

/*  Approach : We iterate over from 1 to n/2, to get all the pairs of number, that
                can sum up to the given no. n. and check if the numbers in the pair 
                are reverse of each other.
*/
func rev(num int) int {
    var ans = 0
    for (num > 0) {
        ans *= 10
        ans += (num % 10)
        num /= 10
    }
    return ans
}

func solve(num int) int {
    for i := 1; i <= num / 2; i++ {
        if rev(i) == num - i {
            return 1
        }
    }
    return 0
}

func main() {
    var num int
    fmt.Scan(&num)
    var ans = solve(num)
    if (ans == 1) {
        fmt.Print("It is a mystery number")
    } else {
        fmt.Print("It is not a mystery number")
    }
}

/*
    Input: num : 22
    Output: It is a mystery number.
    Verification: 22 can be expressed as sum of pair (11, 11).
                  Here, 11 and 11 are reverse of each other. Hence,
                  22 is a mystery number.
*/
