
//AVL Tree implementaion in Java


public class AVL_Tree
{
       //Declaring Node class
	private class Node 
	{
		int data;
		Node left;
		Node right;
		int height;
		public Node(int data) 
		{
			this.data = data;
			this.height = 1;
		}
	}
	
	private Node root;
	
	public void insert(int num)
	{
		this.root = insert(this.root, num);
	}

	
	//Display node Function
	public void inOrder(Node node)
	{ 
                 if (node != null) 
                 { 
        	       inOrder(node.left);
                      System.out.print(node.data + " "); 
                      inOrder(node.right); 
                 } 
         } 
	
	//preorder traversal
	public void preOrder(Node node) 
	{ 
                if (node != null) 
                { 
        	     System.out.print(node.data + " ");
        	     preOrder(node.left); 
                     preOrder(node.right);
                 } 
         } 
	
	//post order traversal
	public void postOrder(Node node) 
	{ 
                if (node != null) 
               { 
        	    postOrder(node.left); 
                    postOrder(node.right); 
                   System.out.print(node.data + " ");
                } 
        } 
	
	
  
	private Node insert(Node node1, int num) 
	{

		if (node1 == null) 
		{
			Node node2 = new Node(num);
			return node2;
		}

		if (num > node1.data)
		{
			node1.right = insert(node1.right, num);
		} else if (num < node1.data) 
		{
			node1.left = insert(node1.left, num);
		}

		node1.height = Math.max(height(node1.left), height(node1.right)) + 1;

		int balancefac = balancefac(node1);

		// L-L Case
		if (balancefac > 1 && num < node1.left.data)
		{
			return rightRotate(node1);
		}

		// R-R Case
		if (balancefac < -1 && num > node1.right.data)
		{
			return leftRotate(node1);
		}

		// L-R Case
		if (balancefac > 1 && num > node1.left.data) 
		{
			node1.left = leftRotate(node1.left);
			return rightRotate(node1);
		}

		// R-L Case
		if (balancefac < -1 && num < node1.right.data) 
		{
			node1.right = rightRotate(node1.right);
			return leftRotate(node1);
		}
		return node1;

	}
	

        //Finding height of the node
	private int height(Node num) 
	{
		if (num == null) 
		{
			return 0;
		}

		return num.height;
	}
       //Balance Factor
	private int balancefac(Node num)
	{
		if (num == null) 
		{
			return 0;
		}

		return height(num.left) - height(num.right);
	}
       //performing right rotation
	private Node rightRotate(Node node3)
	{

		Node node4 = node3.left;
		Node node = node4.right;

		node4.right = node3;
		node3.left = node;

		node3.height = Math.max(height(node3.left), height(node3.right)) + 1;
		node4.height = Math.max(height(node4.left), height(node4.right)) + 1;

		return node4;
	}

	//performing left rotation
	private Node leftRotate(Node node3) 
	{

		Node node4 = node3.right;
		Node node = node4.left;
		
		node4.left = node3;
		node3.right = node;

		node3.height = Math.max(height(node3.left), height(node3.right)) + 1;
		node4.height = Math.max(height(node4.left), height(node4.right)) + 1;

		return node4;
	}


	public static void main(String[] args) 
	{

		AVL_Tree tree = new AVL_Tree();
		tree.insert(10);
		tree.insert(20);
		tree.insert(30);
		tree.insert(40);
		tree.insert(50);
		tree.insert(25);

		System.out.println("Preorder display: ");
		tree.preOrder(tree.root);
		System.out.println("\n\nInorder display: ");
		tree.inOrder(tree.root);
		System.out.println("\n\nPostorder display: ");
		tree.postOrder(tree.root);
		

	}
}

/* Input: 
 * 10 20 30 40 50 25
 */



/* 
 * Output: 
 *
 * Preorder display: 
   30 20 10 25 40 50 

   Inorder display: 
   10 20 25 30 40 50 

   Postorder display: 
   10 25 20 50 40 30 
*/
