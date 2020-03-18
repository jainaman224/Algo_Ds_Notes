import java.util.Scanner;

public class BinaryTree {
	
    class Node {
	int data;
	Node left;
	Node right;
	    
	public Node(int x) 
	{
	    this.data = x;
	}
     }
    
    public Node root;
    
    public static Scanner scn = new Scanner(System.in);
   
    public static boolean isBST(Node node) {

 	if (node == null)
	    return true;

	boolean l = isBST(node.left); // l will store whether the left subtree is BST or not
	boolean r = isBST(node.right); // r will store whether the right subtree is BST or not

	//the below given conditions will return false if the current node doesnt satisfy the property of a BST
	if(node.left != null && node.data < node.left.data)
	    return false;

	if(node.right != null && node.data > node.right.data)
	    return false;

	//if the curr node satifies the BST property then we will return true if both l and r subtree are BST or not
	return l && r;
    }

    public static void main(String[] args) {

	Node root = new Node(5); 
    	root.left = new Node(2); 
    	root.right = new Node(15); 
    	root.left.left = new Node(1); 
    	root.left.right = new Node(4); 
	System.out.println(isBST(root));
    }
}

  /*Sample Input :- 	
	2-> 5 <-15
	1-> 2 <-4
    Output :- true
  */
