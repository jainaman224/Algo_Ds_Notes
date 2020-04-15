/**
    Tree Inorder Traversal In C#
*/

using System;

// Node Class To Declare Nodes Of The Tree
class Node
{
    public int data;
    public Node left;
    public Node right;
    
    public void display()
    {
        Console.Write(" [");
        Console.Write(data);
        Console.Write("] ");
    }
}

// Tree Class To Declare Binary Search Tree
class Tree
{
    public Node root;

    // Constructor
    public Tree()
    {
        root = null;
    }

    public Node ReturnRoot()
    {
        return root;
    }

    // Function To Insert Node Into BST
    public void Insert(int id)
    {
        Node newNode = new Node();
        newNode.data = id;
        
        if (root == null)
            root = newNode;
        else
        {
            Node current = root;
            Node parent;

            while (true)
            {
                parent = current;
                if (id < current.data)
                {
                    current = current.left;
                    if (current == null)
                    {
                        parent.left = newNode;
                        return;
                    }
                }

                else
                {
                    current = current.right;
                    if (current == null)
                    {
                        parent.right = newNode;
                        return;
                    }
                }
            }
        }
    }

    // Inorder Traversal Function
    public void Inorder(Node Root)
    {
        if (Root != null)
        {
            Inorder(Root.left);
            Console.Write(Root.data + " ");
            Inorder(Root.right);
        }
    }
}

class InorderTreeProgram
{
    public static void Main(string[] args)
    {
        // Declaring the Object Of Tree Class
        Tree BST = new Tree();
        Console.WriteLine("1. Insert Node");
        Console.WriteLine("2. Display InOrder Traversal");
        Console.WriteLine("3. Exit");

        while(true)
        {
            Console.WriteLine("\nEnter your choice: ");
            String choice = Console.ReadLine();
            int Choice = int.Parse(choice);

            switch(Choice)
            {
                case 1:
                    {
                        Console.WriteLine("Enter the value to insert node: ");
                        String val = Console.ReadLine();
                        int data = int.Parse(val);
                        BST.Insert(data);
                        break;
                    }

                case 2:
                    {
                        Console.WriteLine("\nTree Inorder Traversal: ");
                        BST.Inorder(BST.ReturnRoot());
                        Console.WriteLine(" ");
                        break;
                    }

                case 3:
                    {
                        Console.WriteLine("Exit");
                        System.Environment.Exit(0);
                        break;
                    }
            }
        }
    }
}

/**

1. Insert Node
2. Display InOrder Traversal
3. Exit

Enter your choice: 1
Enter the value to insert node: 30

Enter your choice: 1
Enter the value to insert node: 35

Enter your choice: 1
Enter the value to insert node: 57

Enter your choice: 1
Enter the value to insert node: 15

Enter your choice: 1
Enter the value to insert node: 63

Enter your choice: 1
Enter the value to insert node: 49

Enter your choice: 1
Enter the value to insert node: 77

Enter your choice: 1
Enter the value to insert node: 98

Enter your choice: 2

Tree Inorder Traversal: 
15 30 35 49 57 63 77 98  

Enter your choice: 3
Exit

*/
