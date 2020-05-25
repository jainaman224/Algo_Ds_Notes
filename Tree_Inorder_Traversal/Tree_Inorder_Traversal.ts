export {}
// Node 
interface node
{
    key: number;
    parent?: node;
    left?: node;   
    right?: node;  
}


// Defining the nodes with their values and left right children
const node9: node = { key: 9, left: undefined, right: undefined };
const node8: node = { key: 8, left: undefined, right: undefined };
const node7: node = { key: 7, left: undefined, right: undefined };
const node6: node = { key: 6, left: undefined, right: undefined };
const node5: node = { key: 5, left: undefined, right: undefined };
const node4: node = { key: 4, left: node8, right: node9 };
const node3: node = { key: 3, left: node6, right: node7 };
const node2: node = { key: 2, left: node4, right: node5 };
const root:  node = { key: 1, parent: undefined, left: node2, right: node3 };

// Construct a tree by assigning parents
function constructTree(): node
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
  
    return root;
  }

function inOrderTraversal(node: node) : null
  {
      if (!node)
          return;
      inOrderTraversal(node.left); 
      console.log(node.key + " -> ");
      inOrderTraversal(node.right);
  }


constructTree();
console.log("The inorder traversal of the binary tree is :");
inOrderTraversal(root);

/*
Output
The inorder traversal of the binary tree is :
8 -> 4 -> 9 -> 2 -> 5 -> 1 -> 6 -> 3 -> 7
*/