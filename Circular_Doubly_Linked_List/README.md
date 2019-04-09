# Circular Doubly Linked List

A **Circular Doubly Linked List** is a linked data structure that consists of a set of sequentially linked records called nodes. Each node is connected to the next node and previous node via two link fields which refences the next node in sequence and previous node in sequence. Each node consists of a data/key.

This data structure is so called as it combines the features of both a circular linked list and a doubly linked list. As per doubly linked list characteristics - it consists of the previous node pointer that points to the previous node in the sequence. And similar to a circular linked list - the last node in the list points to the first node by next pointer and the first node points to the last node by the previous pointer.

Node traversal from any direction is possible and also jumping from head to last node or from last node to head is only one operation: head pointer previous is last node and the last node next pointer is head.

Hence in a **Circular Doubly Linked List** all nodes are connected to form a circle. There is no NULL at the end. 

The head or starter pointer points to the beginning of the Circular Doubly Linked List.

An example of a Circular Doubly Linked List:

![Circular Doubly Linked List](http://cdncontribute.geeksforgeeks.org/wp-content/uploads/Circular-doubly-linked-list.png)
[Courtesy: geeksforgeeks.org](https://www.geeksforgeeks.org/doubly-circular-linked-list-set-1-introduction-and-insertion/)

## Insert in a Circular Doubly Linked List

### 1. Prepend - Add node to the beginning of the list

In a prepend operation - a node is added to the beginning of the Circular Doubly Linked List. The newly added node becomes the head of the Circular Doubly Linked List. If the list is not an empty list - the appropriate next and previous pointers for the head, last node and the newly inserted node are updated. In an empty list - next, previous and head all point to the new node. The last node in the list is easily obtained using the previous pointer of the head or starter pointer.

##### 1a. Circular Doubly Linked List Prepend operation - on an empty list

![Prepend-1](http://cdncontribute.geeksforgeeks.org/wp-content/uploads/Insertion-in-empty-list1.png)

##### 1b. Circular Doubly Linked List Prepend operation - on an existing list

![Prepend-2](http://cdncontribute.geeksforgeeks.org/wp-content/uploads/Insertion-at-beginning-of-list.png)

### 2. Append - Add node to the end of the list

In an append operation - a node is added to the end of the Circular Doubly Linked List. This new node after insertion points to the beginning of the Circular Doubly Linked List or the head. If the list is not an empty list - the appropriate next and previous pointers for the head, last node and the newly inserted node are updated. In an empty list - next, previous and head all point to the new node. The last node in the list is easily obtained using the previous pointer of the head or starter pointer.

##### 2a. Circular Doubly Linked List Append operation - on an empty list

![Append-1](http://cdncontribute.geeksforgeeks.org/wp-content/uploads/Insertion-in-empty-list1.png)

##### 2b. Circular Doubly Linked List Append operation - on an existing list

![Append-2](http://cdncontribute.geeksforgeeks.org/wp-content/uploads/Insertion-in-a-list.png)


### 3. Insert In between Nodes ( After a given Node or Before a given Node)

If the Circular Doubly Linked List is empty - a node can be added via an **append** or **prepend** operation to create a new Circular Doubly Linked List with a single item.

If the node after which the new key is to be inserted is the last node then an **append** operation is performed. If the node before which the new key is to be inserted is the first node then a **prepend** operation is performed.

Otherwise we the traverse the list and the new node is added after (or before) the given node. The previous and next pointers are updated appropriately. 

##### Circular Doubly Linked List Insert - New node between nodes 
![Insert node 4](http://cdncontribute.geeksforgeeks.org/wp-content/uploads/Insertion-in-between-the-list.png)

[Courtesy: geeksforgeeks.org](https://www.geeksforgeeks.org/doubly-circular-linked-list-set-1-introduction-and-insertion/)

## Delete in a Circular Doubly Linked List

### Case 1. Delete head in a single element Circular Doubly Linked List

##### Deletes the only element and no Circular Doubly Linked List remains.
The current node is set to NULL / None and no Circular Doubly Linked List remains.

### Case 2. Delete head in a Circular Doubly Linked List with more than one element

##### List with more than one element and then deleting head
![Delete Case 2](https://media.geeksforgeeks.org/wp-content/uploads/Delete_first_node.png)

### Case 3. Delete a middle node

##### List with more than one element and then deleting a middle node
![Delete Case 3](https://media.geeksforgeeks.org/wp-content/uploads/Delete_middle_node.png)

### Case 4. Delete the last node 

##### Delete the last node in a Circular Doubly Linked List
![Delete Case 4](https://media.geeksforgeeks.org/wp-content/uploads/Delete_last_node.png)

[Courtesy: geeksforgeeks.org](https://www.geeksforgeeks.org/doubly-circular-linked-list-set-2-deletion/)

## See also

- [GeeksForGeeks: Circular Doubly Linked List Introduction and Insertion](https://www.geeksforgeeks.org/doubly-circular-linked-list-set-1-introduction-and-insertion/)
- [GeeksForGeeks: Circular Doubly Linked List Deletion ](https://www.geeksforgeeks.org/doubly-circular-linked-list-set-2-deletion/)
- [ Visualization of Circular Doubly Linked List ](https://www.codelike.in/animation/circular-doubly-linked-list/)
