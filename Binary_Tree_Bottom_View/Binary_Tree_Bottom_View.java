/*
    The Bottom View of a Binary Tree depicts the nodes that are visible 
    when the tree is viewed from below. At every horizontal distance 
    there would be exactly one node that will appear in bottom view.
    The horizontal distance is measured with root serving as reference,
    then we measure the left and right deviations of the each node.
*/

import java.util.*;

// Node of Binary Tree storing data, horizontal distance
// from root, left and right child information
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

class Binary_Tree_Bottom_View
{
    // Function to print Bottom View of Binary Tree
    public static void BottomView(Node root) 
    {
        if (root == null)
            return;

        // initialising variables
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        root.distance = 0;
        // Tree Map keeps entries of Map sorted by key
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        // variable to store distance of nodes
        int distance;

        // Assigning horizontal distance to each node of Binary Tree
        // Storing all nodes of same horizontal distance in a map 
        // with key as distance
        while (!q.isEmpty()) 
        {
            // extract the node at the front of queue
            Node temp = q.peek();
            distance = temp.distance;

            // make key as distance and data as value for map
            mp.put(distance, temp.data);
            // remove the extract node from queue
            q.poll();

            // when left child exists, assign horizontal distance to it
            // and push it to the queue
            if (temp.left != null) 
            {
                temp.left.distance = distance - 1;
                q.add(temp.left);
            }

            // when right child exists, assign horizontal distance to it
            // and push it to the queue
            if (temp.right != null) 
            {
                temp.right.distance = distance + 1;
                q.add(temp.right);
            }
        }
        /* 
            Map mp contains:
            [-2] -> 4
            [-1] -> 8
            [0] -> 6
            [1] -> 9
            [2] -> 7
        */

        System.out.println("Bottom View of Binary Tree: ");
        // Iterate over the map keys i.e -2, -1, 0, 1, 2
        for (Map.Entry<Integer, Integer> entry : mp.entrySet())
        {
            System.out.print(entry.getValue() + " ");
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

        // call to BottomView function
        Binary_Tree_Bottom_View obj = new Binary_Tree_Bottom_View();
        obj.BottomView(root);
    }
}

/*
    Input:
            1
         /     \
        2       3
      /   \   /   \
    4      5 6     7
         /   \
        /      \
       8        9

    Output:
    Bottom View of Binary Tree:
    4 8 6 9 7
*/
