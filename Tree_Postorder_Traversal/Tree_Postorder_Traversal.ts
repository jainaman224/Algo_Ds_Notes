//Tree Postorder Traversal in TypeScript

export {}

// Tree Nodes 
interface treeNodes
{
    val: number;
    parent?: treeNodes;  
    left?: treeNodes;   
    right?: treeNodes;  
}

// Defining the nodes with their values and left right children. If a value is not given it is undefined.
const node11: treeNodes = { val: 11 };
const node10: treeNodes = { val: 10 };
const node9: treeNodes = { val: 9 };
const node8: treeNodes = { val: 8 };
const node7: treeNodes = { val: 7 };
const node6: treeNodes = { val: 6, left: node10, right: node11};
const node5: treeNodes = { val: 5 };
const node4: treeNodes = { val: 4, left: node8, right: node9 };
const node3: treeNodes = { val: 3, left: node6, right: node7 };
const node2: treeNodes = { val: 2, left: node4, right: node5 };
const root:  treeNodes = { val: 1, left: node2, right: node3 };

// Construct a tree by assigning parent
function constructBinaryTree(): treeNodes
{
    root.parent = undefined;
    node2.parent = root;
    node3.parent = root;
    node4.parent = node2;
    node5.parent = node2;
    node6.parent = node3;
    node7.parent = node3;
    node8.parent = node4;
    node9.parent = node4;
    node10.parent = node6;
    node11.parent = node6;

    return root;
}

// Recursive Function to call itself on left child, then on right child and then print value of current node 
function postOrderTraversal(currentNode: treeNodes) 
{
    if (!currentNode)
        return;
    postOrderTraversal(currentNode.left); 
    postOrderTraversal(currentNode.right);
    console.log(currentNode.val + " -> ");
}

constructBinaryTree();
console.log("The postorder traversal of the binary tree is :");
postOrderTraversal(root);

/*
Output:
The postorder traversal of the binary tree is :
8 -> 
9 -> 
4 -> 
5 -> 
2 ->
10 ->
11 -> 
6 -> 
7 -> 
3 -> 
1 ->
*/
