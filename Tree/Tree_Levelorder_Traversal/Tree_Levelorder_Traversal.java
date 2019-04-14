import java.util.*;
import java.lang.*;
import java.io.*;

class Node
{
    int data;
    Node left, right;
    public Node(int item)
    {
        data = item;
        left = right = null;
    }
}

class BinaryTree
{
    Node root;

    public BinaryTree()
    {
        root = null;
    }

    void printLevelOrder()
    {
        int h = height(root);
        int i;
        for (i = 1; i <= h; i++)
            printGivenLevel(root, i);
    }

    int height(Node root)
    {
        if (root == null)
           return 0;
        else
        {
            /* compute  height of each subtree */
            int lheight = height(root.left);
            int rheight = height(root.right);

            /* use the larger one */
            if (lheight > rheight)
                return(lheight + 1);
            else return(rheight + 1);
        }
    }

    void printGivenLevel (Node root ,int level)
    {
        if (root == null)
            return;
        if (level == 1)
            System.out.print(root.data + " ");
        else if (level > 1)
        {
            printGivenLevel(root.left, level-1);
            printGivenLevel(root.right, level-1);
        }
    }

    public static void main(String args[])
    {
       BinaryTree tree = new BinaryTree();
       tree.root = new Node(1);
       tree.root.left = new Node(2);
       tree.root.right = new Node(3);
       tree.root.left.left = new Node(4);
       tree.root.left.right = new Node(5);
       tree.root.right.left = new Node(6);
       tree.root.right.right = new Node(7);
       tree.root.left.left.left = new Node(8);
       tree.root.left.left.right = new Node(9);

       System.out.println("Level order traversal of binary tree is ");
       tree.printLevelOrder();
    }
}

/*
Output:
Level order traversal of binary tree is
1 2 3 4 5 6 7 8 9
*/
