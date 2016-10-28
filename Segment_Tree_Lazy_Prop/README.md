##Segment Tree with Lazy Propogation

Segment tree or segtree is a basically a binary tree used for storing the intervals or segments.


Each node in the segment tree represents an interval.


Consider an array A of size N and a corresponding segtree T:
*    The root of T will represent the whole array A[0:N-1].
*    Each leaf in the segtree T will represent a single element A[i] such that 0 <= i < N.
*    The internal nodes in the segtree tree T represent union of elementary intervals A[i:j] where 0 <= i < j < N.



Demonstrates usage of Segment Tree with Lazy Propogation for finding the sum of all the elements in an array from index left to right.

###Input : Array of with N numbers, and queries of altering the numbers by some delta amount or finding sum of Array[i] to Array[j]
###Output : Acc. to the query


###Reference : <a href="https://www.hackerearth.com/practice/notes/segment-tree-and-lazy-propagation/">Hacker Earth : Segment Tree</a> 
