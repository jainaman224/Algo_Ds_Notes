class node:
    def __init__(self, key, next=None, prev=None):
        self.key = key
        self.next = next
        self.prev = prev

    def __str__(self):
        return str(self.key)

    def __repr__(self):
        return str(self.key)


class doubly_linked_list:
    def __init__(self, head=None):
        self.head = head

    def pretty_print(self):

        dbl_list_str = ''

        current_node = self.head

        while current_node:
            dbl_list_str += '-({0:1d})-'.format(current_node.key)
            current_node = current_node.next

        return dbl_list_str

    # Insert node at the end of the doubly linked list
    def append(self, key):
        new_node = node(key)
        # If there are no elements in the doubly linked list
        if self.head is None:
            self.head = new_node
        else:
            current_node = self.head
            # Traverse the doubly linked list to find last node
            while current_node.next:
                current_node = current_node.next

            new_node.prev = current_node
            current_node.next = new_node

    # Insert node at the beginning of the doubly linked list

    def prepend(self, key):
        new_node = node(key)
        # If there are no elements in the doubly linked list
        if self.head is None:
            self.head = new_node
        else:
            # Add node at the beginning of the doubly linked list
            self.head.prev = new_node
            new_node.next = self.head
            self.head = new_node

    # Insert after a specific node in the doubly linked list
    def insert_after_node(self, afterkey, key):
        current_node = self.head
        while current_node:
            if current_node.next is None and current_node.key == afterkey:
                # New node is to be appended to the list
                self.append(key)
                return
            elif current_node.key == afterkey:
                new_node = node(key)
                next_node = current_node.next

                # Update next pointers
                current_node.next = new_node
                new_node.next = next_node

                # Update prev pointers
                new_node.prev = current_node
                next_node.prev = new_node
                return

            current_node = current_node.next

    # Insert before a specific node in the doubly linked list

    def insert_before_node(self, beforekey, key):
        current_node = self.head
        while current_node:
            if current_node.prev is None and current_node.key == beforekey:
                # New node is to be prepended to the list
                self.prepend(key)
                return
            elif current_node.key == beforekey:
                new_node = node(key)
                prev_node = current_node.prev

                # Update next pointers
                prev_node.next = new_node
                new_node.next = current_node

                # Update prev pointers
                new_node.prev = prev_node
                current_node.prev = new_node

                return

            current_node = current_node.next

    # Delete specific key node from the doubly linked list
    def delete(self, deletekey):
        current_node = self.head
        while current_node:
            # The node to be deleted is the head node
            if current_node.key == deletekey and current_node == self.head:
                # Case 1 - The head is the only element in doubly linked list
                if current_node.next is None:
                    current_node = None
                    self.head = None
                    return

                # Case 2 - There are more elements in the doubly linked list
                else:
                    next_node = current_node.next

                    current_node.next = None
                    current_node = None

                    next_node.prev = None
                    self.head = next_node
                    return
            # Node to be deleted in between nodes or last node
            elif current_node.key == deletekey:

                # Case 3 : Node to be deleted is not last node
                if current_node.next:

                    next_node = current_node.next
                    prev_node = current_node.prev

                    prev_node.next = next_node
                    next_node.prev = prev_node

                    current_node = None
                    return
                # Case 4 : Node to be deleted is the last node
                else:
                    prev_node = current_node.prev
                    prev_node.next = None

                    current_node = None
                    return

            current_node = current_node.next


