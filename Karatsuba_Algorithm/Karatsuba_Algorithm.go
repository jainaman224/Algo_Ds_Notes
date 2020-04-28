// Karatsuba Algorithm In GO

/**

The Karatsuba Algorithm is a fast multiplication algorithm. 
It was discovered by Anatoly Karatsuba in 1960. It reduces 
the multiplication of two n-digit numbers to at most single 
digit multiplications in general. It is therefore faster 
than classical multiplication operation.

*/

package main

// Importing Necessary Packages
import 
(
    "fmt"
    "math"
)

// Input Function To Get The Digits
func getDigits(number int64) uint {

    var ans uint

    if number == 0 {
        return 1
    }

    if number < 0 {
        number = -number
    }

    for number > 0 {
        ans++
        number = number / 10
    }

    return ans
}

func getHighAndLowDigits(num int64, digits uint) (int64, int64) {

    divisor := int64(math.Pow(10, float64(digits)))

    if num >= divisor {
        return num / divisor, num % divisor
    } 
    else {
        return 0, num
    }
}

// Karatsuba Algorithm Function
func karatsuba(x int64, y int64) int64 {

    var max_digits uint
    positive := true

    if x == 0 || y == 0 {
        return 0
    }

    if (x > 0 && y < 0) || (x < 0 && y > 0) {
        positive = false
    }

    if x < 0 {
        x = -x
    }

    if y < 0 {
        y = -y
    }

    if x < 10 || y < 10 {
        return x * y
    }

    x_digits := getDigits(x)
    y_digits := getDigits(y)

    if x_digits >= y_digits {
        max_digits = x_digits / 2
    } 
    else {
        max_digits = y_digits / 2
    }

    x_high, x_low := getHighAndLowDigits(x, max_digits)
    y_high, y_low := getHighAndLowDigits(y, max_digits)

    z0 := karatsuba(x_low, y_low)
    z1 := karatsuba((x_low + x_high), (y_low + y_high))
    z2 := karatsuba(x_high, y_high)

    if positive {
        return (z2 * int64(math.Pow(10, float64(2 * max_digits)))) + 
            (z1 - z2 - z0) * int64(math.Pow(10, float64(max_digits))) + z0
    } 
    else {
        return -((z2 * int64(math.Pow(10, float64(2 * max_digits)))) + 
            (z1 - z2 - z0) * int64(math.Pow(10, float64(max_digits))) + z0)
    }
}

// Main Function & Taking User Inputs
func main() {

    fmt.Println("Enter the first number: ")
    var first int64
    fmt.Scanln(&first)

    fmt.Println("Enter the second number: ")
    var second int64
    fmt.Scanln(&second)
    fmt.Println()

    fmt.Print("Result: ")
    fmt.Println(karatsuba(first, second))
}

/**

Enter the first number: 121547 
Enter the second number: 1855324

Result: 225509066228

Enter the first number: -8859460 
Enter the second number: 1154486

Result: -10228122537560

*/
