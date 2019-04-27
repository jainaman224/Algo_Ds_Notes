/* Babylonian method for square root
  1. Start with an arbitrary positive start value x (the closer to the 
     root, the better).
  2. Initialize y = 1.
  3. Do following until desired approximation is achieved.
      a) Get the next approximation for root using average of x and y
      b) Set y = n/x */

package main

import (
    "fmt"
    "strconv"
)

func squareRoot(num float64) float64{    
    var number = num 
    var guess float64 = 1
    var accuracy = 0.000001 /* it decides the accuracy level*/
    for (number - guess > accuracy) {
        number = (number + guess) / 2 
        guess = num / number // to get next approximation 
    } 
    return number; 
} 

func main(){
    var num float64 = 2
    fmt.Print("Square root of " + strconv.Itoa(int(num)) + " is " +  fmt.Sprintf("%f", squareRoot(num)))
}

/*Enter a number :
2
Square root of 2 is 1.414214 */
