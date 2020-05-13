/**
 * ------------------------------------------------
 *    AVL Tree implementation in Dart
 * ------------------------------------------------
 * 
 * AVL Tree is a binary search tree that provides insertion, deletion
 * and search in O(logn) time in all cases. It is an improvement over BST as a BST can
 * take O(n) time when the tree takes a linear shape whereas AVL tree takes O(logn) time
 * in all cases as it balances the tree using various rotations.
 * 
 * AVL tree is preferred when insertions and deletions are less frequent and search is a
 * more frequent operation.
 * 
 * References - Geeksforgeeks
 * 
 */

// Importing required libraries
import 'dart:io';
import 'dart:math';

// Class definition for a tree node.
class Node{
    int value;
    Node left , right;
    int height;

    Node(value){
        this.value = value;
        this.left = null;
        this.right = null;
        this.height = 1;
    }
}

// Class defintion for an AVL tree.
class AVL_Tree{
    Node root;

    // Utility function to print the tree in preorder traversal.
    void print_AVL(Node root){
        if(root != null){
            print(root.value);
            print_AVL(root.left);
            print_AVL(root.right);
        }
    }

    // Utility function to find the height of the tree.
    int height(Node node){
        if(node == null){
            return 0;
        }
        return node.height;
    }

    // Utility function ro find the balance of the tree.
    int balance(Node node){
        if(node == null){
            return 0;
        }
        return height(node.left) - height(node.right);
    }

    //Utility function for right rotation 
    Node rightRotate(Node root){
        Node z = root , y = root.left , x = y.left;
        Node c2 = root.left.right;
        y.right = z;
        y.left = x;
        z.left = c2;
        y.height = 1 + max<int>(height(y.left) , height(y.right));
        x.height = 1 + max<int>(height(x.left) , height(x.right));
        z.height = 1 + max<int>(height(z.left) , height(z.right));
        return y;
    }

    // Utility function for left rotation
    Node leftRotate(Node root){
        Node z = root , y = root.right , x = y.right;
        Node c2 = y.left;
        y.left = z;
        y.right = x;
        z.right = c2;
        y.height = 1 + max<int>(height(y.left) , height(y.right));
        x.height = 1 + max<int>(height(x.left) , height(x.right));
        z.height = 1 + max<int>(height(z.left) , height(z.right));
        return y;
    }

    // Utility function for leftRight rotation
    Node leftRightRotate(Node root){
        Node z = root , y = root.left , x = y.right;
        Node c1 = z.right , c2 = y.left , c3 = x.left , c4 = x.right;
        x.right = z;
        x.left = y;
        y.left = c2;
        y.right = c3;
        z.left = c4;
        z.right = c1;
        y.height = 1 + max<int>(height(y.left) , height(y.right));
        x.height = 1 + max<int>(height(x.left) , height(x.right));
        z.height = 1 + max<int>(height(z.left) , height(z.right));
        return x;
    }

    // Utility function for rightLeft rotation
    Node rightLeftRotate(Node root){
        Node z = root , y = z.right , x = y.left;
        Node c1 = z.left , c2 = x.left , c3 = x.right , c4 = y.right;
        x.left = z;
        x.right = y;
        z.left = c1;
        z.right = c2;
        y.left = c3;
        y.right = c4;
        y.height = 1 + max<int>(height(y.left) , height(y.right));
        x.height = 1 + max<int>(height(x.left) , height(x.right));
        z.height = 1 + max<int>(height(z.left) , height(z.right));
        return x;
    }

    // Utility function to find the successor of a node.
    Node successor(Node root){
        Node temp = root;
        while(temp.left != null){
            temp = temp.left;
        }
        return temp;
    }

