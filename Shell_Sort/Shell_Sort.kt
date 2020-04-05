val gaps = listOf(701, 301, 132, 57, 23, 10, 4, 1)  // Marcin Ciura's gap sequence
 
 // ShellSort function----
fun shellSort(a: IntArray) {
    for (gap in gaps) {
        for (i in gap until a.size) {
            val temp = a[i]
            var j = i
            while (j >= gap && a[j - gap] > temp) {
                a[j] = a[j - gap]
                j -= gap
            }
            a[j] = temp
        }
    }
}
 
fun main(args: Array<String>) {
    val aa = arrayOf(
       
        // ----Example 1----
        intArrayOf(100, 2, 56, 200, -52, 3, 99, 33, 177, -199),
       // -----Example 2-----
        intArrayOf(4, 65, 2, -31, 0, 99, 2, 83, 782, 1)
    )
    for (a in aa) {
        shellSort(a)
        println(a.joinToString(", "))
    }
}




//Output

/*-199, -52, 2, 3, 33, 56, 99, 100, 177, 200
-31, 0, 1, 2, 2, 4, 65, 83, 99, 782   */