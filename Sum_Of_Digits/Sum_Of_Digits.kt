import java.util.*

fun main(args: Array<String>) {
    val read = Scanner(System.`in`)
    print("Enter the Number : ")
    var num = read.nextInt()
    var sum = 0
    while(num > 0)
    {
        var a = num % 10
        sum += a
        num /= 10
    }
    println("The sum of digits of given number is : ${sum}")
}

/*
    Input : Enter the Number : 223
    Output : The sum of digits of given number is : 7
*/
