import java.util.Scanner

// Function For Binary Search
fun binarySearch(array: IntArray, left: Int, right: Int, num: Int):Int {
    if (array.size >= 1) {
        var mid = (left + (right - 1)) / 2
        if (array[mid] == num) {
            return mid
        }
        if (array[mid] > num) {
            return binarySearch(array, 1, mid - 1, num)
        }
        if (array[mid] < num) {
            return binarySearch(array, mid + 1, array.size, num)
        }
    }
    return -1
}

// Driver Function for Binary Search
fun main() {
    val scanner = Scanner(System.`in`)
    print("Enter size of Array : ")
    val size = scanner.nextInt()
    val array = IntArray(size)
    print("Enter Numbers in Array : ")
    for (i in 0 until size)
        array[i] = scanner.nextInt()
    print("Enter an Number : ")
    var num = scanner.nextInt()
    var limit = size - 1
    var search = binarySearch(array, 0, limit, num)
    if (search == -1) {
        print("$num Not Found In The List")
    }
    else {
        print("$num is at position $search")
    }
}

// Input:- Enter size of Array : 6
//         Enter Numbers in Array : 4, 6, 18, 29, 67, 89
//         Enter an Number : 67
// Output:- 67 is at position 4
