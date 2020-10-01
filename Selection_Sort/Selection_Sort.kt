//Function for Selection Sort
fun Selection_Sort(list: MutableList<Int>):List<Int> {
    for(i in 0 until (list.size) ) {
        var min_index: Int = i
        for(j in (i+1) until (list.size)) {
            if(list[j]<list[min_index]) {
                min_index = j
            }
        }
        var temp: Int = list[min_index]
        list[min_index] = list[i]
        list[i] = temp
    }
    return list
}

//Driver function for selection sort
fun main(args: Array<String>) {
    val list = mutableListOf(4, 67, 89, 2, 45, 102)
    println("Unsorted List: $list")
    val sortedList = Selection_Sort(list)
    println("Sorted List: $sortedList")
}

//Input: Unsorted: [4, 67, 89, 2, 45, 102]
//Output: Sorted: [2, 4, 25, 67, 89, 102]