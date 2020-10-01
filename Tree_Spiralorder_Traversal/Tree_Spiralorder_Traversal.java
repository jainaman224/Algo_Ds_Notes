/* Spiral Order Traversal of a tree is level order traversal where levels are explored in zig-zag manner i.e. all nodes present at level 1 should be printed first from left to right, followed by nodes of level 2 right to left, followed by nodes of level 3 from left to right and so on.*/

import java.util.*;

// Node of Binary Tree storing data, level, left and right child information
class Node 
{
    int data;
    int level;
    Node left, right;
    Node(int val) 
    {
        data = val;
        left = null;
        right = null;
    }
}

class Tree_Spiralorder_Traversal
{
    // Function to print Binary Tree in Spiral Order
    public static void SpiralOrderTraversal(Node root) 
    {
	if (root == null)
	    return;

	// initialising variables
	Queue<Node> q = new LinkedList<>();
	q.add(root);
	root.level = 0;
	// Tree Map keeps entries of Map sorted by key
	TreeMap<Integer, ArrayList<Integer> > mp = new TreeMap<>();

	// Assigning level to each node of Binary Tree
	// Storing all nodes of same level in a map with key as level
	while (!q.isEmpty()) 
	{
	    // extract the node at the front of queue
	    Node temp = q.peek();

	    // make key as level and data as value for map
	    ArrayList<Integer> list =  mp.get(temp.level); 
	    if(list == null) 
	    { 
	        list = new ArrayList<>(); 
	        list.add(temp.data); 
	    } 
	    else
	        list.add(temp.data); 

	    mp.put(temp.level, list);
	    // remove the extract node from queue
	    q.poll();
	    // when left child exists, assign level to it, and push it to the queue
	    if (temp.left != null) 
	    {
	        temp.left.level = temp.level + 1;
		q.add(temp.left);
	    }
	    // when right child exists, assign level to it, and push it to the queue
	    if (temp.right != null) 
	    {
		temp.right.level = temp.level + 1;
		q.add(temp.right);
	    }
	}   
	/* Map mp contains:
	[0] -> 1
	[1] -> 2, 3
	[2] -> 4, 5, 6, 7
	[3] -> 8, 9
	*/

	System.out.println("Spiral Order Traversal of Tree: ");
	ArrayList<Integer> row = new ArrayList<>(); 
	int level = 0;
	// Iterate over the map keys i.e 0, 1, 2, 3
	for (Map.Entry<Integer, ArrayList<Integer> > entry : mp.entrySet())
	{
	    row = entry.getValue();
	    // when level is even, print elements of ArrayList from left to right
	    if(level%2 == 0)
	    {
		for (int i = 0; i < row.size(); i++)
		    System.out.print(row.get(i)+" ");
		System.out.println();
	    }
	    else
	    {
	    // when level is odd, print elements of ArrayList from right to left
	        for (int i = row.size()-1; i >= 0; i--)
		    System.out.print(row.get(i)+" ");
	        System.out.println();  
	    }
	    // increment level value
	    level++;
	 }
    }

    // Driver Function
    public static void main(String args[]) 
    {
	// Creating and Inserting nodes in Binary tree
	Node root = new Node(1);
	root.left = new Node(2);
	root.right = new Node(3);
	root.left.left = new Node(4);
	root.left.right = new Node(5);
	root.right.left = new Node(6);
	root.right.right = new Node(7);
	root.left.right.left = new Node(8);
	root.left.right.right = new Node(9);

	// call to SpiralOrderTraversal function
	Tree_Spiralorder_Traversal obj = new Tree_Spiralorder_Traversal();
	obj.SpiralOrderTraversal(root);
    }
}

/* Input Graph:
                1
             /     \
            2       3
          /   \   /   \
        4      5 6     7
             /   \
            /     \
           8        9
       
Output:
Spiral Order Traversal of Tree: 
1 
3 2 
4 5 6 7 
9 8 
*/
