import java.util.Scanner

// Recursive Function for euclidean
fun euclidean(num1: Int, num2: Int):Int {
    var Num1 = num1
    var Num2 = num2
    if (Num1 == 0)
        return Num2

    else
        return euclidean(Num2 % Num1, Num1)
}

// Driver Function
fun main() {
    val scanner = Scanner(System.`in`)
    println("Please Enter Two Integers.")
    val num1 = scanner.nextInt()
    val num2 = scanner.nextInt()
    println("GCD of $num1 and $num2 is ${euclidean(num1, num2)}")
}

/*
  Input:- Please Enter Two Integers.
          55 88
  Output:- GCD of 55 and 88 is 11
*/
