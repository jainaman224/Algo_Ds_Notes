/*
    The Right View of a Binary Tree depicts the nodes that are visible 
    when the tree is viewed from the right side of it. At every level 
    there would be exactly one node that will appear in right view which
    would be the last node of that level.
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

class Binary_Tree_Right_View
{
    // Function to print Right View of Binary Tree
    public static void rightView(Node root) 
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
            [1] -> 3
            [2] -> 7
            [3] -> 9
        */

        System.out.println("Right View of Binary Tree: ");
        // Iterate over the map keys i.e 0, 1, 2, 3
        for (Map.Entry<Integer, Integer> entry : mp.entrySet())
        {
            System.out.print(entry.getValue() + " ");
        }
    }

    // Driver Function
    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        HashMap<Integer, Node> m = new HashMap<Integer, Node>();

        // Input number of edges
        int n = sc.nextInt();
        Node root = null;

        /* 
            The input format is that we get node1 which is the parent,
            node2 which is the child, and then direction 'L' or 'R' which
            tells us whether it is a left or right child of node1. Example:
            Input:
            3
            1 2 L
            1 3 R
            2 4 L
            This means there are 3 edges
            2 is the left child of 1,
            3 is the right child of 1,
            4 is the left child of 2.
        */
        for (int i = 0; i < n; i++)
        {
            int node1 = sc.nextInt();
            int node2 = sc.nextInt();
            char direction = sc.next().charAt(0);
            Node parent = m.get(node1);
            if (parent == null)
            {
                parent = new Node(node1);
                m.put(node1, parent);
                if(root == null)
                    root = parent;
            }
            Node child = new Node(node2);
            if (direction == 'L')
                parent.left = child;
            else
                parent.right = child;
            m.put(node2, child);
        }

        // call to leftView function
        Binary_Tree_Right_View obj = new Binary_Tree_Right_View();
        obj.rightView(root);
    }
}

/*
            1
         /     \
        2       3
      /   \   /   \
    4      5 6     7
          /   \
         /     \
        8       9

    Input:
    8
    1 2 L 
    1 3 R
    2 4 L 
    2 5 R
    3 6 L
    3 7 R
    5 8 L
    6 9 R

    Output:
    Right View of Binary Tree:
    1 3 7 9
*/
