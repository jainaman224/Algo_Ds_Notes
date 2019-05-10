import java.util.*

// Checking whether number is Ugly Number or not
fun UglyNum(number: Int):Int {
    var x = 0
    var number = number
   while (number != 1) {
       if (number % 2 == 0) {
           number /= 2
       }
       else if (number % 3 == 0) {
           number /= 3
       }
       else if (number % 5 == 0) {
           number /= 5
       }
       else {
           x = -1
           break
       }
   }
   return x
}

// Finding Nth Ugly Number
fun NthUglyNum(num: Int):Int {
    var checkNum = 0
    var count = 0
    while (count < num ) {
        checkNum += 1
        var NUM = UglyNum(checkNum)
        if (NUM == 0) {
            count += 1
        }
        else {
            continue
        }
    }
    return checkNum
}

// Driver function for Ugly Number
fun main() {
    val scanner = Scanner(System.`in`)
    println("Please Enter an Integer :")
    val num = scanner.nextInt()
    var result = NthUglyNum(num)
    println("$num th Ugly Number is $result.")
}

// Input:- Please Enter an Integer : 30
// Output:- 30 th Ugly Number is 80.
