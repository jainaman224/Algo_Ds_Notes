/*
    The Left View of a Binary Tree depicts the nodes that are visible 
    when the tree is viewed from the left side of it. At every level 
    there would be exactly one node that will appear in left view which
    would be the first node of that level.
*/

import java.util.*;

// Node of Binary Tree storing data, level,
// left and right child information
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

class Binary_Tree_Left_View
{
    // Function to print Left View of Binary Tree
    public static void leftView(Node root) 
    {
        if (root == null)
            return;

        // initialising variables
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        root.level = 0;

        // Tree Map keeps entries of Map sorted by key
        TreeMap<Integer, Integer> mp = new TreeMap<>();

        // variable to store level of nodes
        int level;

        // Assigning level to each node of Binary Tree
        // Storing first node of same level in a map 
        // with key as level
        while (!q.isEmpty()) 
        {
            // extract the node at the front of queue
            Node temp = q.peek();
            level = temp.level;

            // make key as level and data as value for map
            if(!mp.containsKey(level))
                mp.put(level, temp.data);

            // remove the extract node from queue
            q.poll();

            // when left child exists, assign level to it
            // and push it to the queue
            if (temp.left != null) 
            {
                temp.left.level = level + 1;
                q.add(temp.left);
            }

            // when right child exists, assign level to it
            // and push it to the queue
            if (temp.right != null) 
            {
                temp.right.level = level + 1;
                q.add(temp.right);
            }
        }
        /* 
            Map mp contains:
            [0] -> 1
            [1] -> 2
            [2] -> 4
            [3] -> 8
        */

        System.out.println("Left View of Binary Tree: ");
        // Iterate over the map keys i.e 0, 1, 2, 3
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

        // call to leftView function
        Binary_Tree_Left_View obj = new Binary_Tree_Left_View();
        obj.leftView(root);
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
    Left View of Binary Tree:
    1 2 4 8
*/
