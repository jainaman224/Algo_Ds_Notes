/* QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array 
around the picked pivot.It's Best case complexity is n*log(n) & Worst case complexity is n^2. */

//partition array
fun quick_sort(A: Array<Int>, p: Int, r: Int) {
    if (p < r) {
        var q: Int = partition(A, p, r)
        quick_sort(A, p, q - 1)
        quick_sort(A, q + 1, r)

    }
}

//assign last value as pivot
fun partition(A: Array<Int>, p: Int, r: Int): Int {
    var x = A[r]
    var i = p - 1
    for (j in p until r) {
        if (A[j] <= x) {
            i++
            exchange(A, i, j)
        }
    }
    exchange(A, i + 1, r)
    return i + 1
}

//swap
fun exchange(A: Array<Int>, i: Int, j: Int) {
    var temp = A[i]
    A[i] = A[j]
    A[j] = temp
}

fun main(arg: Array<String>) {
    print("Enter no. of elements :")
    var n = readLine()!!.toInt()

    println("Enter elements : ")
    var A = Array(n, { 0 })
    for (i in 0 until n)
        A[i] = readLine()!!.toInt()

    quick_sort(A, 0, A.size - 1)

    println("Sorted array is : ")
    for (i in 0 until n)
        print("${A[i]}  ")
}

/*-------OUTPUT--------------
Enter no. of elements :6
Enter elements :
4
8
5
9
2
6
Sorted array is :
2  4  5  6  8  9
*/

