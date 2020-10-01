/*
Leap year is an year with 366 days. Leap Year should be divisible by 4.
Also it should be divisible by 400 and not divisible by 100.
*/

package main
import "fmt"

func checkLeapYear(year int) bool {
    if year % 400 == 0 {
        return true
    }
    if year % 100 == 0 {
        return false
    }
    if year % 4 == 0 {
        return true
    }
    return false
}

func findLeapYears(year1 int, year2 int) {
    fmt.Printf("The leap years between %d and %d are:\n", year1, year2)
    for i := year1; i <= year2; i++ {
        if (checkLeapYear(i)){
            fmt.Println(i)
        }
    }
}

func main() {
    var year1 int
    var year2 int
    fmt.Println("Enter first year:")
    fmt.Scanf("%d", &year1)
    fmt.Println("Enter second year:")
    fmt.Scanf("%d", &year2)
    findLeapYears(year1, year2)
}

/*
Input:
2000
2050

Output:
The leap years between 2000 and 2050 are:
2000
2004
2008
2012
2016
2020
2024
2028
2032
2036
2040
2044
2048
*/
