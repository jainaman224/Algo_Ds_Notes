# Treap

A **Treap** is a binary search tree with a modified way of ordering the nodes. Each node x in the tree has a **key value x:key**. In addition, we assign **x:priority**, which is a random number chosen independently for each node. We assume that all priorities are distinct and also that all keys are distinct. The nodes of the treap are ordered so that the keys obey the binary-search tree property and the priorities obey the heap order property.

This combination of properties is why the tree is called a **“treap”**: it has features of both a binary search tree and a heap.

The cost of all the operations — search, insert, delete, — is proportional to the depth of the node in the treap and approximately is in the order of `O(log n)` time.

An example of a treap:

                         G:4                   
                       /    \                 
                    B:7      H:5            
                   /  \         \     
                A:10   E:23    K:65
                                /
                              I:73   

(Courtesy: Cormen)

## Properties of Treap

Since basically a treap is a binary tree - it follows the basic properties of a binary tree.

1. If v is a left child of u, then v:key < u:key.
2. If v is a right child of u, then v:key > u:key.
3. Additionally it will obey the priorities of either min or max heap properties

##### If the heap order is to maintain a **min heap**, then:

* The priority value of the root is lesser than the priority value of its children.
* i.e. If v is a child of u, then v:priority > u:priority.

##### If the heap order is to maintain a **max heap**, then:

* The priority value of the root is greater than the priority value of its children.
* i.e. If v is a child of u, then v:priority < u:priority.

## Right Rotation and Left Rotation

A rotation is a local operation in a tree that preserves in-order traversal key ordering along with min/max heap priorities.

### Right Rotate <----> Left Rotate 

>
>                            Right Rotate  ----->
>
>                         y                      x
>                        /  \                   /  \
>                      x     C                 A     y
>                     /  \           <--->          /  \
>                    A    B                        B    C
>                        
>                             <--------- Left Rotate

(Courtesy: Cormen)
## Insertion into Treap 
To insert into a treap - first, a regular binary tree insert is performed. After this a rebalance of the treap using rotations is done to preserve the min / max heap priorities if the heap order priority is violated. 

> Treap Insertion - Insert key = 4, priority = 9 (min heap)
>
>                   Basic binary insert -------->                        
>
>                   7:4                           7:4
>                  /   \                        /     \
>                2:7    8:5                 2:7       8:5
>               /  \       \               /  \          \
>             1:10  5:23    11:65        1:10  5:23       11:65
>                   /       /                   /           /
>                3:25      9:73              3:25        9:73
>                                              \
>                                               4:9
>
>                   Left rotate at node 4 , 9 -------->                        
>
>                  7:4                        7:4
>                /     \                     /   \
>             2:7       8:5               2:7    8:5
>            /  \         \              /   \      \
>         1:10  5:23       11:65      1:10  5:23    11:65
>                /           /                /       /
>               3:25      9:73              4:9     9:73
>                 \                         /
>                  4:9                    3:25
>
>                   Right rotate at node 4 , 9 -->  Final Treap                      
>
>                 7:4                         7:4
>                /   \                      /     \
>             2:7    8:5                 2:7      8:5     
>            /   \      \               /   \        \
>         1:10  5:23    11:65         1:10  4:9     11:65
>                /       /                 /   \        /
>               4:9     9:73            3:25  5:23    9:73
>               /
>             3:25


## Deletion in Treap
In treap only leaf nodes are deleted. If the node to be deleted is already a leaf node, it is simply deleted from the treap after setting its parent's appropriate child pointer to an empty value.

If the node to be deleted is not a leaf node, it will be rotated down the treap until it becomes a leaf node and then deleted.

> Treap Delete - Delete key = 9, priority = 17 (min heap)
>
>                    Rotate right at node 9, 17 -------->                 
>
>                   3:1                           3:1
>                  /   \                        /     \
>               1:6     5:11                 1:6      5:11
>              /  \     /    \               /  \    /    \
>           0:9  2:99  4:14   9:17       0:9  2:99  4:14   7:22
>                              /                           /   \
>                           7:22                        6:42   9:17
>                           /  \                                /
>                        6:42  8:49                          8:49
>
>                    Rotate right at node 9, 17 -------->                 
>
>                   3:1                            3:1
>                  /   \                         /     \
>               1:6     5:11                  1:6      5:11
>              /  \     /    \                /  \    /    \
>           0:9  2:99  4:14   7:22         0:9  2:99  4:14   7:22
>                              /  \                         /   \
>                           6:42   9:17                  6:42   8:49
>                                 /                               \
>                               8:49                              9:17
>
>                Delete leaf node 9, 17 -------->  Final Treap               
>
>                   3:1                              3:1     
>                  /   \                           /    \
>               1:6     5:11                    1:6      5:11
>              /  \     /    \                 /  \      /   \
>           0:9  2:99  4:14   7:22           0:9  2:99  4:14  7:22
>                              /  \                           /  \  
>                           6:42   8:49                    6:42  8:49
>                                   \
>                                   9:17

## See also

- [Wikipedia Treap](https://en.wikipedia.org/wiki/Treap)
- [Treap on GeeksForGeeks](https://www.geeksforgeeks.org/treap-a-randomized-binary-search-tree/)
