fun square_root(num: Float):Float {
    var number = num
    var guess = 1F
    var accuracy = 0.000001
    while(number - guess > accuracy) {
        number = (number + guess) / 2
        guess = num / number
    }
    return number
}

//Driver Function for Babylonian
fun main() {
    //let number be 90
    var num = 90
    println("Square Root of $num is ${square_root(num.toFloat())}")
}

//Output: Square Root of 90 is 9.486834
