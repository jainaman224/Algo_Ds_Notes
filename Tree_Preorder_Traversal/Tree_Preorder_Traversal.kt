class Node<Element>(
    var key:Element,
    var left:Node<Element>? = null,
    var right:Node<Element>? = null  
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
    val zero = Node(0)
    val one = Node(1)
    val two = Node(2)
    val three = Node(3)
    val four = Node(4)
    val five = Node(5)
    
    zero.left = one
    zero.right = two
    one.left = three
    one.right = four
    two.left = five
    
    print("Pre Order traversal of tree is ")
    zero.preorderTraversal()
}

//Output: Pre Order traversal of tree is 0 1 3 4 2 5 
