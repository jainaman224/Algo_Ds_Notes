// Creates a Tree Node with input value
class Node {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

// Function for In Order Tree Transversal
function InOrder(root) {
    if (root) {
        InOrder(root.left);
        console.log(root.value);
        InOrder(root.right);
    }
}

// Sample Input
var root = new Node(1);
root.left = new Node(2);
root.right = new Node(3);
root.left.left = new Node(4);
root.left.right = new Node(5);
root.right.left = new Node(6);
root.right.right = new Node(7);

// Sample Output
console.log("In Order traversal of tree is:-");
InOrder(root);

/* Output
In Order traversal of tree is:- 4 2 5 1 6 3 7
 */
