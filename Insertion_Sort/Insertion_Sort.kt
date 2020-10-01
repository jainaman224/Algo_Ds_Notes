//Function for sorting an list using Insertion Sort
fun Insertion_sort(list: MutableList<Int>): List<Int> {
    for(i in 0 until list.size) {
        var key = list[i]
        var j = i - 1
        /*Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position*/
        while(j > 0 && list[j] > key) {
            list[j+1] = list[j]
            j = j - 1
        }
        list[j+1] = key
    }
    return list
}

//Driver function for Insertion sort
fun main(args: Array<String>) {
    val list = mutableListOf(4, 67, 89, 2, 45, 102)
    println("Unsorted List: $list")
    val sortedlist = Insertion_sort(list)
    println("Sorted List: $sortedlist")
}

//Input: Unsorted: [4, 67, 89, 2, 45, 102]
//Output: Sorted: [2, 4, 25, 67, 89, 102]