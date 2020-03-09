import java.util.*;
import java.lang.*;
import java.io.*;

class Node
{
    int key;
    Node left, right;

    public Node(int item)
    {
        key = item;
        left = right = null;
    }
}

class BinaryTree
{
    Node root;

    BinaryTree()
    {
        root = null;
    }

    void printInorder(Node node)
    {
        if (node == null)
            return;

        printInorder(node.left);
        System.out.print(node.key + " ");
        printInorder(node.right);
    }

    void printInorder()
    {
        printInorder(root);
    }

    public static void main(String[] args)
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

        System.out.println("\nInorder traversal of binary tree is ");
        tree.printInorder();
    }
}

/*
Output:
Inorder traversal of binary tree is
8 4 9 2 5 1 6 3 7
*/
