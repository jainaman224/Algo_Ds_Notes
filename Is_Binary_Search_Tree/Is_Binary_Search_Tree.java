    
    import java.util.Scanner;

    public class BinaryTree {
        class Node {
	    int data;
	    Node left;
	    Node right;
	}
    
	private Node root;
	private int size;
	public static Scanner scn = new Scanner(System.in);

	public BinaryTree() {
	    this.root = this.takeInput(null, false);
	}

	public Node takeInput(Node parent, boolean ilc) {

	    int cdata = scn.nextInt();
	    Node child = new Node();
	    child.data = cdata;
	    this.size++;

	    // left
	    boolean hlc = scn.nextBoolean();

	    if (hlc) {
		child.left = this.takeInput(child, true);
	    }

	    // right
	    boolean hrc = scn.nextBoolean();
  
            if (hrc) {
	        child.right = this.takeInput(child, false);
	    }

	    // return
	    return child;
	}

	public boolean isBST() {
	    return isBST(root);
	}

	private boolean isBST(Node node) {

	    if (node == null)
		return true;

	    boolean l = isBST(node.left); 
	    // l will store whether the left subtree is BST or not
	    boolean r = isBST(node.right); 
	    // r will store whether the right subtree is BST or not

	    //the below given conditions will return false if the current node doesnt satisfy the property of a BST
	    if(node.left != null && node.data < node.left.data)
	        return false;

	    if(node.right != null && node.data > node.right.data)
		return false;

	    //if the curr node satifies the BST property then we will return true if both l and r subtree are BST or not
	    return l && r;
	}

	public static void main(String[] args) {

	    BinaryTree bt = new BinaryTree();
	    System.out.println(bt.isBST());
	}
    }

   /*Sample Input :
     4 true 2 true 1 false false true 3 false false true 6 true 5 false false true 7 false false
     Sample Output : true
     Also The tree is :
	2-> 4 <-6
	1-> 2 <-3
	. -> 1 <- .
	. -> 3 <- .
	5-> 6 <-7
	. -> 5 <- .
	. -> 7 <- . */
