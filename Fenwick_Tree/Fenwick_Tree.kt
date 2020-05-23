/*Fenwick Tree is used when there is a problem of range sum query with update
i.e. RMQ. Suppose you have an array and you have been asked to find sum in
range. It can be done in linear time with static array method. If will be
difficult for one to do it in linear time when you have point updates. In this
update operation is incrementing an index by some value. Brute force approach
will take O(n^2) time but Fenwick Tree will take O(nlogn) time
*/

//Sum function
fun sum(ft:Array<Int>, _index:Int):Int{
    /*
    Argument
    ft     : Fenwick Tree
    index  : Index upto which you want to find prefix sum
    Initialize the result "s" then increment the value of
    index "index".

    Returns : sum of given arr[0..index]. This function assumes
    that the array is preprocessed and partial sums of
    array elements are stored in ft[].
    */

    // Initialize sum variable to 0
    var s:Int  = 0
    // Increment index
    var index = _index + 1

    while (index > 0){

        // Adding tree node to sum
        s += ft[index]
        // Update tree node
        index -= index and (-index)
    }
    // Return total sum
    return s
}


// Update function
fun update(ft:Array<Int>,size:Int,_index:Int,value:Int){
    /*
    Arguments
    ft    : Fenwick Tree
    index : Index of ft to be updated
    size  : Length of the original array
    val   : Add val to the index "index"
    Traverse all ancestors and add 'val'.
    Add 'val' to current node of Fenwick Tree.
    Update index to that of parent in update.
    */

    var index = _index + 1
    while (index <= size) {

        // Update tree node value
        ft[index] += value
        // Update node index
        index += index and (-index)
    }

}

// Construct function
fun construct(array:Array<Int>, size:Int):Array<Int>{
    /*
    Argument
    arr : The original array
    size : The length of the given array
    This function will construct the Fenwick Tree
    from the given array of length "size"

    Return : Fenwick Tree array ft[]
    */

    // Init ft array of length size+1 with zero value initially
    var ft = Array(size+1,{0})

    // Constructing Fenwick Tree by Update operation
    for (i in 0 until size){
        // Update operation
        update(ft,size,i,array[i])
    }
    // Return Fenwick Tree array
    return ft
}

fun main(){
    /*
        INPUT
        -------
        arr : [2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9]
        Print sum of freq[0...5]
        Update position 4 by adding 16
        Print sum of freq[2....7] after update
        Update position 5 by adding 10
        Print sum of freq[2....7] after update

        OUTPUT
        ------
        12
        33
        43
    */

    // Given array
    var list = arrayOf(2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9)

    // Build Fenwick Tree
    var ft = construct(list,list.size)

    // Print Sum of array from index = 0 to index = 5
    println(sum(ft,5))

    // Increment list[4] by 16
    update(ft,list.size,4,16)

    // Print sum from index = 2 to index = 7
    println(sum(ft,7) - sum(ft,2))

    // Increment list[5] by 10
    update(ft,list.size,5,10)

    // Print sum from index = 2 to index = 7
    println(sum(ft,7) - sum(ft,2))
}

