import java.util.*

fun main()
{
    var read = Scanner(System.`in`)
    println("Enter the size of Array")
    var arrSize = read.nextLine().toInt()
    var arr = FloatArray(arrSize)
    println("Enter the Elements")
    for (i in 0 until arrSize)
    {
        arr[i] = read.nextLine().toFloat()
    }

    // Logic For Bucket Sort
    var bucket = Array<ArrayList<Float> >(arrSize) { i -> ArrayList() }
    for (i in 0 until arrSize)
    {
        var index = arrSize*arr[i].toInt()
        bucket[index].add(arr[i])
    }

    for (i in 0 until arrSize)
    {
        bucket[i].sort()
    }
    var index = 0
    for (i in 0 until arrSize)
    {
        for (j in 0 until bucket[i].size)
        {
            arr[index++] = bucket[i][j]
        }
    }
    println("Sorted Array is: ")
    for (i in 0 until arrSize)
    {
        print("${arr[i]} ")
    }
}
/*
OUTPUT:-
 Enter the Elements
 0.3
 0.4
 0.6
 Sorted Array is: 
 0.3 0.4 0.6
*/

