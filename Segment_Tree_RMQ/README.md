# Segment Tree

Segment tree can be used to do preprocessing and query in moderate time. With segment tree, preprocessing time is O(n) and time to for range minimum query is O(Logn). The extra space required is O(n) to store the segment tree.

**Representation of Segment trees**

* Leaf Nodes are the elements of the input array.
* Each internal node represents minimum of all leaves under it.

An array representation of tree is used to represent Segment Trees. For each node at index i, the left child is at index 2*i+1, right child at 2*i+2 and the parent is at [(i-1)/2].

## Construction of Segment Tree from given array

We start with a segment arr[0 . . . n-1]. and every time we divide the current segment into two halves(if it has not yet become a segment of length 1), and then call the same procedure on both halves, and for each such segment, we store the minimum value in a segment tree node.
All levels of the constructed segment tree will be completely filled except the last level. Also, the tree will be a Full Binary Tree because we always divide segments in two halves at every level. Since the constructed tree is always full binary tree with n leaves, there will be n-1 internal nodes. So total number of nodes will be 2*n – 1.

Height of the segment tree will be ```[log2 n]```. Since the tree is represented using array and relation between parent and child indexes must be maintained, size of memory allocated for segment tree will be ```2*2[log2 n]-1```.

 ![Segment Tree](https://media.geeksforgeeks.org/wp-content/cdn-uploads/RangeMinimumQuery.png)

## Query for minimum value of given range 

Once the tree is constructed, how to do range minimum query using the constructed segment tree. Following is algorithm to get the minimum.

    qs --> query start index, qe --> query end index
    int RMQ(node, qs, qe) 
    {
        if range of node is within qs and qe
            return value in node
        else if range of node is completely outside qs and qe
            return INFINITE
        else
            return min( RMQ(node's left child, qs, qe), RMQ(node's right child, qs, qe) )
    }

## Time Complexity

Time Complexity for tree construction is O(n). There are total 2n-1 nodes, and value of every node is calculated only once in tree construction.

Time complexity to query is O(Logn). To query a range minimum, we process at most two nodes at every level and number of levels is **O(Log n)**.

## Implementation
- [C++ Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Segment_Tree_RMQ/Segement_Tree_RMQ.cpp) 

- [Python Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Segment_Tree_RMQ/Segement_Tree_RMQ.py)

- [Java Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Segment_Tree_RMQ/Segement_Tree_RMQ.java)
 
## See also
[Segment Tree on GeeksforGeeks](https://www.geeksforgeeks.org/segment-tree-set-1-range-minimum-query/)
