// Function for Bubble Sort
fun bubbleSort(list: MutableList<Int>):List<Int> {
    /* flag keeps track if any swap happened or not,
     if swap not happened then array is sorted and it will break
      out of the loop and will save time from
      running for loop unnecessarily.*/
    var flag: Int = 0
    for (i in 0 until (list.size - 1)) {
        for (j in 0 until (list.size - i - 1)) {
            if (list[j] > list[j + 1]) {
                var tmp = list[j + 1]
                list[j + 1] = list[j]
                list[j] = tmp
                flag++
            }
        }
        if (flag == 0)
            break
    }
    return list
}

// Driver Function for Bubble Sort
fun main(args:Array<String>) {
    val numbers = mutableListOf(9, 5, 25, 9, 2, 1)
    println("Unsorted: $numbers")
    val sortedlist = bubbleSort(numbers)
    println("Sorted: $sortedlist")
}

// Input: Unsorted: [90, 5, 25, 19, 2, 1]
// Output: Sorted: [1, 2, 5, 19, 25, 90]
