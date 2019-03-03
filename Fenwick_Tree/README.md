## Fenwick Tree
Fenwick Tree or Binary Indexed Tree is a data structure used when you have an array and you are performing some operation to find a result(operation can be finding minimum,sum etc in the given array) in a given range. It supports two O(logn) time operations on an array:
processing a range sum query and updating a value <br>
The advantage of a binary indexed tree is that it allows us to efficiently update array values between sum queries. This would not possible using a prefix sum array, because after each update, it would be necessary to build the whole prefix
sum array again in **O(n)** time.


