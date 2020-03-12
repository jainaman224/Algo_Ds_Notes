import java.util.*

fun main() {
    // Taking Inputs
    var read = Scanner(System.`in`)
    println("Enter the size of Array:")
    val arrSize = read.nextLine().toInt()
    var arr = IntArray(arrSize)
    println("Enter the elements")
    for(i in 0 until arrSize)
        arr[i] =  read.nextLine().toInt()
    var list = IntArray(arrSize)
    // Initializing List array
    for(i in 0 until arrSize)
        list[i] =  1
    // Finding Longest Increasing Subsequence
    var i = 1
    var j:Int
    while (i < arrSize) {
        j = 0
        while (j < i) {
            if (arr[i] > arr[j] && list[i] < list[j] + 1) {
                list[i] = list[j] + 1
            }
            j++
        }
        i++
    }
    var max = 0
    i = 0
    while (i < arrSize) {
        if (max < list[i]) {
            max = list[i]
        }
        i++
    }
    println("Size of the longest increasing subsequence: $max")
}

/*
Enter the size of Array:
 5
Enter the elements
 5
 4
 3
 2
 5
Size of the longest increasing subsequence: 2
*/

