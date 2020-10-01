/* Vertical Order Traversal of Binary Tree is a traversal in which all nodes that fall in the same vertical line are visited together, starting from the leftmost vertical line and ending at the rightmost vertical line. The horizontal distance is measured with root serving as reference, then we measure the left and right deviations of the each node. */

import java.util.*;

// Node of Binary Tree storing data, horizontal distance from root, left and right child information
class Node 
{
    int data;
    int distance;
    Node left, right;
    Node(int val) 
    {
        data = val;
        left = null;
        right = null;
    }
}

class Tree_Verticalorder_Traversal
{
    // Function to print Binary Tree in Vertical Order
     public static void VerticalOrderTraversal(Node root) 
    {
        if (root == null)
            return;

        // initialising variables
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        root.distance = 0;
        // Tree Map keeps entries of Map sorted by key
        TreeMap<Integer, ArrayList<Integer> > mp = new TreeMap<>();
        // variable to store distance of nodes
        int distance;

        // Assigning horizontal distance to each node of Binary Tree
        // Storing all nodes of same horizontal distance in a map with key as distance
        while (!q.isEmpty()) 
        {
            // extract the node at the front of queue
            Node temp = q.peek();
            distance = temp.distance;

            // make key as distance and data as value for map
            ArrayList<Integer> list =  mp.get(distance); 
            if(list == null) 
            { 
                list = new ArrayList<>(); 
                list.add(temp.data); 
            } 
            else
                list.add(temp.data); 
           
            mp.put(distance, list);
            // remove the extract node from queue
            q.poll();
            // when left child exists, assign horizontal distance to it, and push it to the queue
            if (temp.left != null) 
            {
                temp.left.distance = distance - 1;
                q.add(temp.left);
            }
            // when right child exists, assign horizontal distance to it, and push it to the queue
            if (temp.right != null) 
            {
                temp.right.distance = distance + 1;
                q.add(temp.right);
            }
        }
        /* Map mp contains:
        [-2] -> 4
        [-1] -> 2, 8
        [0] -> 1, 5, 6
        [1] -> 3, 9
        [2] -> 7
        */

        System.out.println("Vertical Order Traversal of Tree: ");
        ArrayList<Integer> row = new ArrayList<>(); 
        // Iterate over the map keys i.e -2, -1, 0, 1, 2
        for (Map.Entry<Integer, ArrayList<Integer> > entry : mp.entrySet())
        {
            row = entry.getValue();
            for (int i = 0; i < row.size(); i++)
                System.out.print(row.get(i)+" ");
            System.out.println();
        }
    }

    // Driver Function
    public static void main(String args[]) 
    {
        /* Contructing Binary Tree as:
                1
             /     \
            2       3
          /   \   /   \
        4      5 6     7
             /   \
            /     \
           8        9
        */
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);
        root.left.right.left = new Node(8);
        root.left.right.right = new Node(9);

        // call to VerticalOrderTraversal function
        Tree_Verticalorder_Traversal obj = new Tree_Verticalorder_Traversal();
        obj.VerticalOrderTraversal(root);
    }
}

/*  Output:
    Vertical Order Traversal of Tree: 
    4 
    2 8 
    1 5 6 
    3 9 
    7 
*/
