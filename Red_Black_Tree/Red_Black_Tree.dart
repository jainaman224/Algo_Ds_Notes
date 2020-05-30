/**
 *   Red Black Tree
 * -------------------------------
 * RB Tree is a self balancing tree which is of O(logn) time complexity
 * for various operations. It has 4 balancing rules as follows:
 * 
 * 1. Nodes are of either red or black color.
 * 2. Root is always black.
 * 3. Red node should not have red children
 * 4. Every path from a node (including root) to any of its descendant 
 * NULL node has the same number of black nodes.
 * 
 */

// Importing required libraries
import 'dart:io';

// Defining colors as constants to increase readability and decrease confusion
const bool BLACK = false;
const bool RED = true;

// Class definition of a node
class Node{
    int value;
    bool color;
    Node parent, left, right;

    Node(int value){
        this.value = value;
        this.color = RED;
    }
}

// Class definition of a RB Tree
class RBTree{

    // Tree's root
    Node root;

    // Utility function to print a RB Tree
    void printRBTree(Node root){
        if(root != null){
            print(root.value);
            printRBTree(root.left);
            printRBTree(root.right);
        }
    }

    // Utility method to search in the tree
    Node searchRBTree(Node root, int target){
        if(root == null){
            return null;
        }
        if(root.value == target){
            return root;
        }
        else if(root.value < target){
            return searchRBTree(root.right, target);
        }
        else{
            return searchRBTree(root.left, target);
        }
    }

    // Utility method to perform BST insertion
    Node insertBST(Node root, Node node){
        if(root == null){
            root = node; 
        }
        else{
            if(root.value < node.value){
                root.right = insertBST(root.right, node);
                root.right.parent = root;
            }
            else if(root.value > node.value){
                root.left = insertBST(root.left, node);
                root.left.parent = root;
            }
        }
        return root;
    }

    // Utility method for left rotation
    Node rotateLeft(Node root, Node node){

        Node node_right = node.right;
        node.right = node_right.left;
        if(node.right != null){
            node.right.parent = node;
        }
        node_right.parent = node.parent;
        if(node.parent == null){
            root = node_right;
        }
        else if(node == node.parent.left){
            node.parent.left = node_right;
        }
        else{
            node.parent.right = node_right;
        }
        node_right.left = node;
        node.parent = node_right;
        return root;
        
    }

    // Utility method for right rotation
    Node rotateRight(Node root,Node node){
        
        Node node_left = node.left;
        node.left = node_left.right;

        if(node.left != null){
            node.left.parent = node;
        }

        node_left.parent = node.parent;

        if(node.parent == null){
            root = node_left;
        }
        else if(node == node.parent.left){
            node.parent.left = node_left;
        }
        else{
            node.parent.right = node_left;
        }

        node_left.right = node;
        node.parent = node_left;
        return root;
    }

    // Utility method to swap colors of two nodes
    void swapColor(Node node1, Node node2){
        if(node1 == null || node2 == null){
            return;
        }
        bool temp;
        temp = node1.color;
        node1.color = node2.color;
        node2.color = temp;
    }

    // Utility method to fix violation of rules of RB Tree
    Node fixViolation(Node root, Node node){
        Node parentnode = null;
        Node grandparent = null;
        while((node != root) && (node.color != BLACK) && (node.parent.color == RED)){
            parentnode = node.parent;
            grandparent = node.parent.parent;
            if(parentnode == grandparent.left){
                Node uncle = grandparent.right;
                if(uncle != null && uncle.color == RED){
                    grandparent.color = RED;
                    parentnode.color = BLACK;
                    uncle.color = BLACK;
                    node = grandparent;
                }
                else{
                    if(node == parentnode.right){
                        root = rotateLeft(root,parentnode);
                        node = parentnode;
                        parentnode = node.parent;
                        grandparent = parentnode.parent;
                    }
                    root = rotateRight(root, grandparent);
                    swapColor(parentnode,grandparent);
                    node = parentnode;
                }
            }
            else{
                Node uncle = grandparent.left;

                if((uncle != null) && (uncle.color == RED)){
                    grandparent.color = RED;
                    parentnode.color = BLACK;
                    uncle.color = BLACK;
                    node = grandparent;
                }
                else{
                    if(node == parentnode.left){
                        root = rotateRight(root,parentnode);
                        node = parentnode;
                        parentnode = node.parent;
                        grandparent = parentnode.parent;
                    }
                    root = rotateLeft(root,grandparent);
                    swapColor(parentnode,grandparent);
                    node = parentnode;
                }
            }
           
        }
        root.color = BLACK;
        return root;
    }

