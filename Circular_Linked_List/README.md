# Circular Linked List

A **Circular Linked List** is a linked data structure that consists of a set of sequentially linked records called nodes. Each node 
is connected to the next node via a link field which refences the next node in sequence. Each node consists of a data/key.

In a **circular linked list** all nodes are connected to form a circle. There is no NULL at the end. A circular linked list can be a singly circular linked list or doubly circular linked list.

The head or starter pointer points to the beginning of the circular linked list.

An example of a Circular linked list:

![Circular linked list](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/CircularLinkeList.png)
[Courtesy: geeksforgeeks.org](https://www.geeksforgeeks.org/circular-linked-list/)

## Insert in a Circular Linked List

### 1. Prepend - Add node to the beginning of the list

In a prepend operation - a node is added to the beginning of the circular linked list. The newly added node becomes the head of the Circular linked list.

##### Circular Linked List before Prepend operation

![Prepend-1](https://media.geeksforgeeks.org/wp-content/uploads/CircularSinglyLinkedlist-4.png)

##### Circular Linked List after Prepend operation

![Prepend-2](https://media.geeksforgeeks.org/wp-content/uploads/CircularSinglLinkedList5.png)

### 2. Append - Add node to the end of the list

In an append operation - a node is added to the end of the circular linked list. This new node after insertion points to the beginning of the circular linked list or the head.

##### Circular Linked List before Append operation

![Append-1](https://media.geeksforgeeks.org/wp-content/uploads/CircularSinglyLinkedlist-6.png)

##### Circular Linked List after Append operation

![Append-2](https://media.geeksforgeeks.org/wp-content/uploads/CircularSinglyLinkedlist-7.png)

### 3. Insert After a Given Node or In between Nodes

If the circular linked list is empty - a node can be added via an **append** operation to create a new circular linked list with a single item.

Otherwise we traverse the list and the new node is added after the given node.

##### Circular Linked List before Insert - New node between nodes 
![Insert node 1](https://media.geeksforgeeks.org/wp-content/uploads/circularll-1.png)

##### Circular Linked List after Insert - New node between nodes 
![Insert node 2](https://media.geeksforgeeks.org/wp-content/uploads/CircularSinglyLinkedList9.png)

[Courtesy: geeksforgeeks.org](https://www.geeksforgeeks.org/circular-singly-linked-list-insertion/)

## Delete in a Circular Linked List

### Case 1. Delete head in a single element circular linked list

##### Deletes the only element and no circular linked list remains.

###### Circular linked list before deletion of head
![Delete Case 1](https://media.geeksforgeeks.org/wp-content/uploads/CircularSinglyLinkedList3.png)

###### Circular linked list after deletion of the only node in the list
![Delete Case 2](https://media.geeksforgeeks.org/wp-content/uploads/CircularSinglyLinkedList2.png)

### Case 2. Delete head in a circular linked list with more than one element

##### List with more than one element and then deleting head
![Delete Case 2-1](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/CircularDeleteFirstNode.png)

### Case 3. Delete a middle node

##### List with more than one element and then deleting a middle node
![Delete Case 3-1](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/DeleteAtIndexCLL.png)

### Case 4. Delete the last node 

##### Delete the last node in a circular linked list
![Delete Case 4-1](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/CircularDeleteLastNode.png)

[Courtesy: geeksforgeeks.org](https://www.geeksforgeeks.org/delete-a-node-in-a-Circular-linked-list/)

## See also

- [Wikipedia : Circular Linked List](https://en.wikipedia.org/wiki/Linked_list#Circular_linked_list)
- [GeeksForGeeks : Circular Linked List Introduction](https://www.geeksforgeeks.org/circular-linked-list/)
- [GeeksForGeeks : Circular Linked List Insertion](https://www.geeksforgeeks.org/circular-singly-linked-list-insertion/)
- [GeeksForGeeks : Circular Linked List Deletion ](https://www.geeksforgeeks.org/deletion-at-different-positions-in-a-circular-linked-list/)
