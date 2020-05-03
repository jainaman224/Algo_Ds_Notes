// Code for printing Level Order of Tree in Kotlin

class Node
{
    //Structure of Binary tree node
    int num;
    Node left, right;
    public Node(int num)
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

    //function to print level order traversal
    fun printLevelOrder():void
    {
        int h = height(root);
        int i;
	// To Print nodes at each level
        for (i = 1; i <= h; i++)
	{
	    printGivenLevel(root, i);
	}
        
    }

    //Function to calculate height of Tree
    fun height(Node: root):void
    {
        if (root == null)
	{
	     return 0;
	}
        else
        {
            // compute  height of each subtree 
            int lheight = height(root.left);
            int rheight = height(root.right);
	    // use the larger one 
            if (lheight > rheight)
	    {
		return(lheight + 1);
	    }
            else 
	    {
	        return(rheight + 1);
	    }
        }
    }

    fun printGivenLevel(Node:root ,int: level):void
    {
        if (root == null)
	{
	    return;
	}
	//Print data
        if (level == 1)
	{
           println(root.data);
	}
        else if (level > 1)
        {
            printGivenLevel(root.left, level-1);
            printGivenLevel(root.right, level-1);
        }
    }

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

       println("Level order traversal of binary tree is ");
       tree.printLevelOrder();
    }
}

/*
Input:
1 2 3 4 5 6 7 8 9
Output:
Level order traversal of binary tree is
1 2 3 4 5 6 7 8 9
*/
