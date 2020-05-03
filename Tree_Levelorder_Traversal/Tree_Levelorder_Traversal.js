/*Description - Level order traveral of a tree is a traversal in which all the nodes which are at same
level are explored and then we move to another level. It is implemented using a queue. The root node
is pushed into queue intially and loops run till queue is not empty. The node at front is poped out 
and if child of that node exist then those are pushed into queue.
Implementing Level Order Traversal in graph is also called Breath First Search.
*/

// Creates a Tree Node with input value
class Node {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

//Level Order Traversal 
var traversal = function (root) {
    if (root === null) return root;
    if (root.left === null && root.right === null) {
        console.log(root.value);
        return root;
    }
    const queue = [];
    queue.push(root);
    while (queue.length > 0) {
        const node = queue.splice(0, 1)[0];
        console.log(node.value);
        if (node.left) queue.push(node.left);
        if (node.right) queue.push(node.right);
    }
    return root;
};

// Sample Input
var root = new Node(1);
root.left = new Node(2);
root.right = new Node(3);
root.left.left = new Node(4);
root.left.right = new Node(5);
root.right.left = new Node(6);
root.right.right = new Node(7);

// Sample Output
console.log("Level Order traversal of tree is:-");
traversal(root);

/*
* Output
*
* Level Order traversal of tree is
1
2
3
4
5
6
7
*/
