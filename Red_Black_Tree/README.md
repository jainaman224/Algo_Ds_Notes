# Red–Black Tree

A **red–black tree** is a binary search tree with one extra bit of storage 
per node: itscolor, which can be either RED or BLACK.

The RED or BLACK color bits are used to ensure the tree remains approximately balanced 
during insertions and deletions.

The balancing of the tree is not perfect, but it is good 
enough to allow it to guarantee searching in `O(log n)` time,
where `n` is the total number of elements in the tree. 
The insertion and deletion operations, along with the tree 
rearrangement and recoloring, are also performed 
in `O(log n)` time.

An example of a red–black tree:

![red-black tree](https://upload.wikimedia.org/wikipedia/commons/6/66/Red-black_tree_example.svg)
[Courtesy: Wikipedia.org](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree)

## Properties

A red-black tree is a binary tree that satisfies the following properties:

1. Every node is either red or black.
2. The root is black.
3. Every leaf (NIL) is black.
4. If a node is red, then both its children are black.
5. For each node, all simple paths from the node to descendant leaves contain the same number of black nodes.

The uniform number of black nodes in all paths from root to the leaves 
is called the **black-height** of the red–black tree.

Implementations of the red-black tree algorithms will usually include the 
sentinel nodes (empty) as a convenient means of flagging that you have reached 
a leaf node. These are the NULL black nodes of property 3.

### Right Rotation and Left Rotation

A rotation is a local operation in a search tree that preserves in-order traversal key ordering.

#### Right Rotate <----> Left Rotate 
(Courtesy: Cormen)

                            Right Rotate  ----->

                         y(B)                    x(B)
                        /  \                   /    \
                      x(B)   C(R)            A(R)    y(B)
                      / \           <--->             /  \
                    A(R)  B(R)                   B(R)   C(R)
                        
                             <--------- Left Rotate

### Insertion into a Red Black Tree 

We start by inserting the new node, x, in the tree just as we would for any other binary tree, and the color of the new node is RED. Subsequetly a check for violation of red black properties is done and fixed.

## Balancing during insertion

#### If uncle is RED
![Red Black Tree Balancing](https://www.geeksforgeeks.org/wp-content/uploads/redBlackCase2.png)

#### If uncle is BLACK

- Left Left Case (`p` is left child of `g` and `x` is left child of `p`)
- Left Right Case (`p` is left child of `g` and `x` is right child of `p`)
- Right Right Case (`p` is right child of `g` and `x` is right child of `p`)
- Right Left Case (`p` is right child of `g` and `x` is left child of `p`)

##### Left Left Case 

![Red Black Tree Balancing](https://www.geeksforgeeks.org/wp-content/uploads/redBlackCase3a1.png)

##### Left Right Case 

![Red Black Tree Balancing](https://www.geeksforgeeks.org/wp-content/uploads/redBlackCase3b.png)

##### Right Right Case

![Red Black Tree Balancing](https://www.geeksforgeeks.org/wp-content/uploads/redBlackCase3c.png)

##### Right Left Case 

![Red Black Tree Balancing](https://www.geeksforgeeks.org/wp-content/uploads/redBlackCase3d.png)

[Courtesy: geeksforgeeks.org](https://www.geeksforgeeks.org/red-black-tree-set-2-insert/)

## See also

- [Wikipedia : Red Black Tree](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree)
- [Red Black Tree Insertion on GeeksForGeeks](https://www.geeksforgeeks.org/red-black-tree-set-2-insert/)
- [Red Black Tree Interactive Visualisations](https://www.cs.usfca.edu/~galles/visualization/RedBlack.html)
- [Red Black Trees](https://www.cs.auckland.ac.nz/software/AlgAnim/red_black.html)
