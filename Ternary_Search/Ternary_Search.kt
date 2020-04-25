    import java.util.*
    import kotlin.collections.ArrayList

    //Ternary Search begins
    public fun ternarySearch(l:Int, r:Int, key:Int, ar:ArrayList<Int>): Int {
        if(r>=1){
            var mid1 = l + (r - l) / 3
            var mid2 = r - (r - l) / 3

    //Searching for the key element
        if (ar[mid1] == key) {
            return mid1
        }
        
        if (ar[mid2] == key) {
            return mid2
        }
        
        if (key < ar[mid1]) {
            return ternarySearch(l, mid1 - 1, key, ar)
        }
        
        else if (key > ar[mid2]) {
            return ternarySearch(mid2 + 1, r, key, ar)
        }
        
        else {
            return ternarySearch(mid1 + 1, mid2 - 1, key, ar)
        }
    }
    return -1;
}

    //Main function
    fun main() {
        var l:Int = 0
        var r:Int
        var p:Int
        var key:Int
        var scan1: Scanner = Scanner(System.`in`)
    
    //var ar = arrayOf<Int>(1,2,3,4,5,6,7,8,9,10)
    var ar = ArrayList<Int>()

    //Taking input from user
    println("Enter the number of elements: ")
    var n:Int = scan1.nextInt()
    var temp:Int
        for (i in 1..n) {
            temp = scan1.nextInt()
            ar.add(temp)
         }

    //Sorting the array
    println("Sorting the array in ascending order...")
    ar.sort()
    r = ar.count()
    println("Enter the key element to search for:")
    key = scan1.nextInt()
    p = ternarySearch(l, r, key, ar)
    //Printing the key element with its position
    print("Index of $key is $p \n")
    
    
    /*Sample Input and Output
    Enter the number of elements :
    6
    5
    4
    3
    2
    1
    Sorting the array in ascending order...
    Enter the key element to search for:
    5
    Index of 5 is 4
    */
