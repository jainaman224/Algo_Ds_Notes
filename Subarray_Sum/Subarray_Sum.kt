import java.util.*

fun main(args: Array<String>) {
    val read = Scanner(System.`in`)
    print("Enter the size of array : ")
    val n = read.nextInt()
    val arr = Array(n){0}
    print("Enter the elements of array : ")
    for(i in 0 until n)
    {
        var x = read.nextInt()
        arr[i] = x
    }
    var res = 0
    for(i in 0 until n)
    {
        res += (arr[i] * (n - i) * (i + 1))
    }
    println("The sum of all subarrays is : $res")
}

/*
    Input :
    Enter the size of array : 5
    Enter the elements of array : [1, 2, 3, 4, 5]
    Output :
        The sum of all subarrays is : 50
*/
