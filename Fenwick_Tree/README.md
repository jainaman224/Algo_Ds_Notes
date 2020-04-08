# Fenwick Tree
A Fenwick Tree (a.k.a. Binary Indexed Tree, or BIT) is a fairly common data structure. that can efficiently update elements and calculate prefix sums in a table of numbers.

## Explanation

Binary Indexed Tree is an array in which each node stores sum of some elements of a given array for which the BI Tree is made.
Problems that can be solved efficiently with Fenwick tree :-

 1. "What is the sum of the numbers indexed from [1,x]?"
 2. "Increase the number indexed by x by v."

A simple solution is to run a loop from 0 to i-1 and calculate the sum of the elements. To update a value, simply do arr[i] = x. The first operation takes O(n) time and the second operation takes O(1) time. But, A BIT can perform both of these operations in O(log N) time, and takes O(N) memory.

Wondering how?

BI Tree for an array arr[] has following operations :
1. update() : Updates BI Tree for oeration arr[index] += val
2. getSum() : Returns sum of arr[0..index]

The idea is based on the fact that all positive integers can be represented as the sum of powers of 2. For example 19 can be represented as 16 + 2 + 1. Every node of the BITree stores the sum of n elements where n is a power of 2. For example, in the first diagram above (the diagram for getSum()), the sum of the first 12 elements can be obtained by the sum of the last 4 elements (from 9 to 12) plus the sum of 8 elements (from 1 to 8). The number of set bits in the binary representation of a number n is O(Logn). Therefore, we traverse at-most O(Logn) nodes in both getSum() and update() operations. The time complexity of the construction is O(nLogn) as it calls update() for all n elements.

## Pseudocode

We first intialize all values in BITree[] as 0.
Then we call update() operation for all indexes to insert values according to given array.

 1. Update()
 // Note that the update(x, val) operation will not change arr[].  It only makes changes to BITree[]
1) Initialize the current index as x+1.
2) Do the following while the current index is smaller than or equal to n.
...a) Add the val to BITree[index]
...b) Go to parent of BITree[index].  The parent can be obtained by incrementing
     the last set bit of the current index, i.e., index = index + (index & (-index))

     ![alt text](https://media.geeksforgeeks.org/wp-content/cdn-uploads/BITUpdate12.png)

The update function needs to make sure that all the BITree nodes which contain arr[i] within their ranges being updated. We loop over such nodes in the BITree by repeatedly adding the decimal number corresponding to the last set bit of the current index.

 2. getSum()
 // Returns the sum of the sub-array arr[0,...,x] using BITree[0..n], which is constructed from arr[0..n-1]
1) Initialize the output sum as 0, the current index as x+1.
2) Do following while the current index is greater than 0.
...a) Add BITree[index] to sum
...b) Go to the parent of BITree[index].  The parent can be obtained by removing
     the last set bit from the current index, i.e., index = index - (index & (-index))
3) Return sum.

![alt text](https://media.geeksforgeeks.org/wp-content/cdn-uploads/BITSum.png)

The diagram above provides an example of how getSum() is working. Here are some important observations.

BITree[0] is a dummy node.

BITree[y] is the parent of BITree[x], if and only if y can be obtained by removing the last set bit from the binary representation of x, that is y = x – (x & (-x)).

The child node BITree[x] of the node BITree[y] stores the sum of the elements between y(inclusive) and x(exclusive): arr[y,…,x).



## Algorithm

#define LSB(i) ((i) & -(i)) // zeroes all the bits except the least significant one
//One based indexing is assumed
int A[SIZE+1];

int sum(int i) // Returns the sum from index 1 to i
{
    int sum = 0;
    while (i > 0)
        sum += A[i], i -= LSB(i);
    return sum;
}

void add(int i, int k) // Adds k to element with index i
{
    while (i <= SIZE)
        A[i] += k, i += LSB(i);
}

## Example

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8

## See also

* [Wikipedia : Fenwick Tree](https://en.wikipedia.org/wiki/Fenwick_tree)
* [Hackerearth : Fenwick Tree](https://www.hackerearth.com/practice/notes/binary-indexed-tree-or-fenwick-tree/)
