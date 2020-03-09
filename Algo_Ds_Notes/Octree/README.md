# Octree Data Structure

Octree is a **tree data structure** where each internal node has 8 children. An octree is generally used to represent relation between objects in a 3-dimensional space. It is used in **3D computer graphics**. Octrees are also used for **nearest neighbor search** which can be done easily in **logarithmic time**.

Like a binary tree divides a **1-dimensional space** into **two segments**, an octree subdivides the **3D space into 8 octants** where each octant is represented by a node.

An octree save a large amount of space when storing points in a 3D space, especially if the space is sparsely populated. **If there are k points in a 3D cube of dimension N, then space used by the tree is O(klog2N).**

![Octree](https://geidav.files.wordpress.com/2014/07/octree.png?w=820)

## Algorithm
Three types of nodes are used in octree:

- **Point node:** Used to represent of a point. Is always a leaf node.
- **Empty node:** Used as a leaf node to represent that no point exists in the region it represent.
- **Region node:** This is always an internal node. It is used to represent a 3D region or a cuboid.

A region node always have 4 children nodes that can either be a point node or empty node.

The image below shows how an octree represents points in a space.

![Octree](https://iq.opengenus.org/content/images/2019/03/octree.png)

## Insertion
This is a recursive function used to store a point in the octree.
```sh
1. Start with root node as current node.
2. If the given point is not in cuboid represented by current node, stop insertion
    with error.
3. Determine the appropriate child node to store the point.
4. If the child node is empty node, replace it with a point node representing the
    point. Stop insertion.
5. If the child node is a point node, replace it with a region node. Call insert for
    the point that just got replaced. Set current node as the newly formed region
    node.
6. If selected child node is a region node, set the child node as current node.
    Goto step 2.
```

## Search
 This is a boolean function used to determine weather a point exists in 3D space or not.
```sh
1. Start with root node as current node.
2. If the given point is not in boundary represented by current node, stop search
    with error.
3. Determine the appropriate child node to store the point.
4. If the child node is empty node, return FALSE.
5. If the child node is a point node and it matches the given point return
    TRUE, otherwise return FALSE.
6. If the child node is a region node, set current node as the child region node.
    Goto step 2.
```

## Complexity
**Time Complexity**<br>
Insert: **O(log2N)**<br>
Search: **O(log2N)**

**Space Complexity: O(k log2N)**

Where k is count of points in the space and space is of dimension N x M x O, N >= M, O.

## Applications
- Used extensively in 3D computer graphics, especially game design.
- Used for triangle search. Paper.
- Used to find closest object in 3D space efficiently.