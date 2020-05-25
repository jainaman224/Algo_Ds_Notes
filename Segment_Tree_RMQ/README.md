# Segment Tree

Segment Tree is a basically a binary tree used for storing the intervals or segments. Each node in the Segment Tree represents an interval. 

Segment Tree is used in cases where there are multiple range queries on array and modifications of elements of the same array. For example, finding the sum of all the elements in an array from indices L to R, or finding the minimum (famously known as __Range Minumum Query__ problem) of all the elements in an array from indices L to R.

## Explanation

Consider an array __A__ of size __N__ and a corresponding Segment Tree __T__:

1. The root of __T__ will represent the whole array __A[0 : N-1]__.
2. Each leaf in the Segment Tree __T__ will represent a single element __A[i]__ such that __0 <= i < N__.
3. The internal nodes in the Segment Tree __T__ represents the union of elementary intervals __A[i : j]__ where __0<=i<j<N__.

* The root of the Segment Tree represents the whole array __A[0 : N-1]__. 
* Then it is broken down into two half intervals or segments and the two children of the root in turn represent the __A[0 : (N - 1)/2]__ and __A[(N-1)/2 +1 : (N-1)]__. 
* So in each step, the segment is divided into half and the two children represent those two halves. So the height of the segment tree will be __log<sub>2</sub>N__. 
* There are __N__ leaves representing the  elements of the array. The number of internal nodes is __N - 1__. So, a total number of nodes are __2 * N - 1__.

The Segment Tree of array __A__ of size __7__ will look like this:

![Pic01](https://he-s3.s3.amazonaws.com/media/uploads/a0c7f90.jpg)

![Pic02](https://he-s3.s3.amazonaws.com/media/uploads/aad673e.jpg)

## Algorithm

#### Query for minimum value of given range

Once the tree is constructed, how to do range minimum query using the constructed segment tree. Following is the algorithm to get the minimum.

```
// qs --> query start index, qe --> query end index
int RMQ(node, qs, qe) 
{
    if range of node is within qs and qe
        return value in node
    else if range of node is completely outside qs and qe
        return ZERO
    else
        return min( RMQ(node's left child, qs, qe), RMQ(node's right child, qs, qe) )
}
```

## Pseudocode

After we've built a tree, we want to be able to search the tree for its values. (Which, in this case, is the minimum value between indices L and R.) 

Similar to the technique we used before, we recursively search the tree, starting from the root, and if a node is within the range [L, R], then we check it's value as a valid minimum of the range. 

```
function RecursivelySearchForMin(L, R, nodeIndex, nodeStartIndex, nodeEndIndex)
{
    /*  
        If this node's range is anywhere outside of [L, R]
        then  don't use it's value. Just return some 
        really big number (which wouldn't be taken as the minimum).
    */
    if(nodeEndIndex < L || R < nodeStartIndex)
    { 
        return reallyBigNumber;
    }
  
    /* 
        If this node is completely within [L, R], 
        then return it as the min value.
    */
    if(L <= nodeStartIndex && nodeEndIndex <= R)
    {
        return stArray[nodeIndex];
    }
    
    /* 
        Otherwise this node is partially within [L, R].
        (Recursively) check this node's children and return the min of those two.
    */
    middleIndex = nodeStartIndex + ((nodeEndIndex - nodeStartIndex) / 2);
  
    leftChildNodeIndex = 2 * nodeIndex;
    rightChildNodeIndex = 2 * nodeIndex + 1;
  
    leftChildMin = RecursivelySearchForMin(L, R, leftChildNodeIndex, nodeStartIndex, middleIndex);
    rightChildMin = RecursivelySearchForMin(L, R, rightChildNodeIndex, middleIndex + 1, nodeEndIndex); 
  
    minOfThisNode = min(leftChildMin, rightChildMin);
  
    return minOfThisNode;
}
  
// Find the minimum value between indices L and R.
function FindMin(L, R)
{
    // Recursively search the tree, starting from the root (node 0).
    min = RecursivelySearchForMin(L, R, 0, 0, origArrayLength - 1);
    return min;
}
```
## Example

Given an array A[1 … n] of n objects taken from a well-ordered set(such as numbers), returns the position of the minimal element in the specified sub-array A[l … r], (r<=n).

When A = [2,4,3,1,6,7,8,9,1,7], then the answer to the range minimum query for the sub-array A[2 … 7] = [3,1,6,7,8,9] is 3, as A[3] = 1.

![Pic03](https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcRviJId20R7OU-1qdCFVqWY6jkM9lmqw2LPj_PGRqaDbW8ThaDf&usqp=CAU)

## Time Complexity

Time Complexity for tree construction is __O(n)__. There are total __2N - 1__ nodes, and value of every node is calculated only once in tree construction.

Time complexity to query is __O(Log N)__. To query a range minimum, at worst, we'll have to go down the height of the tree twice, once for the left subtree, and one for the right subtree. We process at most two nodes at every level and number of levels is **O(Log N)**.

## Implementation

-[C Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Segment_Tree_RMQ/Segement_Tree_RMQ.c)

-[C++ Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Segment_Tree_RMQ/Segement_Tree_RMQ.cpp)

-[Python Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Segment_Tree_RMQ/Segement_Tree_RMQ.py)

-[Dart Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Segment_Tree_RMQ/Segment_Tree_RMQ.dart)

-[Java Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Segment_Tree_RMQ/Segment_Tree_RMQ.java)

## References

#### Images source:
1. [https://www.hackerearth.com/practice/notes/segment-tree-and-lazy-propagation/](https://www.hackerearth.com/practice/notes/segment-tree-and-lazy-propagation/)
2. [https://www.topcoder.com/community/competitive-programming/tutorials/range-minimum-query-and-lowest-common-ancestor/](https://www.topcoder.com/community/competitive-programming/tutorials/range-minimum-query-and-lowest-common-ancestor/)

#### Websites:
1. [https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/tutorial/](https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/tutorial/)
2. [https://www.geeksforgeeks.org/segment-tree-set-1-range-minimum-query/](https://www.geeksforgeeks.org/segment-tree-set-1-range-minimum-query/)
3. [https://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/](https://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/)
4. [https://www.srcmake.com/home/segment-tree](https://www.srcmake.com/home/segment-tree)
