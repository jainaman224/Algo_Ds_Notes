package main
 
import (
   "fmt"
   "strconv"
)

func main() {
  var number int
  fmt.Println("Enter a number to check if it is a Armstrong number")
  fmt.Scan(&number)
  fmt.Println(Armstrong(number))
}

func Armstrong(number int) bool {
   tmp := number
   digits := len(strconv.Itoa(number))
   sum := 0
   div := 0
   for {
      if tmp <= 0 {
         break;
      }
      div = tmp % 10
      temp := 1
      for i := 0; i < digits; i++ {
         temp = temp * div
      }
      sum += temp
      tmp = tmp / 10
   }
   return number == sum
}