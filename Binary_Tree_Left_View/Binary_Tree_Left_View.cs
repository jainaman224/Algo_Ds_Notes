using System; 

public class Node 
{ 
	public int data; 
	public Node left, right; 

	public Node(int item) 
	{ 
		data = item; 
		left = right = null; 
	} 
} 

/* Class to print the left view */
public class BinaryTree 
{ 
	public Node root; 
	public static int max_level = 0; 

	// recursive function to print left view 
	public virtual void leftViewUtil(Node node, int level) 
	{ 
		// Base Case 
		if (node == null) 
		{ 
			return; 
		} 

		// If this is the first node of its level 
		if (max_level < level) 
		{ 
			Console.Write(" " + node.data); 
			max_level = level; 
		} 

		// Recur for left and right subtrees 
		leftViewUtil(node.left, level + 1); 
		leftViewUtil(node.right, level + 1); 
	} 

	// A wrapper over leftViewUtil() 
	public virtual void leftView() 
	{ 
		leftViewUtil(root, 1); 
	} 

	/* testing for example nodes */
	public static void Main(string[] args) 
	{ 
		/* creating a binary tree and entering the nodes */
		BinaryTree tree = new BinaryTree(); 
		tree.root = new Node(12); 
		tree.root.left = new Node(10); 
		tree.root.right = new Node(30); 
		tree.root.right.left = new Node(25); 
		tree.root.right.right = new Node(40); 

		tree.leftView(); 
	} 
} 

