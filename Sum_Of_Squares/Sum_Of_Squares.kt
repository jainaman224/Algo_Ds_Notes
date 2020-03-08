import java.util.*

fun main(args: Array<String>) {
    val read = Scanner(System.`in`)
    print("Enter the Number : ")
    var num = read.nextInt()
    var ans = ((num) * (num + 1) * (2 * num + 1))/6
    println("The sum of square from 1 to N number is : ${ans}")
}

/*
    Input : Enter the Number : 223
    Output : The sum of square from 1 to N number is : 140
*/
