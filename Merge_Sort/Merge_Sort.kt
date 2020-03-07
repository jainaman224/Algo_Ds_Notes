import java.util.*

fun merge(arr: IntArray, left: Int, right: Int, mid: Int)
{
    //Initializing Array
    var arr1Size = mid - left + 1
    var arr2Size = right - mid
    var arr1 = IntArray(arr1Size)
    var arr2 = IntArray(arr2Size)

    //Copy Data of array into arr1 and arr2
    for (i in 0 until arr1Size)
    {
        arr1[i] = arr[left + i]
    }
    for (i in 0 until arr2Size)
    {
        arr2[i] = arr[mid + 1 + i]
    }
    var index1 = 0
    var index2 = 0
    var k: Int = left
    // Merge arr1 and arr2
    while (index1 < arr1Size && index2 < arr2Size)
    {
        if (arr1[index1] <= arr2[index2] )
        {
            arr[k] = arr1[index1]
            index1++
        }
        else
        {
            arr[k] = arr2[index2]
            index2++
        }
        k++
    }
    // Inserting remaining element
    while (index1 < arr1Size)
    {
        arr[k] = arr1[index1]
        index1++
        k++
    }
    while (index2 < arr2Size)
    {
        arr[k] = arr2[index2]
        index2++
        k++
    }
}

fun mergeSort(arr: IntArray, left: Int, right: Int)
{
    if (left < right)
    {
        var mid: Int = left + (right - left) / 2
        mergeSort(arr, left, mid)
        mergeSort(arr, mid + 1, right)
        merge(arr, left, right, mid)
    }
}

// Driver Function for Merge Sort
fun main()
{
    var read = Scanner(System.`in`)
    println("Enter the size of Array")
    var arrSize = read.nextLine().toInt()
    var arr = IntArray(arrSize)
    println("Enter the Elements")
    for (i in 0 until arrSize)
    {
        arr[i] = read.nextLine().toInt()
    }
    mergeSort(arr, 0, arrSize-1)
    println("Sorted Array is:")
    for (i in 0 until arrSize)
    {
        print("${arr[i]} ")
    }
}

/*
OUTPUT:-
Enter the size of Array
 4
Enter the Elements
 2
 5
 3
 1
Sorted Array is:
 1 2 3 5
*/

