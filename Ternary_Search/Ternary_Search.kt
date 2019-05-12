import java.util.*

//Function for Ternary Search
fun ternarySearch(array: IntArray, num: Int, left: Int, right: Int):Int {
    if (right >= 1) {

        // Calculating Mid values 1 and 2
        var mid1 = (left + (right - 1)) / 3
        var mid2 = (right - (right - 1)) / 3

        // If number equal to Mid values
        if (array[mid1] == num) {
            return mid1
        }
        if (array[mid2] == num) {
            return mid2
        }
        if (num < array[mid1]) {
            return ternarySearch(array, num, left, mid1 -1)
        }
        else if (num > array[mid2]) {
            return ternarySearch(array, num, mid2 + 1, right)
        }
        else {
            return ternarySearch(array, num, mid1 + 1, mid2 - 1)
        }
    }
    return -1
}

fun main() {
    val scanner = Scanner(System.`in`)
    print("Enter the Size of Array : ")
    val size = scanner.nextInt()
    val array = IntArray(size)
    println("Enter entries in Array")
    for(i in 0 until size) {
        array[i] = scanner.nextInt()
    }
    print("Number to be searched in array : ")
    val num = scanner.nextInt()
    var resultAt = ternarySearch(array, num, 0, array.size)
    if(resultAt == -1) {
        println("$num Not Found")
    }
    else {
        println("$num Found at position ${resultAt + 1}")
    }
}

/*
 Input :- Enter the Size of Array : 9
          Enter entries in Array
          1 2 3 4 5 6 7 8 9
          Number to be searched in array : 4
 Output :- 4 Found at position 4
*/
