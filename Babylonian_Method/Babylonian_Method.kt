import java.util.Scanner

fun square_root(num: Float): Float {
    var number = num
    var guess = 1F
    var accuracy = 0.000001
    while (number - guess > accuracy) {
        number = (number + guess) / 2
        guess = num / number
    }
    return number
}

fun main() {
    // Taking Input from user.
    val scanner = Scanner(System.`in`)
    var num = scanner.nextInt()
    println("Square Root of $num is ${square_root(num.toFloat())}")
}

// Input :- 90
// Output: Square Root of 90 is 9.486834
