fun<T: Comparable<T>> circleSort(array: Array<T>, lo: Int, hi: Int, nSwaps: Int): Int {
    if (lo == hi) return nSwaps
 
    fun swap(array: Array<T>, i: Int, j: Int) {
        val temp = array[i]
        array[i] = array[j]
        array[j] = temp
    }
 
    var high = hi
    var low  = lo
    val mid  = (hi - lo) / 2
    var swaps = nSwaps
   
    while (low < high) {
        if (array[low] > array[high]) {
            swap(array, low, high)
            swaps++
        }
        low++
        high--
    }
    if (low == high)
        if (array[low] > array[high + 1]) {
            swap(array, low, high + 1)
            swaps++
        }
    
    swaps = circleSort(array, lo, lo + mid, swaps)
    swaps = circleSort(array, lo + mid + 1, hi, swaps)
    return swaps
}
 
fun main(args: Array<String>) {
    // -- ExampleArray1 --
    val array = arrayOf(6, 7, 8, 9, 2, 5, 3, 4, 1) 
    println("Unsorted Array: ${array.asList()}")
    while (circleSort(array, 0, array.size - 1, 0) != 0) ; 
    println("Sorted Array : ${array.asList()}") //Sorted Array
    println()
    
    // -- ExampleArray2 --
    val array2 = arrayOf("the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog")  
    println("Unsorted Array : ${array2.asList()}")
    while (circleSort(array2, 0, array2.size - 1, 0) != 0) ;
    println("Sorted  Array : ${array2.asList()}")    //Sorted Array
}


//output
Unsorted Array: [6, 7, 8, 9, 2, 5, 3, 4, 1]
Sorted Array : [1, 2, 3, 4, 5, 6, 7, 8, 9]

Unsorted Array : [the, quick, brown, fox, jumps, over, the, lazy, dog]
Sorted  Array : [brown, dog, fox, jumps, lazy, over, quick, the, the]
