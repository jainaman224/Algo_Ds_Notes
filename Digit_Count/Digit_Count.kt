import java.util.*

fun main(args: Array<String>) {
    val read = Scanner(System.`in`)
    print("Enter the Number : ")
    var num = read.nextInt()
    var digits = 0
    while(num > 0)
    {
        digits++
        num /= 10
    }
    println("The no. of digits in given number is : ${digits}")
}

/*
    Input : Enter the Number : 3456
    Output : The no. of digits in given number is : 4
*/
