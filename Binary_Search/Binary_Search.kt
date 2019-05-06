//Function For Binary Search
fun binarySearch(list: List<Int>, left: Int, right: Int, num: Int):Int {
    if (list.size >= 1) {
        var mid = (left + (right -1)) / 2
        if (list[mid] == num) {
            return mid
        }
        if (list[mid] > num) {
            return binarySearch(list, 1, mid - 1, num)
        }
        if (list[mid] < num) {
            return binarySearch(list, mid +1, right, num)
        }
    }
 return -1
}

//Driver Function for Binary Search
fun main() {
    var list = mutableListOf(4, 6, 18, 29, 67, 89)
    //let we want to find 67
    var num = 67
    var limit = list.size - 1
    var search = binarySearch(list, 0, limit, num)
    if (search == -1) {
        println("$num Not Found In The List")
    }
    else {
        println("$num is at position $search")
    }
}

// Output:- 67 is at position 4