    // Method to insert into RB Tree
    Node insertRBT(Node root, int value){
        Node node = Node(value);
        root = insertBST(root, node);
        root = fixViolation(root, node);
        return root;
    }
  
}

// Driver method of the program
void main(){

    // Initialization of the tree
    RBTree tree = RBTree();
    int continued = 1;

    while(continued == 1){
        print("Enter 1 to insert, 2 to search and 3 to print the tree:");
        var input = stdin.readLineSync();
        int option = int.parse(input);
        switch(option){
            case 1:
                input = stdin.readLineSync();
                int value = int.parse(input);
                tree.root = tree.insertRBT(tree.root, value);
                break;
            case 2:
                input = stdin.readLineSync();
                int value = int.parse(input);
                Node node1 = tree.searchRBTree(tree.root, value);
                if(node1 == null){
                    print("Value not found");
                }
                else{
                    print("Value found!");
                }
                break;
            case 3:
                tree.printRBTree(tree.root);
                break;
            default:
                break;
        }
        print("Enter 1 to continue:");
        input = stdin.readLineSync();
        continued = int.parse(input);
    }   
}

/**
 *   Sample Input and Output
 * -----------------------------------
 * Enter 1 to insert, 2 to search and 3 to print the tree:
 * 1
 * 7
 * Enter 1 to continue:
 * 1
 * Enter 1 to insert, 2 to search and 3 to print the tree:
 * 1
 * 3
 * Enter 1 to continue:
 * 1
 * Enter 1 to insert, 2 to search and 3 to print the tree:
 * 1
 * 18
 * Enter 1 to continue:
 * 1
 * Enter 1 to insert, 2 to search and 3 to print the tree:
 * 1
 * 10
 * Enter 1 to continue:
 * 1
 * Enter 1 to insert, 2 to search and 3 to print the tree:
 * 1
 * 22
 * Enter 1 to continue:
 * 1
 * Enter 1 to insert, 2 to search and 3 to print the tree:
 * 1
 * 8
 * Enter 1 to continue:
 * 1
 * Enter 1 to insert, 2 to search and 3 to print the tree:
 * 1
 * 11
 * Enter 1 to continue:
 * 1
 * Enter 1 to insert, 2 to search and 3 to print the tree:
 * 1
 * 26
 * Enter 1 to continue:
 * 1
 * Enter 1 to insert, 2 to search and 3 to print the tree:
 * 3
 * 7
 * 3
 * 18
 * 10
 * 8
 * 11
 * 22
 * 26
 * Enter 1 to continue:
 * 1
 * Enter 1 to insert, 2 to search and 3 to print the tree:
 * 2
 * 18
 * Value found!!
 * Enter 1 to continue:
 * 1
 * Enter 1 to insert, 2 to search and 3 to print the tree:
 * 2
 * 112
 * Value not found!!
 * Enter 1 to continue:
 * 1
 * Enter 1 to insert, 2 to search and 3 to print the tree:
 * 1
 * 2
 * Enter 1 to continue:
 * 1
 * Enter 1 to insert, 2 to search and 3 to print the tree:
 * 1
 * 6
 * Enter 1 to continue:
 * 1
 * Enter 1 to insert, 2 to search and 3 to print the tree:
 * 1
 * 13
 * Enter 1 to continue:
 * 1
 * Enter 1 to insert, 2 to search and 3 to print the tree:
 * 3
 * 10
 * 7
 * 3
 * 2
 * 6
 * 8
 * 18
 * 11
 * 13
 * 22
 * 26
 * Enter 1 to continue:
 * 2
 */
