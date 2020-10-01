# Doubly Linked List

A **Doubly Linked List** is a linked data structure that consists of a set of sequentially linked records called nodes. Each node contains three fields: two link fields (references to the previous and to the next node in the sequence of nodes) and one data/key field. The beginning and ending nodes' previous and next links, respectively, point to some kind of terminator, typically a sentinel node or null, to facilitate traversal of the list. 

The head or starter pointer points to the beginning of the doubly linked list.

An example of a doubly linked list:

![doubly linked list](https://upload.wikimedia.org/wikipedia/commons/5/5e/Doubly-linked-list.svg)
[Courtesy: Wikipedia.org](https://en.wikipedia.org/wiki/Doubly_linked_list)

## Insert in a Doubly Linked List

### 1. Prepend - Add node to the beginning of the list

In a prepend operation - a node is added to the beginning of the doubly linked list. The newly added node becomes the head of the doubly linked list.

![Prepend](https://www.geeksforgeeks.org/wp-content/uploads/gq/2014/03/DLL_add_front1.png)

### 2. Append - Add node to the end of the list

In an append operation - a node is added to the end of the doubly linked list. 

![Append](https://www.geeksforgeeks.org/wp-content/uploads/gq/2014/03/DLL_add_end1.png)

### 3. Insert After a Given Node

If the doubly linked list is empty - a node can be added via an **append** operation to create a new doubly linked list with a single item.

Otherwise we traverse the list and the new node is added after the given node.

##### Insert After - New node between nodes
![Add node](https://www.geeksforgeeks.org/wp-content/uploads/gq/2014/03/DLL_add_middle1.png)

### 4. Insert Before a Given Node

If the doubly linked list is empty - a node can be added via a **prepend** operation to create a new doubly linked list with a single item.

Otherwise we traverse the list and the new node is added before the given node.

##### Insert Before - New node between nodes

![Insert Before ](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/5-55-300x100.png)

[Courtesy: geeksforgeeks.org]
(https://www.geeksforgeeks.org/doubly-linked-list/)

## Delete in a Doubly Linked List

### Case 1. Delete head in a single element doubly linked list

##### Deletes the only element and no doubly linked list remains.

![Delete Case 1](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/Delete_lincked_list4.jpg)

### Case 2. Delete head in a doubly linked list with more than one element

##### List with more than one element
![Delete Case 2-1](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/Delete_lincked_list.jpg)

##### After deleting the head 

![Delete Case 2-2](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/Delete_lincked_list2.jpg)

### Case 3. Delete a middle node

##### Delete a middle node
![Delete Case 3-1](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/Delete_lincked_list2.jpg)

##### After deleting a middle node

![Delete Case 3-2](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/Delete_lincked_list3.jpg)

### Case 4. Delete the last node

##### Delete the last node
![Delete Case 4-1](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/Delete_lincked_list3.jpg)

##### After deleting the last node

![Delete Case 4-2](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/Delete_lincked_list4.jpg)

[Courtesy: geeksforgeeks.org]
(https://www.geeksforgeeks.org/delete-a-node-in-a-doubly-linked-list/)

## See also

- [Wikipedia : Doubly Linked List](https://en.wikipedia.org/wiki/Doubly_linked_list)
- [GeeksForGeeks : Doubly Linked List Insertion](https://www.geeksforgeeks.org/doubly-linked-list/)
- [GeeksForGeeks : Delete a node in a Doubly Linked List](https://www.geeksforgeeks.org/delete-a-node-in-a-doubly-linked-list/)
- [Visual Algorithm - DLL (Doubly Linked List)](https://visualgo.net/en/list)
