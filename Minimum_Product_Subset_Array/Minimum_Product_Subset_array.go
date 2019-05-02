/*
    MINIMUM PRODUCT SUBSET OF AN ARRAY

    Given an array of n elements. We need to find the minimum product possible
    with any subset of that array.
*/
package main
import "fmt"

var neg = 0
var pos = 0
var zero = 0
var prod = 1
var max_neg = -10000000
var min_pos = 10000000

/*
    Approach : Two negative numbers multiply together to form a positive number.
               Hence, the minimum product in case of odd frequency of negative 
               numbers will be the product of entire array except zero.
               In case of even frequency of negative numbers, we exclude the 
               smallest negative number from the product of the array to get our
               answer.
               Also, in case of single negative number and no positive number in 
               the array, the answer would be the negative number itself.
*/
func solve(temp []int, num int) int {
    if (num == 1) {
        return temp[0]
    }
    if zero == num || (neg == 0 && zero > 0) {
        return 0
    }
    if pos == num {
        return min_pos
    }
    if neg % 2 == 0 && neg > 0 {
        prod = prod / max_neg
    }
    return prod
}

func main() {
    var num = 5
    var temp = []int{5, -2, 4, -3, 1}
    for i := 0; i < num; i++ {
        if temp[i] > 0 {
            pos = pos + 1
            if temp[i] < min_pos {
                min_pos = temp[i]
            }
        }else if temp[i] == 0 {
            zero = zero + 1
            continue
        }else {
            neg = neg + 1
            if temp[i] > max_neg {
                max_neg = temp[i]
            }
        }
        prod = prod * temp[i]
    }
    ans := solve(temp, num)
    fmt.Print("Minimum Product Subset is : ", ans)
}

/*
    Input: Array : [5, -2, 4, -3, 1]
    Output: Minimum Product Subset is : -60
    Verification: The product of array is 120. Since, there are even numbers of
                  negative numbers present in the array, we exclude the smallest
                  negative number (-2) from the product to get our desired answer.
                  (120 / (-2) == -60)
*/
