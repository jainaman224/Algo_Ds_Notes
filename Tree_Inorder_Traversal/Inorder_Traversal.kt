//Code for printing inorder traversal in kotlin

class Node
{
    //Structure of Binary tree node
    int num;
    Node left, right; 
    public node(int num)
    {
        key = item;
        left = right = null;
    }
}

class BinaryTree
{
    Node root;
    BinaryTree()
    {
        root = null;
    }
    //function to print inorder traversal
    fun printInorder(Node: node):void		
    {
        if (node == null)
        return;
        printInorder(node.left);
        //printing val of node
        println(node.num); 
        printInorder(node.right);
    }
    
    fun printInorder():void
    {
        printInorder(root);
    }
}

 //Main function
fun main()  
{
    BinaryTree tree = new BinaryTree();
    var read = Scanner(System.`in`)
    println("Enter the size of Array:")
    val arrSize = read.nextLine().toInt()
    var arr = IntArray(arrSize)
    println("Enter data of  binary tree")
    
   for(i in 0 until arrSize)
   {
       arr[i] = read.nextLine().toInt()
       tree.root = new Node(arr[i]);
   }
    
   println("Inorder traversal of binary tree is");
   tree.printInorder();//function call
}

/*
Input: 10 8 3 30 5 19 4 5 1
Output:5 3 1 2 8 10 19 30 4
*/
