import java.util.*
class Node<Int>(
    var key:Int,
    var left:Node<Int>? = null,
    var right:Node<Int>? = null  
)
{
    fun preorderTraversal()
    {
      print("$key ")
      left?.preorderTraversal()
      right?.preorderTraversal()
    }
}

fun main() {
    var read = Scanner(System.`in`)
    println("Enter the size of Array:")
    val arrSize = read.nextLine().toInt()
    var arr = IntArray(arrSize)
    val nodes = mutableListOf<Node<Int>>()
    println("Enter the array respresentaion of binary tree")
    for(i in 0 until arrSize)
    {
        arr[i] = read.nextLine().toInt()
        nodes.add(Node(arr[i]))
    }
    for(i in 0..arrSize-2)
    {
        if((i*2)+1<arrSize && arr[(i*2)+1]!=-1)
        nodes[i].left = nodes[(i*2)+1]
        if((i*2)+2<arrSize && arr[(i*2)+2]!=-1)
        nodes[i].right = nodes[(i*2)+2]
    }
    print("Pre Order traversal of tree is ")
    nodes[0].preorderTraversal()
}
/*
*Enter the size of Array:
*7
*Enter the array respresentaion of binary tree
*1
*2
*3
*4
*5
*-1
*7
*Pre Order traversal of tree is 1 2 4 5 3 7 
*/