if __name__ == "__main__":

    # Create doubly linked list
    dbl_list = doubly_linked_list()

    data = [55, 5, 82, 61]

    for value in data:
        dbl_list.append(value)

    # Expected -(55)--(5)--(82)--(61)-
    print('\nDoubly linked list elements using append --->',
          dbl_list.pretty_print())

    # Add to the beginning of the doubly linked list
    dbl_list.prepend(85)

    # Expected -(85)--(55)--(5)--(82)--(61)-
    print('\nPrepended 85  ---> ', dbl_list.pretty_print())

    dbl_list1 = doubly_linked_list()

    # Prepend when the list is empty
    dbl_list1.prepend(0)

    # Expected -(0)
    print('\nPrepend on empty list  ---> ', dbl_list1.pretty_print())

    print('\n----- Insert After Operations ----- ')

    # Add after node 5 - key 19 - In between nodes
    # Expected -(85)--(55)--(5)--(19)--(82)--(61)-
    dbl_list.insert_after_node(5, 19)
    print('\nInsert after node 5 - key 19 ---> ', dbl_list.pretty_print())

    # Add after node 85 - key 1 - After the beginning of list
    # Expected -(85)--(1)--(55)--(5)--(19)--(82)--(61)-
    dbl_list.insert_after_node(85, 1)
    print('\nInsert after 85 - key 1 ---> ', dbl_list.pretty_print())

    # Add after node 61 - key 44 -  Append Operation - At end of list
    # Expected -(85)--(1)--(55)--(5)--(19)--(82)--(61)--(44)-
    dbl_list.insert_after_node(61, 44)
    print('\nInsert after 61 - key 44  --->', dbl_list.pretty_print())

    print('\n----- Insert Before Operations ----- ')
    # Add before node 82 - key 22 -  In between nodes
    # Expected -(85)--(1)--(55)--(5)--(19)--(22)--(82)--(61)--(44)-
    dbl_list.insert_before_node(82, 22)
    print('\nInsert before 82 - key 22  --->', dbl_list.pretty_print())

    # Add before node 44 - key 33 -  Before the last node
    # Expected -(85)--(1)--(55)--(5)--(19)--(22)--(82)--(61)--(33)--(44)-
    dbl_list.insert_before_node(44, 33)
    print('\nInsert before 44 - key 33  --->', dbl_list.pretty_print())

    # Add before node 85 - key 66 -  At head of list - Prepend Operation
    # Expected -(66)--(85)--(1)--(55)--(5)--(19)--(22)--(82)--(61)--(33)--(44)-
    dbl_list.insert_before_node(85, 66)
    print('\nInsert before 85 - key 66  --->', dbl_list.pretty_print())

    print('\n----- Delete Operations ----- ')

    # Single element doubly linked list
    dbl_del_list = doubly_linked_list()
    dbl_del_list.append(11)
    print('\nSingle node doubly linked list -->', dbl_del_list.pretty_print())

    # Case 1 -
    # Delete the only element in the doubly linked list which is also the head
    # Expected - (Nothing will be printed since the list is empty)
    dbl_del_list.delete(11)
    print('\nAfter deleting the only element (also the head)  -->',
          dbl_del_list.pretty_print())

    # Case 2 - Delete the head in a doubly linked list with more than 1 element
    # Expected -(85)--(1)--(55)--(5)--(19)--(22)--(82)--(61)--(33)--(44)-
    dbl_list.delete(66)
    print('\nAfter deleting the head  -->', dbl_list.pretty_print())

    # Case 3 - Delete a node in between other nodes in the doubly linked list
    # Expected -(85)--(1)--(55)--(5)--(19)--(22)--(61)--(33)--(44)-
    dbl_list.delete(82)
    print('\nAfter deleting a node in between nodes  -->', dbl_list.pretty_print())

    # Case 4 - Delete the last node in a doubly linked list
    # Expected -(85)--(1)--(55)--(5)--(19)--(22)--(61)--(33)-
    dbl_list.delete(44)
    print('\nAfter deleting the last node  -->', dbl_list.pretty_print())

    # Try to delete a non-existing key from the doubly linked list -
    # Expected -(85)--(1)--(55)--(5)--(19)--(22)--(61)--(33)- No change in list
    dbl_list.delete(99)
    print('\nNo change after trying to delete a non existing key -->',
          dbl_list.pretty_print())
