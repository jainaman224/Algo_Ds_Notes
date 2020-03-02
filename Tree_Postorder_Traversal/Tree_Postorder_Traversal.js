/*
 * Program to traverse a tree in Post Order.
 */

// Creates a Tree Node with input value.
class Node {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

// Function for POST ORDER Tree Transversal.
function PostOrder(root) {
    if (root) {
        PostOrder(root.left);
        PostOrder(root.right);
        console.log(root.value);
    }
}

// Sample Input.
var root = new Node(1);
root.left = new Node(2);
root.right = new Node(3);
root.left.left = new Node(4);
root.left.right = new Node(5);
root.right.left = new Node(6);
root.right.right = new Node(7);

// Sample Output
console.log("Post Order traversal of tree is:-");
PostOrder(root);

/*
 * Expected Output:- 4 5 2 6 7 3 1
 */
