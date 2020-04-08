import 'dart:io';

// Class to define the node of a binary tree.
class Node {

    int value;
    Node left;
    Node right;
    
    Node(int value) {

        this.value = value;
        this.left = null;
        this.right = null;

    }

}

// Class to define a binary tree.
class Tree {

    // The tree's root.
    Node root;

    // Constructor
    Tree(Node root) {
        this.root = root;
    }

    // Insert method to build the tree using recursion.
    Node insert(Node root, int val) {

        if (root != null){

            // Inserting in the left side if value is less than root.
            if (val < root.value) {
                root.left = insert(root.left, val);
            }
            else {
                // Inserting in the right side if value is greater than root.
                if (val > root.value) {
                    root.right = insert(root.right, val);
                }
                // Informing user that the value is already present.
                else{
                    print("Value is already present in the tree.");
                }
            }
        }
        else{
            // Insertion 
            root = Node(val);
        }

        return root;

    }

    // Utility method used to print the preorder traversal using recursion.
    void preorder_utility(Node node) {

        if (node != null) {
            print(node.value);
            
            // Recursion
            preorder_utility(node.left);
            preorder_utility(node.right);
        }

    }

    // Method to print the preorder traversal of the binary tree.
    void tree_preorder_traversal(){

        print("The preorder traversal of the tree in the given input is follows:");
        preorder_utility(this.root);

    }

}

// Driver method of the program
void main(){

    // Reading user input
    print("Enter root of the tree:");
    var input = stdin.readLineSync();
    int root_val = int.parse(input);

    // Root node
    Node root_node = Node(root_val);

    // Binary Tree
    Tree tree = Tree(root_node);
    
    String choice = "y";

    while (choice == "y") {
        
        print("Enter number to insert:");
        var input3 = stdin.readLineSync();
        int insert_val = int.parse(input3);
        tree.insert(root_node, insert_val);

        print("Do you want to insert another number into the tree? (y/n)");
        var input2 = stdin.readLineSync();
        choice = input2;

    }
    
    /* Sample Input tree
             8
           /   \
          3    12
         / \   / \
        2   6  9  15
           / \
          5   7
    */

    // Calling method to print preorder traversal of the tree.
    tree.tree_preorder_traversal();

    /* Sample Output
      The preorder traversal of the tree in the given input is follows:
      8
      3
      2
      6
      5
      7
      12
      9
      15
    */

}

