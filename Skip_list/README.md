# SKIP LIST

A **skip list** is a data structure that is used for storing a sorted list of items with a help of hierarchy of linked lists that connect increasingly sparse subsequences of the items. A skip list allows the process of item look up in efficient manner. The skip list data structure skips over many of the items of the full list in one step, that’s why it is known as skip list.

![Skip list](https://iq.opengenus.org/content/images/2019/03/skip-list.png)

In short, skip lists are a linked list like structure which allows for fast search. It consists of a base list holding the elements, together with a tower of lists maintaining a linked hierarchy of subsequences, each skipping over fewer elements.

## Description

A skip list is built in layers:

- The bottom layer is an ordinary ordered linked list.
- Each higher layer acts as an "express lane" for the lists below, where an element in layer i appears in layer i+1 with some fixed probability p (two commonly-used values for p are 1/2 or 1/4).
On average, each element appears in **1/(1-p) lists**, and the tallest element (usually a special head element at the front of the skip list) appears **log1/pn** in lists.

A search for a target element begins at the head element in the top list, and proceeds horizontally until the current element is greater than or equal to the target.

If the current element is equal to the target, it has been found.

If the current element is greater than the target, the procedure is repeated after returning to the previous element and log1/pn/p which is 0(logn) where p is a constant. By choosing different values of p, it is possible to trade search costs against storage costs.

![Skip list](https://iq.opengenus.org/content/images/2019/03/SkipList1.png)

## Basic Operations
Following are the Operations Performed on Skip list:-

- Insertion Operation : To Insert any element in a list
- Search Operation : To Search any element in a list
- Deletion Operation : To Delete any element from a list

## Insertion Operation
Before we start inserting the elements in the skip list we need to decide the nodes level.Each element in the list is represented by a node, the level of the node is chosen randomly while insertion in the list. Level does not depend on the number of elements in the node. 

The level for node is decided by the following algorithm –
```sh
randomLevel()
lvl := 1
//random() that returns a random value in [0...1)
while random() < p and lvl < MaxLevel do
lvl := lvl + 1
return lvl
```
MaxLevel is the upper bound on number of levels in the skip list. It can be determined as – L(N) = logp/2(N). Above algorithm assure that random level will never be greater than MaxLevel. Here p is the fraction of the nodes with level i pointers also having level i+1 pointers and N is the number of nodes in the list.

![Skip list](https://iq.opengenus.org/content/images/2019/03/Node-skip--1.jpg)

We will start from highest level in the list and compare key of next node of the current node with the key to be inserted. Basic idea is:

- Key of next node is less than key to be inserted then we keep on moving forward on the same level
- Key of next node is greater than the key to be inserted then we store the pointer to current node i at update[i] and move one level down and continue our search.

## Searching Operation
Searching an element is very similar to approach for searching a spot for inserting an element in Skip list. 
The basic idea is if –
- Key of next node is less than search key then we keep on moving forward on the same level.
- Key of next node is greater than the key to be inserted then we store the pointer to current node i at update[i] and move one level down and continue our search.

- At the lowest level (0), if the element next to the rightmost element (update[0]) has key equal to the search key, then we have found key otherwise failure.

Seaching operation algorithm:
```sh
Search(list, searchKey)
        x := list -> header
        -- loop invariant: x -> key  level downto 0 do
             while x -> forward[i] -> key  forward[i]
        x := x -> forward[0]
       if x -> key = searchKey then return x -> value
       else return failure
```

## Deletion Operation
Deletion of an element k is preceded by locating element in the Skip list using above mentioned search algorithm. Once the element is located, rearrangement of pointers is done to remove element from list just like we do in singly linked list. We start from lowest level and do rearrangement until element next to update[i] is not k.After deletion of element there could be levels with no elements, so we will remove these levels as well by decrementing the level of Skip list.

Deletion operation algorithm:
```sh
Delete(list, searchKey)
local update[0..MaxLevel+1]
x := list -> header
for i := list -> level downto 0 do
   while x -> forward[i] -> key  forward[i]
      update[i] := x
x := x -> forward[0]
if x -> key = searchKey then
   for i := 0 to list -> level do
        if update[i] -> forward[i] ≠ x then break
        update[i] -> forward[i] := x -> forward[i]
   free(x)
   while list -> level > 0 and list -> header -> forward[list -> level] = NIL do
       list -> level := list -> level – 1
```

## Complexity

**Time Complexity:-**

| OPERATIONS | AVERAGE CASE | WORST CASE |
| ---------- | ------------ | ---------- |
| Search     | O(logn)	    | O(n)       |
| Insertion  | O(logn)	    | O(n)       |
| Deletion	 | O(logn)	    | O(n)       |

**Space Complexity : O(N log N)**

A skip list is built in layers. The bottom layer is an ordinary ordered linked list. Each higher layer acts as an "express lane" for the lists below, where an element in layer i appears in layer i+1 with some fixed probability p (two commonly used values for p are 1/2 or 1/4). On average, each element appears in 1/(1-p) lists, and the tallest element (usually a special head element at the front of the skip list) in all the lists. The skip list contains log1/pn lists.

## Applications 
List of applications and frameworks that use skip lists:

- Skip list are used in distributed applications. In distributed systems, the nodes of skip list represents the computer systems and pointers represent network connection.
- Skip list are used for implementing highly scalable concurrent priority queues with less lock contention (struggle for having a lock on a data item).
- QMap template class of Qt that provides a dictionary.