# AVL Tree

An AVL tree is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. AVL trees, like binary search trees, can be traversed using an inorder traversal, yielding their items in ascending order in **O(log n)** time

## Animation 

Animation showing the insertion of several elements into an AVL 
tree. It includes left, right, left-right and right-left rotations.


[Courtesy: Wikipedia.org](https://en.wikipedia.org/wiki/AVL_tree)
![AVL Tree](https://upload.wikimedia.org/wikipedia/commons/f/fd/AVL_Tree_Example.gif)


## Rebalancing in AVL Tree
When a node is added to an AVL Tree is may cause the tree to become unbalanced. Hence after every insertion or deletion - the AVL Tree needs to be checked and rebalanced accordingly.

Height for a node in AVL Tree is calculated as =
```max height of either left or right subtree +1 for root```

Balance factor for a node in AVL Tree =
```height (left subtee ) - height (right subtree)```

For each node if balance is -1, 0 or 1 no rotation is required and it is an AVL tree.

## Left Rotation in AVL Tree

When the balance of a node is greater than 1 -> it means Left subtree is bigger than right subtree

* Case 1 : Left Right Case

                 Left Right Case -> rotate 68,70 to the left
                         88               88
                        /  \             / \
                      68   89          70   89
                      / \        ->   / \
                     65  70         68   85
                        / \        / \
                      67  85     65   67



* Case 2 : Left Left Case

                 Left Left Case -> rotate 70,88 to the right
                        88                   70
                       / \                  / \
                     70   89              68   88
                    /  \                / \    / \
                   68  85             65  67  85 89
                  /  \
                 65  67

## Right Rotation in AVL Tree

When the balance of a node is less than -1 -> it means Right subtree is bigger than left subtree

* Case 1 : Right Left Case

                     Right Left Case -> rotate 45, 43 to the right
                         40              40
                        / \             / \
                      20   45          20  43
                          / \    ->       / \
                        43  63          41   45
                        / \                 / \
                      41   44             44   63


* Case 2 : Right Right Case

                 Right Right Case -> rotate 40,45 to the left
                       40                43
                      / \              /   \
                    20   43          40     45
                        / \     ->  / \     / \
                      41   45      20 41  44  63
                          / \
                        44   63


## Deletion in AVL Tree

Deletion in AVL tree is similar to deletion in a binary tree with the additional factor of re-balancing the tree after the deletion of the node.

There are 3 cases for deletion -

* Case 1 : Node to be deleted is a leaf node
    * Can be deleted right away  
                    Delete 7 (and rebalance)
                       15                     15
                      /  \                   /  \
                    6     50               5     50
                   / \    /  \     ->     / \    / \
                  4   7  23   71         4   6  23 71
                   \        
                    5     

* Case 2 : Node to be deleted has only left or right sub tree
    * If sub tree is x-sub and the node to be deleted is x
    * Replace data of x with data of x-sub
    * Delete x-sub (now a leaf node)

                    Delete 71 (and rebalance)
                       15                     15
                      /  \                   /  \
                    5     71               5     23
                   / \    /       ->      / \     
                  4   6  23              4   6  

* Case 3 : Node to be deleted has both left and right sub trees
    * Use Predecessoror / Successor to replace data and sub tree
    * Successor is smallest node in the right subtree
    * Predecessor is largest node in the left subtree
    * Find Successor of x - say z-scr which will have no left sub tree
    * Replace data of x with with data of z-scr
    * Delete z-scr (If z-scr has a child then can use case 2 to delete z-scr)

                    Delete 50 (and rebalance)
                       15                     15
                      /  \                   /  \
                    5     50               5     71
                   / \    /  \     ->     / \    / 
                  4   6  23   71         4   6  23 
                           
 
## See also
[AVL tree on Wikipedia](https://en.wikipedia.org/wiki/AVL_tree)