    // Function to delete a node in the tree.
    Node delete_AVL(Node root , int key){
        if(root == null){
            return root;
        }
        else if(key > root.value){
            root.right = delete_AVL(root.right , key);
        }
        else if(key < root.value){
            root.left = delete_AVL(root.left , key);
        }
        else{
            Node temp;
            if(root.left == null || root.right == null){
                if(root.left == null && root.right != null){
                    temp = root.right;
                }
                else if(root.right == null && root.left != null){
                    temp = root.left;
                }
            
                if(temp == null){
                    temp = root;
                    root = null;
                }
                else{
                    root = temp;
                }
            }
            else{
                Node temp1 = successor(root.right);
                root.value = temp1.value;
                root.right = delete_AVL(root.right , temp1.value);
            }
        }

        if(root == null){   
            return root;
        }
    
        root.height = 1 + max<int>(height(root.left) , height(root.right));
        int difference = balance(root);

        if(difference > 1 && balance(root.left)>=0){
            return rightRotate(root);
        }

        if(difference > 1 && balance(root.left)<0){
            return leftRightRotate(root);
        }

        if(difference < -1 && balance(root.right)<=0){
            return leftRotate(root);
        }

        if(difference < -1 && balance(root.left)>0){
            return rightLeftRotate(root);
        }

        return root;
    }

    // Function to insert a value as a node into a tree.
    Node insert_AVL(Node root , int key){
        if(root == null){
            return Node(key);
        }
        else if(key < root.value){
            root.left = insert_AVL(root.left, key);
        }
        else{
            root.right = insert_AVL(root.right, key);
        }

        root.height = 1 + max<int>(height(root.left), height(root.right));     
        int difference = balance(root);
        
        if(difference > 1 && key < root.left.value){
            return rightRotate(root);
        }

        if(difference > 1 && key > root.left.value){
            return leftRightRotate(root);
        }

        if(difference < -1 && key > root.right.value){
            return leftRotate(root);
        }

        if(difference < -1 && key < root.right.value){
            return rightLeftRotate(root);
        }
        
        return root;
    }

}

void main(){

    int continued = 1;
    AVL_Tree tree = AVL_Tree();
        
    while(continued == 1){
        print("Enter 1 to insert , 2 to delete and 3 to print the AVL tree:");
        var input = stdin.readLineSync();
        int operation = int.parse(input);

        if(operation == 1){
            input = stdin.readLineSync();
            int value = int.parse(input);
            tree.root = tree.insert_AVL(tree.root , value);
        }
        else if(operation == 3){
            tree.print_AVL(tree.root);
        }
        else{
            input = stdin.readLineSync();
            int value = int.parse(input);
            tree.root = tree.delete_AVL(tree.root , value);
        }

        print("Enter 1 to continue:");
        input = stdin.readLineSync();
        continued = int.parse(input);
    }

}

/**
 * ------------------------------------------------
 *    Sample Input and Output
 * ------------------------------------------------
 * 
 * Enter 1 to insert , 2 to delete and 3 to print the AVL tree:
 * 1
 * 10
 * Enter 1 to continue:
 * 1
 * Enter 1 to insert , 2 to delete and 3 to print the AVL tree:
 * 1
 * 20
 * Enter 1 to continue:
 * 1
 * Enter 1 to insert , 2 to delete and 3 to print the AVL tree:
 * 1
 * 30
 * Enter 1 to continue:
 * 1
 * Enter 1 to insert , 2 to delete and 3 to print the AVL tree:
 * 1
 * 40
 * Enter 1 to continue:
 * 1
 * Enter 1 to insert , 2 to delete and 3 to print the AVL tree:
 * 1
 * 50
 * Enter 1 to continue:
 * 1
 * Enter 1 to insert , 2 to delete and 3 to print the AVL tree:
 * 1
 * 25
 * Enter 1 to continue:
 * 1
 * Enter 1 to insert , 2 to delete and 3 to print the AVL tree:
 * 3
 * 30
 * 20
 * 10
 * 25
 * 40
 * 50
 * Enter 1 to continue:
 * 1
 * Enter 1 to insert , 2 to delete and 3 to print the AVL tree:
 * 2
 * 50
 * Enter 1 to continue:
 * 1
 * Enter 1 to insert , 2 to delete and 3 to print the AVL tree:
 * 3
 * 30
 * 20
 * 10
 * 25
 * 40
 * Enter 1 to continue:
 * 0
 * 
 */
