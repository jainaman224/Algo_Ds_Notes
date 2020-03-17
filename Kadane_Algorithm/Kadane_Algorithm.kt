/* Kadagne's Algorithm in Kotlin*/

fun main(args: Array<String>) {
    val numbers = readLine()!!.split(",").map(String::toInt)
    var maxSum = 0
    var sum = 0
    for (number in numbers) {
        sum += number
        maxSum = Math.max(sum, maxSum)
        sum = Math.max(sum, 0)
    }
    print(maxSum)
}