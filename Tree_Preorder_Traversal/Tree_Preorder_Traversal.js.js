
//Tree_Preorder_Traversal in javascript
class Node
{
    constructor(data)
    {
        this.data = data;
        this.left = null; //left child of the node
        this.right = null; //right child of the node
    }
}
class BinarySearchTree
{
    constructor()
    {
        this.root = null;
    }
//data inserting in tree
insert(data)
{
    let node = new Node(data);
    if(this.root == null)
    {
        this.root = node;
    }
    else
    {
      this.insertNode(this.root, node);
    }
}
insertNode(root, newNode)
{
    if(newNode.data < root.data)
    {
        if(root.left == null)
        {
            root.left = newNode;
        }
        else
        {
            this.insertNode(root.left, newNode);
        }
    }
    else if(newNode.data > root.data)
    {
        if(root.right == null)
        {
            root.right = newNode;
        }
        else
        {
            this.insertNode(root.right, newNode);
        }
    }
}
getRootNode()
{
    return this.root; 
}
//function of preorder traversal
preorder(root)
{
    if(root != null)
    {
        console.log(root.data); // first line - P L R
        this.preorder(root.left); // second line
        this.preorder(root.right); // third line
    }
}
}

var bst = new BinarySearchTree();
//tree data insertion statically
bst.insert(3);
bst.insert(5);
bst.insert(1);
bst.insert(6);
bst.insert(4);
var root = bst.getRootNode();
console.log('Preorder Traversal:');
bst.preorder(root);
console.log('\n'); 

/*
output:
Preorder Traversal:
3
1
5
4
6

*/
