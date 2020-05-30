/*   Implementation of the preorder traversal of a binary tree in TypeScript language   */

// Declaring the node class
class node {
    right: any;
    value: any;
    left: any;
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

// Recursive Function for Preorder Tree Transversal.
function PreOrder(root) 
{ 
    if (root) {
        console.log(root.value);
        PreOrder(root.left);
        PreOrder(root.right);
    }
} 

// Sample Input
var root = new node(1);
root.left = new node(2);
root.right = new node(3);
root.left.right = new node(4);
root.right.left = new node(8);
root.right.right = new node(7);
root.left.right.left = new node(5);
root.left.right.left.right = new node(6);

// Sample Output
console.log("Preorder traversal of tree formed is:-");
PreOrder(root);


/*  OUTPUT:

Preorder traversal of tree formed is:-
1
2
4
5
6
3
8
7

*/

