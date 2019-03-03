## Fenwick Tree
Fenwick Tree or Binary Indexed Tree is a data structure used when you have an array and you are performing some operation to find a result(operation can be finding minimum,sum etc in the given array) in a given range. It supports two O(logn) time operations on an array:
processing a range sum query and updating a value <br>
The advantage of a binary indexed tree is that it allows us to efficiently update array values between sum queries. This would not possible using a prefix sum array, because after each update, it would be necessary to build the whole prefix
sum array again in **O(n)** time. <br><br>
Let p(k) denote the largest power of two that divides k. We store a binary indexed tree as an array tree such that <br>

**tree[k] = sum(k − p(k)+1,k),**
<br><br>
i.e., each position k contains the sum of values in a range of the original array
whose length is p(k) and that ends at position k. For example, since p(6) = 2,
tree[6] contains the value of sumq(5,6).



